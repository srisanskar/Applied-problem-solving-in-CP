#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    string s;cin>>s;
    int max=0;
    int curr=1;

    for(int i=0;i<s.length();i++){
        if(s[i]==s[i+1]){
            curr++;
        }
        else{
            if(max<curr) max=curr;
            curr=1;
        }
    }
    cout<< max<<endl;
    
}