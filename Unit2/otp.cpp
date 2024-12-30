#include <iostream>
using namespace std;

int altonum(char n){
    return int(n - 'A');
}

int numtoal(int n){
    return char(n + 'A');
}

int main(){
    
    string pt, key;
    
    cout<<"Plain Text (Upper Case Only):- ";
    cin>>pt;
    
    cout<<"Key (Upper Case Only):- ";
    cin>>key;
    
    string cip;
    
    if(key.length()<pt.length()){
        int repeat = pt.length() - key.length();
        int actuallen = repeat+key.length();
        int k = 0;
        for(int i = key.length();i<actuallen;i++){
            key+=key[k];
            k++;
        }
    }
    
    for(int i = 0; i<pt.length(); i++){
        int ptnum = altonum(pt[i]);
        int knum = altonum(key[i]);
        int otp = ptnum + knum;
        if(otp>26)
            otp -= 26;
        cip += numtoal(otp);
    }
    
    cout<<"Cipher:- "<<cip;
    
    return 0;
}
