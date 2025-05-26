#include <iostream>
using namespace std;

int main(){
    long long n,sum,asum=0;
    cin >> n;
    int arr[200000];
    for (int i=0; i<(n-1); i++){
        cin >> arr[i];
    }
    for (int i=0; i<(n-1); i++){
        asum+=arr[i];
    }
    sum=n*(n+1)/2;
    cout << (sum-asum) << endl;
}