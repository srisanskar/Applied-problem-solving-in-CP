#include <iostream>
using namespace std;
#define num 1000000007
int fun(int sum,int arr[],int n, int p){
    int t=0;            
    int k=0;
    if (sum ==0){
        return 1;
    }
    else if (sum < 0){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(i!=p){
            int sumi=sum;
            while(sumi>0){
                sumi-=arr[i];
                t+=fun(sumi,arr,n,i);
            }}
    }
    return t%num;
}
int main(){
    int n,sum;
    cin>>n;
    cin>>sum;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << fun(sum,arr,n,-1);
}