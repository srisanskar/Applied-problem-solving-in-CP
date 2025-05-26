#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    long long int n;
    cin>>n;

    vector<long long int> vec(n);

    for(long long int i=0;i<n;i++){
        cin>>vec[i];
    }
    

    long long int i=1;
    long long int count = 0;
    long long int diff = 0;
    while(i<n){
        if(vec[i]<vec[i-1]){
            diff = vec[i-1]-vec[i];
            count+=diff;
            vec[i]=vec[i-1];
        }
        i++;

    }

    cout<<count ; 
    

    return 0;

}