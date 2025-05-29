#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    int n;
    cin>>n;

    vector<int> vec;
    bool found = false;
    
    for(int i=1;i<n;i++){
    int x;
    cin>>x;
    vec.push_back(x) ;
    }

    sort(vec.begin(),vec.end());


    for(int i=0;i<=n-2;i++){
    if(vec[i]!=i+1){
    cout<< i+1 ;
    found = true;
    break;
    }
    }

    if(!found) cout<<n;
    

    return 0;

}
