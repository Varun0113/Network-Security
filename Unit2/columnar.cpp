#include<iostream>
using namespace std;
string encr(string text,string key){
    int pvalue=text.length();
    int kvalue=key.length();
    
    int row=(pvalue+kvalue-1)/kvalue;
    char matrix[row][kvalue];
    for(int i=0;i<row;i++){
        for(int j=0;j<kvalue;j++){
            int index=i*kvalue+j;
            if(index<pvalue)
                matrix[i][j]=text[index];
            else
                matrix[i][j]='X';
        }
    }
    int indic[kvalue];
    for(int i=0;i<kvalue;i++){
        indic[i]=i;
    }
    string cipher;
    for(int i=0;i<kvalue-1;i++){
        for(int j=i+1;j<kvalue;j++){
            if(key[indic[i]]>key[indic[j]]){
                int temp=indic[i];
                indic[i]=indic[j];
                indic[j]=temp;
            }
        }
    }
    
    for(int i=0;i<kvalue;i++){
        int col=indic[i];
        for(int j=0;j<row;j++){
            cipher+=matrix[j][col];
        }
    }
    
    return cipher;
}
int main(){
    string text,key,key2;
    cout<<"Enter Plain Text: ";
    cin>>text;
    cout<<"Enter Key: ";
    cin>>key;
    
    string cipher=encr(text,key);
    cout<<"Cipher: "<<cipher<<endl;
    
    cout<<"Enter Key2: ";
    cin>>key2;
    string final=encr(cipher,key2);
    cout<<"Final: "<<final<<endl;
}