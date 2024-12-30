#include<iostream>
using namespace std;

int altonum(char c){
    return int(c-'A');
}

char numtoal(int n){
    return char(n +'A');
}

int main(){
    
    string pt;
    string cip;
    string key;
    string nor;
    
    cout<<"Enter PT (uppercase letters only):- ";
    cin>>pt;
    
    int pval[pt.length()];
    int kval[pt.length()];
    int cval[pt.length()];
    
    cout<<"Enter Key (uppercase letters only):- ";
    cin>>key;
    
    //Key Value Generate
    for(int i=0, j=0; i<pt.length(); i++,j++){
        if(j>=key.length()){
            j = 0;
        }
        kval[i] = altonum(key[j]);
    }
    
    for(int i = 0; i<pt.length(); i++){
        pval[i] = altonum(pt[i]);
        cval[i] = pval[i] + kval[i];
        cip += numtoal(cval[i]%26);
    }
    
    cout<<"Cipher:- "<<cip<<endl;
    
    for(int i = 0; i<cip.length(); i++){
        pval[i] = cval[i] - kval[i];
        nor += numtoal(pval[i] %26);
    }
    
    cout<<"Normal:- "<<nor<<endl;

    
    return 0;
}
