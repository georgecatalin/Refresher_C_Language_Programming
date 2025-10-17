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
    int input = 0;
    char buffer_exchange_communication[BUFFER_SIZE];
    int data_socket = 0;
    int returned_value = 0;

    //Good practice: zero out the struct
    memset(&unix_domain_socket_name,0, sizeof(struct sockaddr_un));

    //fill in the unix_domain_socket_name
    unix_domain_socket_name.sun_family = AF_UNIX;
    strncpy(unix_domain_socket_name.sun_path,SOCKET_NAME,sizeof(unix_domain_socket_name.sun_path) - 1);
    //create a communication socket 
    data_socket = socket(AF_UNIX,SOCK_STREAM,0);
    printf("Client created a data socket -> %d. \n", data_socket);

    if(data_socket == -1)
    {
        perror("Error create data socket");
        exit(EXIT_FAILURE);
    }

    //send a connection request to the server which is knows as per the filled in sockaddr_un name(address)
    returned_value = connect(data_socket,(const struct sockaddr *) &unix_domain_socket_name,sizeof(struct sockaddr_un));

    if(returned_value == -1)
    {
        perror("Error when connect()");
        exit(EXIT_FAILURE);
    }

    printf("Client has established a connection with the server on the data socket '%d'\n",data_socket);

    //send the data to the server until sending a '0'
    do
    {
        printf("Enter the number to send to the server: ");
        scanf("%d", &input);

        returned_value = write(data_socket,&input,sizeof(int));

        if(returned_value == -1)
        {
            perror("Error when write");
            exit(EXIT_FAILURE);
        }
        
        printf("Client sends data to server . Number of bytes %d sent, and data sent is %d. \n", returned_value, input);

    } while (input != 0);
    
    //receive data from the server
    //zero out the communication buffer
    memset(buffer_exchange_communication, 0, BUFFER_SIZE);

    returned_value = read(data_socket, buffer_exchange_communication, BUFFER_SIZE);
    
    if (returned_value == -1)
    {
        perror("Error when read()");
        exit(EXIT_FAILURE);
    }

    printf("Client received the value -> %s .\n", buffer_exchange_communication);

    close(data_socket);
    
    return 0;

}
    

