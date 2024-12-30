#include <iostream>
using namespace std;

void div(int data[], int dataLen, int divisor[], int divilen){
    int temp[dataLen];
    
    
    for (int i = 0; i < dataLen; i++){
        temp[i] = data[i];
    }


    for (int i = 0; i < dataLen - divilen + 1; i++){
        if (temp[i] == 1) {
            for (int j = 0; j < divilen; j++){
                temp[i + j] = temp[i + j] ^ divisor[j]; 
            }
        }
    }

   
    cout << "Remainder: ";
    for (int i = dataLen - divilen + 1; i < dataLen; i++){
        cout << temp[i];
    }
    cout << endl;
}

int main(){
    int data[] = {1,1,0,1,0,1};
    int dataLen=6;
    int divisor[] = {1, 0, 1,1};
    int divilen = 4;
    
    int totalLen = dataLen + divilen - 1;
    int paddedData[totalLen];

    for (int i = 0; i < dataLen; i++){
        paddedData[i] = data[i];
    }
    for (int i = dataLen; i < totalLen; i++){
        paddedData[i] = 0;
    }

    div(paddedData, totalLen, divisor, divilen);
}
