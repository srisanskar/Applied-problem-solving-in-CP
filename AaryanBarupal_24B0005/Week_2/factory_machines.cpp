#include<bits/stdc++.h>//binary search
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,t;
    cin>>n>>t;
    vector<long long >machines(n);
    for(int i=0;i<n;i++){
        cin>>machines[i];
    }
    long long low=0;
    long long high=1e18+10;
    while(low<high){
        long long mid=low+(high-low)/2;
        long long total=0;
        bool enough=false;
        for(int i=0;i<n;i++){
            total+=mid/machines[i];
            if(total>=t){
                enough=true;
                break;
            }
        }
        if(enough){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<low<<endl;
}//O(n*log(maxtime))=O(n)