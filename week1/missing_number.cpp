#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int a[n-1];
    int sum=0;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout << n*(n+1)/2 - sum<<endl;

}