#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 6969
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, readvalue;
    struct sockaddr_in serv_addr;
    char *msg = "Leave one Client alive and the Server are never safe. (Message from Client)"; 
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nThe Client is no one.\n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed\n");
        return -1;
    }

    send(sock , msg , strlen(msg) , 0 ); 
    printf("The Client remembers! (Message from Client)\n"); 
    readvalue = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
}