#include <iostream>
using namespace std;
int main(){
    long int n,sum1=0,sum2=0;
    cin>>n;
    long int arr[n];   
    cin >> arr[0];
    for(int i=1;i<n;i++){
        cin>>arr[i];
        sum1+=arr[i];
        if(arr[i]<arr[i-1]){
            arr[i]=arr[i-1];
        }
        sum2+=arr[i];
    }
    cout<<sum2-sum1;
}