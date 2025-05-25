#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    cin>>s ;

    int n = s.length() ; 
    int max_freq = 1;
    int curr_freq = 1;

    for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
        curr_freq++;
    }

    else 
    curr_freq = 1;

    max_freq = max(max_freq,curr_freq);
    }

    cout<<max_freq;
   

    return 0;

}