#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    // sending connection request
    connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress));
    
    // sending data
    int num[2];
    cout<< "Enter First Number: ";
    cin>> num[0];
    cout<< "Enter Second Number: ";
    cin>> num[1];
    send(clientSocket, num, sizeof(num), 0);
    
    // Read Response
    int res;
    read(clientSocket, &res, sizeof(res));
    cout << "Message from server: " << res << endl;
    
    // closing socket
    close(clientSocket);
    return 0;
}