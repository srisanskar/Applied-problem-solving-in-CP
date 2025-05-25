#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;cin>>t;
    for(int n=1;n<=t;n++){
        int total=n*n *(n*n -1)/2 ;
        int attacking= 4*(n-1)*(n-2);
        cout << total-attacking <<endl;
    }
}