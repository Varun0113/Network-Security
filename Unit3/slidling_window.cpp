#include<iostream>
#include<cstdlib>
#include<chrono>
#include<thread>
using namespace std;
int main(){
    int total=10;
    int win=3;
    int frame=1;
    
    while(frame<=total){
        int sent=0;
        for(int i=0;i<win&&frame+i<=total;i++){
            cout<<"Sending Frame: "<<frame+i<<endl;
            sent++;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
        int ack=0;
        
        for(int i=0;i<sent;i++){
            int act=rand()%2;
            if(act==1){
                cout<<"Frame sent"<<frame+i<<endl;
                ack++;
            }
            else{
                cout<<"Fail to send,Sending again"<<frame+i<<endl;
            }
        }
        frame+=ack;
        cout<<"-----------"<<endl;
    }
    cout<<"All sent"<<endl;
}
