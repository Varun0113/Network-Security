#include<iostream>
using namespace std;

int main(){
    
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string pt;
    string cip = "";
    string nor = "";
    
    cout<<"Enter Plain Text:- ";
    cin>>pt;
    
    //Encrypt
    for(int i = 0; i < pt.length(); i++){
        int n = alpha.find(pt[i]);
        cip += key.at(n);
    }
    
    cout<<endl<<"Cipher Text:- "<<cip;
    
    //Decrypt
    for(int i = 0; i < cip.length(); i++){
        int n = key.find(cip[i]);
        nor += alpha.at(n);
    }
    
    cout<<endl<<"Normal Text:- "<<nor;

    
    return 0;
}