#include <iostream>
using namespace std;
#include <vector>
long long unsigned int fun(vector<long long unsigned int>& v, int n){
    int l=v.size();
    if(l>=n){return v[n-1];}
    long long unsigned int t=(2*fun(v,n-1))-fun(v,n-2)+(2*(n*n))-8+1+(((2*n)-3)*((2*n)-3))-4;
    v.push_back(t);
    return t;
}
int main() {
    vector<long long unsigned int> v={0,6,28};
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        cout<<fun(v,i)<<endl;
    }
}