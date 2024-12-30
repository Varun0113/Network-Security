#include<iostream>
using namespace std;
int main(){
    string str;
    cout<<"Enter Str: ";
    cin>>str;
    
    int key;
    cout<<"Enter Key: ";
    cin>>key;
    
    string rails[key];
    int steps=1,ra=0;
    
    for(int i=0;i<str.length();i++){
        rails[ra]+=str[i];
        if(ra==0)
            steps=1;
        else if(ra==key-1)
            steps=-1;
        ra+=steps;
    }
    string cip;
    for(int i=0;i<key;i++){
        cip+=rails[i];
    }
    cout<<"Cipher: "<<cip;
}
