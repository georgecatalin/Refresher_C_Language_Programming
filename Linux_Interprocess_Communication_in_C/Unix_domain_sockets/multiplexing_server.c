#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>
#include <sys/select.h>

#define SOCKET_NAME "/tmp/george_socket"
#define BUFFER_SIZE 150

#define MAX_NUMBER_CLIENTS_SUPPORTED 32 // monitoring potentially 31 clients as 1 file descriptor is reserved for the server master socket file descriptor

int monitored_file_descriptors[MAX_NUMBER_CLIENTS_SUPPORTED];

// initialize the array for computed results for each potential client connected (31), for simplicity sake i put 32(MAX_NUMBER_CLIENTS_SUPPORTED)
int computed_result[MAX_NUMBER_CLIENTS_SUPPORTED] = {0};

// write a collection of functions to deal with the collection of monitored file descriptors
static void initialize_monitored_collection()
{
    int i;
    for (i = 0; i < MAX_NUMBER_CLIENTS_SUPPORTED; i++)
    {
        monitored_file_descriptors[i] = -1;
    }
}

static void add_to_monitored_collection(int socket_file_descriptor)
{
    int i;
    for (i = 0; i < MAX_NUMBER_CLIENTS_SUPPORTED; i++)
    {
        if (monitored_file_descriptors[i] != -1)
        {
            continue;
        }
        else
        {
            monitored_file_descriptors[i] = socket_file_descriptor;
            break;
        }
    }
}

static void remove_from_monitored_collection(int socket_file_descriptor)
{
    int i;
    for (i = 0; i < MAX_NUMBER_CLIENTS_SUPPORTED; i++)
    {
        if (monitored_file_descriptors[i] != socket_file_descriptor)
        {
            continue;
        }
        else
        {
            monitored_file_descriptors[i] = -1;
            break;
        }
    }
}
static void refresh_fd_set(fd_set *fd_set_pointers)
{
    FD_ZERO(fd_set_pointers);
    int i;
    for (i = 0; i < MAX_NUMBER_CLIENTS_SUPPORTED; i++)
    {
        if (monitored_file_descriptors[i] != -1)
        {
            FD_SET(monitored_file_descriptors[i], fd_set_pointers);
        }
    }
}

static int get_maximum_file_descriptor()
{
    int i;
    int max = -1;
    for (i = 0; i < MAX_NUMBER_CLIENTS_SUPPORTED; i++)
    {
        if (monitored_file_descriptors[i] > max)
        {
            max = monitored_file_descriptors[i];
        }
    }

    return max;
}

int main(void)
{
    struct sockaddr_un my_address;

    int returned_value;
    int master_socket_file_descriptor, data_socket;
    int result;
    int data;
    char communication_buffer[BUFFER_SIZE];
    fd_set readfds;

    int comm_socket_fd, i;

    // initialize the array of monitored file descriptors(sockets) to -1 cause they have positive values when initialized
    initialize_monitored_collection();

    unlink(SOCKET_NAME); // In case the application did not shut down gracefully, release the socket

    master_socket_file_descriptor = socket(AF_UNIX, SOCK_STREAM, 0); // SOCK_DGRAM for UDP

    if (master_socket_file_descriptor == -1)
    {
        perror("Error when creating master file descriptor");
        exit(EXIT_FAILURE);
    }

    printf("Master socket file descriptor created . \n");

    // good practice: zero out the struct
    memset(&my_address, 0, sizeof(struct sockaddr_un));

    // specify the socket credentials
    my_address.sun_family = AF_UNIX;
    strncpy(my_address.sun_path, SOCKET_NAME, sizeof(my_address.sun_path) - 1);

    // bind socket to socket name
    returned_value = bind(master_socket_file_descriptor, (const struct sockaddr *)&my_address, sizeof(struct sockaddr_un));

    if (returned_value == -1)
    {
        perror("Error when binding");
        exit(EXIT_FAILURE);
    }

    printf("bind() call succeed.");

    returned_value = listen(master_socket_file_descriptor, MAX_NUMBER_CLIENTS_SUPPORTED);

    if (returned_value == -1)
    {
        perror("Error listen");
        exit(EXIT_FAILURE);
    }

    printf("The server is listening for incoming connections from up to %d clients. \n", MAX_NUMBER_CLIENTS_SUPPORTED);

    /* Add master socket file descriptor to the collection of file descriptors */
    add_to_monitored_collection(master_socket_file_descriptor);

    for (;;)
    {
        refresh_fd_set(&readfds); // clone the array of file descriptors to fd_set data structure
        printf("Waiting on select() system call \n");

        select(get_maximum_file_descriptor() + 1, &readfds, NULL, NULL, NULL); // This is a blocking statement

        if (FD_ISSET(master_socket_file_descriptor, &readfds)) // if the master socket file descriptor is activated
        {
            printf("New incoming connection initiation request coming.\n");
            data_socket = accept(master_socket_file_descriptor, NULL, NULL);

            if (data_socket == -1)
            {
                perror("Error when accepting connection initiation request \n");
                exit(EXIT_FAILURE);
            }

            printf("Connection accepted towards client %d.\n", data_socket);

            add_to_monitored_collection(data_socket);
        }
        else // in this case data comes from other client file descriptor
        {
            // find which client has sent the data request
            comm_socket_fd = -1;
            for (i = 0; i < MAX_NUMBER_CLIENTS_SUPPORTED; i++)
            {
                if (FD_ISSET(monitored_file_descriptors[i], &readfds)) // check if the element is activated
                {
                    comm_socket_fd = monitored_file_descriptors[i]; // data request comes from  comm_socket_fd = monitored_file_descriptors[i]

                    // prepare the buffer to read data
                    memset(communication_buffer, 0, BUFFER_SIZE);

                    // reading data
                    printf("Waiting for data from the client...\n");
                    returned_value = read(comm_socket_fd, communication_buffer, BUFFER_SIZE);

                    if (returned_value == -1)
                    {
                        perror("Error reading data");
                        exit(EXIT_FAILURE);
                    }

                    // Add received command
                    memcpy(&data, communication_buffer, sizeof(int));
                    if (data == 0)
                    {
                        // send data back to client
                        // zero out communication buffer
                        memset(communication_buffer, 0, BUFFER_SIZE);
                        sprintf(communication_buffer, "Result is %d\n", computed_result[i]);

                        printf("Sending back the result to the client identified by %d\n", comm_socket_fd);
                        returned_value = write(comm_socket_fd, communication_buffer, BUFFER_SIZE);

                        if (returned_value == -1)
                        {
                            perror("Error when writing");
                            exit(EXIT_FAILURE);
                        }

                        // Close socket
                        close(comm_socket_fd);
                        computed_result[i] = 0;
                        remove_from_monitored_collection(comm_socket_fd);
                        continue;
                    }
                    else
                    {
                        computed_result[i] += data;
                    }
                } // End of if (FD_ISSET(monitored_file_descriptors[i],&readfds))
            } // End of for(i = 0; i< MAX_NUMBER_CLIENTS_SUPPORTED; i++)
        } // End of else (data comes from other client file descriptor)

    } // End of infinite for loop

    // close the master socket file descriptor
    close(master_socket_file_descriptor);
    remove_from_monitored_collection(master_socket_file_descriptor);
    printf("Connection closed ...\n");

    // release the used resources . unlink the socket
    unlink(SOCKET_NAME);
    return 0;
}
