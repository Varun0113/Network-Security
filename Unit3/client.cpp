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
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);
    
    // Read Response
    char buffer[1024] = { 0 };
    read(clientSocket, buffer, sizeof(buffer));
    cout << "Message from server: " << buffer << endl;
    
    // closing socket
    close(clientSocket);
    return 0;
}





//File Transfer
#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr); // Change IP if needed

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cerr << "Connection failed!" << endl;
        return -1;
    }
    cout << "Connected to the server." << endl;

    // Open a file to save the received data (example: "received_file.txt")
    ofstream file("received_file.txt", ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open the file to write." << endl;
        close(clientSocket);
        return -1;
    }

    // Receive the file in chunks
    char buffer[1024];
    int bytesReceived;
    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        file.write(buffer, bytesReceived);
    }

    // Close file and socket
    file.close();
    close(clientSocket);
    cout << "File received and connection closed." << endl;

    return 0;
}