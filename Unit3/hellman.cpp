#include <iostream>
using namespace std;
int power(int a, int b, int mod){
    int result=1;
    for(int i=0;i<b;i++){
        result=(result*a)%mod;
    }
    return result;
}
int main(){
    int p,g;
    cout<<"Enter Prime P: ";
    cin>>p;
    
    cout<<"Enter G: ";
    cin>>g;
    
    int a,b;
    cout<<"Enter User A Private Key: ";
    cin>>a;
    
    cout<<"Enter User B Private Key: ";
    cin>>b;
    
    int A=power(g,a,p);
    int B=power(g,b,p);
    
    cout<<"Private key of A: "<<A<<endl;
    cout<<"Private key of B: "<<B<<endl;
    
    int secretA=power(B,a,p);
    int secretB=power(A,b,p);
    
    cout<<"Secret Key of User A: "<<secretA<<endl;
    cout<<"Secret Key of User B: "<<secretB<<endl;
}

