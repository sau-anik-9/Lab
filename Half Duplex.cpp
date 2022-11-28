Server:
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netdb.h"
#include "arpa/inet.h"
#define MAX 1000
#define BACKLOG 5
int main()
{
char serverMessage[MAX];
char clientMessage[MAX];
int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_inserverAddress;
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(5214);
serverAddress.sin_addr.s_addr = INADDR_ANY;
bind(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
listen(socketDescriptor, BACKLOG);
int clientSocketDescriptor = accept(socketDescriptor, NULL, NULL);
while (1)
{
printf("\ntext message here .. :");
scanf("%s", serverMessage);
send(clientSocketDescriptor, serverMessage, sizeof(serverMessage) , 0);
recv(clientSocketDescriptor, &clientMessage, sizeof(clientMessage), 0) ;
printf("\nCLIENT: %s", clientMessage);
}
close(socketDescriptor);
return 0;
}

Client:
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/types.h>
#include <sys/socket.h>
include <netinet/in.h>
#include <unistd.h>
#include "netdb.h"
#include "arpa/inet.h"
#define h_addrh_addr_list[0]
#define PORT 5214
#define MAX 1000
int main(){
char clientResponse[MAX];
int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
char hostname[MAX], ipaddress[MAX];
struct hostent *hostIP;
f(gethostname(hostname,sizeof(hostname))==0){
hostIP = gethostbyname(hostname);
}
else{
printf("ERROR:FCC4539 IP Address Not ");
}
struct sockaddr_inserverAddress;
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(PORT);
serverAddress.sin_addr.s_addr = INADDR_ANY;
connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
printf("\nLocalhost: %s\n", inet_ntoa(*(struct in_addr*)hostIP->h_addr));
printf("Local Port: %d\n", PORT);
printf("Remote Host: %s\n", inet_ntoa(serverAddress.sin_addr));
while (1)
{
recv(socketDescriptor, serverResponse, sizeof(serverResponse), 0);
printf("\nSERVER : %s", serverResponse);
printf("\ntext message here... :");
scanf("%s", clientResponse);
send(socketDescriptor, clientResponse, sizeof(clientResponse), 0);
}
close(socketDescriptor);
return 0;
}


Python:

Server side Script
# Server Side Script
# Supports Python v3.*

from socket import *
server_port = 5000
server_socket = socket(AF_INET,SOCK_STREAM)
server_socket.bind(('',server_port))
server_socket.listen(1)
print ("Welcome: The server is now ready to receive")
connection_socket, address = server_socket.accept()
while True:
  sentence = connection_socket.recv(2048).decode()
  print('>> ',sentence)
  message = input(">> ")
  connection_socket.send(message.encode())
  if(message == 'q'):
    connectionSocket.close()
      
Client Side Script
# Client Side Script
# Supports Python v3.*

from socket import *
server_name = 'localhost'
server_port = 5000
client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect((server_name,server_port))

while True:
  sentence = input(">> ")
  client_socket.send(sentence.encode())
  message = client_socket.recv(2048)
  print (">> ", message.decode())
  if(sentence == 'q'):
    client_socket.close()
      
Save the server side code in a file and name it as server.py or anything as you wish. Also save the client side code in another file and name as client.py. You can run the code in windows command prompt (cmd) by opening it in the directory you stored your script file. Then type python server.pyand hit Enter. Running client.py will require another cmd window. Type there as python client.py and hit enter. You will get a message in the server side that a client is connected. Now, you can send and receive message from and to both ends.
