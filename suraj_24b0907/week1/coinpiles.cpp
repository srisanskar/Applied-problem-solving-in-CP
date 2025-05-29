#include <iostream>
using namespace std;
int main(){
    long int n,a,b,d;
    cin >> n;
    for(long int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        if(a<b){swap(a,b);}
        d=a-b;
        a=a-2*d;
        b=b-d;
        if(a<0 || b<0 || a!=b){cout<<"NO"<<endl;}
        else if(a==b && a>=0){ if(a%3==0){cout << "YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
        else {cout << "NO"<<endl;}
}}