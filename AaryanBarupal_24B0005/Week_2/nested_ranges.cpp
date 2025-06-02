#include<bits/stdc++.h>
using namespace std;
struct Range{
    int l,r,idx;
};

bool cmp_contained(const Range& a,const Range& b){
    if(a.l==b.l){
        return a.r>b.r;
    }
    return a.l<b.l;
}

bool cmp_contains(const Range& a,const Range& b){
    if(a.l==b.l){
        return a.r<b.r;
    }
    return a.l>b.l;
}

int main(){
    int n;
    cin>>n;
    vector<Range>ranges(n);
    for(int i=0;i<n;i++){
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].idx=i;
    }
    vector<int>contains(n,0),contained(n,0);

    sort(ranges.begin(),ranges.end(),cmp_contained);
    int max_r=0;
    for(const auto& range:ranges){
        if(range.r<=max_r){
            contained[range.idx]=1;
        }
        max_r=max(max_r,range.r);
    }

    sort(ranges.begin(),ranges.end(),cmp_contains);
    int min_r=1e9+10;
    for(const auto& range:ranges){
        if(range.r>=min_r){
            contains[range.idx]=1;
        }
        min_r=min(min_r,range.r);
    }

    for(int val: contains){
        cout<<val<<" ";
    }
    cout<<endl;
    for(int val: contained){
        cout<<val<<" ";
    }
    cout<<endl;
}//O(n logn)