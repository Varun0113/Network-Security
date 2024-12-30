#include<iostream>
using namespace std;

string encry(string s, int k){
    string cipher;
    for(int i = 0; i<s.length(); i++){
        if(isupper(s[i]))
            cipher += char(int(s[i]+k - 'A') %26 + 'A');
        else
            cipher += char(int(s[i]+k - 'a') %26 + 'a');
    }

    return cipher;
}

string decry(string s, int k){
    string decry;
    for(int i = 0; i<s.length(); i++){
        if(isupper(s[i]))
            decry += char(int(s[i]-k - 'A' + 26) %26 + 'A');
        else
            decry += char(int(s[i]-k - 'a' + 26) %26 + 'a');
    }

    return decry;
}

int main(){

    string txt;
    int key;

    cout<<"Enter Text:- ";
    cin>>txt;

    cout<<"Enter Key:- ";
    cin>>key;

    string cipher = encry(txt, key);
    cout<<"Cipher:- "<<cipher<<endl;

    string pt = decry(cipher, key);
    cout<<"Plain Text:- "<<pt<<endl;

    return 0;
}
