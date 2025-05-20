#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int32_t main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int a[n],dp[x+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<x+1;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<x+1;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]){
                dp[i]+=dp[i-a[j]];
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[x]%MOD<<endl;
}