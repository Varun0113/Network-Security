#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;
int main() {
    int totalFrames = 5;
    int frame = 1;
    while (frame <= totalFrames) {
        cout << "Sending frame " << frame << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        int ack = rand() % 2;
        if (ack == 1) {
            cout << "ACK received for frame " << frame << endl;
            frame++;
        } else {
            cout << "Frame " << frame << " lost, resending..." << endl;
        }
        cout << "------------------" << endl;
    }
    cout << "All frames sent successfully!" << endl;
    return 0;
}
