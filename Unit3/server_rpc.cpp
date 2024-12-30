#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int addOperation(int a, int b){
    return a+b;
}

int main()
{
    // creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    // specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    // binding socket.
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    
    // listening to the assigned socket
    listen(serverSocket, 5);
    
    // accepting connection request
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    
    // recieving data
    int num[2];
    recv(clientSocket, num, sizeof(num), 0);
    cout << "Doing Addition of: " << num[0] << " + " << num[1] << endl;
    
    // sending data
    int response = addOperation(num[0], num[1]);
    send(clientSocket, &response, sizeof(response), 0);
    
    // closing the socket.
    close(serverSocket);
    return 0;
}