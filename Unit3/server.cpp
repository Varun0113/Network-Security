#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
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
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer << endl;
    
    // sending data
    const char* response = "Hello, client!";
    send(clientSocket, response, strlen(response), 0);
    
    // closing the socket.
    close(serverSocket);
    return 0;
}


#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind and listen
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);

    cout << "Server is waiting for a connection..." << endl;

    // Accept connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    cout << "Client connected!" << endl;

    // Open the file to send (example: "testfile.txt")
    ifstream file("testfile.txt", ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        close(clientSocket);
        close(serverSocket);
        return -1;
    }

    // Read the file in chunks and send it
    char buffer[1024];
    while (!file.eof()) {
        file.read(buffer, sizeof(buffer));
        int bytesRead = file.gcount();
        send(clientSocket, buffer, bytesRead, 0); // Send the data chunk
    }

    // Close file and sockets
    file.close();
    close(clientSocket);
    close(serverSocket);
    cout << "File sent and connection closed." << endl;

    return 0;
}