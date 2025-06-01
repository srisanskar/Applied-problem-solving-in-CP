#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int A=1e5+10;
int n;
long long arr[N];
long long prefix[A],suffix[A];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        prefix[i]=__gcd(prefix[i-1],arr[i]);
    }
    for(int i=n;i>=1;i--){
        suffix[i]=__gcd(suffix[i+1],arr[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long gcd_without_ai;
        if(i==1){
            gcd_without_ai=suffix[i+1];
        }
        else if(i==n){
            gcd_without_ai=prefix[i-1];
        }
        else{
            gcd_without_ai=__gcd(prefix[i-1],suffix[i+1]);
        }
        long long lcm=(arr[i] / __gcd(arr[i], gcd_without_ai)) * gcd_without_ai;
        ans=__gcd(lcm,ans);
    }
    cout<<ans<<'\n';
}//O(n log m)