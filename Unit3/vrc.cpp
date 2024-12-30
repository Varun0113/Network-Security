#include<iostream>
using namespace std;
int main(){
    string data;
    cout<<"Enter Data: ";
    cin>>data;
    
    int count=0;
    for(int i=0;i<data.length();i++){
        if(data[i]=='1')
            count++;
    }
    
    int ch;
    cout<<"Enter your Choice: ";
    cin>>ch;
    
    if(ch==1){
        if(count%2==0)
            data.append("0");
        else
            data.append("1");
    }
    if(ch==2){
        if(count%2!=0)
            data.append("0");
        else
            data.append("1");
    }
    
    cout<<"Answer: "<<data;
}