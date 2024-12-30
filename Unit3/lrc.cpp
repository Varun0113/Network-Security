#include<iostream>
using namespace std;

int main() {
    string data;
    cout << "Enter Data (Only Binary/Even Length): ";
    cin >> data;
    
    int bit;
    cout << "Enter Bit: ";
    cin >> bit; 
    
    int len = data.length() / bit; 

    char dat[len][bit]; 
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < bit; j++) {
            dat[i][j] = data[i * len + j];
        }
    }
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < bit; j++) {
            cout<<dat[i][j];
        }
        cout<<endl;
    }
    
    int parity[bit];
    int ch;
    
    cout<<"Enter your Choice: ";
    cin>>ch;
    
    for(int j=0;j<bit;j++){
        int count=0;
        for(int i=0;i<len;i++){
            if(dat[i][j]=='1')
                count++;
        }
        
        if(ch==1){
            if(count%2==0)
                parity[j]=0;
            else
                parity[j]=1;
        }
        
        if(ch==2){
            if(count%2!=0)
                parity[j]=0;
            else
                parity[j]=1;
        }
    }
    
    cout<<endl<<"Parity: ";
    for(int j=0;j<bit;j++){
        cout<<parity[j];
    }
    cout<<endl;
}

