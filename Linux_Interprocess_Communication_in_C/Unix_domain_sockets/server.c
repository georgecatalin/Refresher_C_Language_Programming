#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>


#define SOCKET_NAME "/tmp/george_socket"
#define BUFFER_SIZE 150

int main(int argc, char **argv)
{
    struct sockaddr_un unix_domain_socket_name;

    int returned_value = 0;
    int connection_socket = 0;
    int data_socket = 0;
    int result_operation, data;

    char buffer_exchange_communication[BUFFER_SIZE];

    /* As a precaution, make sure that there is no other master socket file description existing on the same machine
       It might have happened that the previous server process using Unix Domain Sockets did not shut down properly
    */

    unlink(SOCKET_NAME);

    //create the master socket file descriptor
    connection_socket = socket(AF_UNIX,SOCK_STREAM,0);

    if (connection_socket == -1)
    {
        perror("Error when creating master file descriptor");
        exit(EXIT_FAILURE);
    }
    
    printf("Master socket file descriptor has been created.\n");

    //fill in the details of the data structure sock_addr_un created 
    
    //good practice: zero out the new structure
    memset(&unix_domain_socket_name,0,sizeof(struct sockaddr_un));

    unix_domain_socket_name.sun_family = AF_UNIX;
    strncpy(unix_domain_socket_name.sun_path,SOCKET_NAME,sizeof(unix_domain_socket_name.sun_path) - 1);

    //with the bind() system call, instruct the OS to forward all the communications towards the socket name, to this server process
    returned_value = bind(connection_socket,(const struct sockaddr *) &unix_domain_socket_name, sizeof(struct sockaddr_un) -1);

    if(returned_value == -1)
    {
        perror("Error when binding");
        exit(EXIT_FAILURE);
    }

    printf("bind() system call executed properly.\n");

    //prepare for incoming client communication.If other maximum 20 clients wish to communicate with the server, add them in a queue. drop the other supplementary more than 20
    returned_value = listen(connection_socket,20);

    if(returned_value == -1)
    {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("The server is ready to accept connections from clients .\n");

    for(;;)
    {
        printf("The server issues an accept() system call");

        data_socket = accept(connection_socket, 0, 0);

        if(data_socket == -1)
        {
            perror("Error when accept()");
            exit(EXIT_FAILURE);
        }

        printf("Server process accepted connection with data socket -> %d \n", data_socket);
        /*
            The accept() system call is a blocking system call, that means the process is only waiting for some client connection,
            it does not do anything else
        */

        //server runs infinitely until it gets the value of '0'
        result_operation = 0;

        for(;;)
        {
            //Good practice : zero out the buffer to receive the data 
            memset(buffer_exchange_communication,0,BUFFER_SIZE);

            //receive data from the client
            returned_value = read(data_socket,buffer_exchange_communication,BUFFER_SIZE);
            //after a client handler = data socket was created, the system is waiting for data in a blocked state

            if(returned_value == -1)
            {
                perror("Error when read");
                exit(EXIT_FAILURE);
            }

            //Execute server logic here
            memcpy(&data,buffer_exchange_communication,sizeof(int));
            //server receives integers. copy the integer received in the data variable

            if(data == 0)
            {
                break;
            }
            else
            {
                result_operation += data;
            }

        }

        //send the result back to the client
        
        //Good practice: zero out the buffer(clean it from garbage)
        memset(buffer_exchange_communication,0,BUFFER_SIZE);
        sprintf(buffer_exchange_communication,"the result is -> %d", result_operation);

        printf("Server is sending data to the client now.\n");
        returned_value = write(data_socket,buffer_exchange_communication,BUFFER_SIZE);

        if (returned_value == -1)
        {
            perror("Error when write");
            exit(EXIT_FAILURE);
        }
        
        close(data_socket);
          printf("Data socket was closed.\n");
    }

    close(connection_socket);
    printf("Connection socket was closed.\n");

    unlink(SOCKET_NAME);

    return 0;
}