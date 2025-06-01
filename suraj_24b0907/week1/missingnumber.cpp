#include <iostream>
using namespace std;
int main(){
    int n;
    int sum=0;
    int k;
    int tot=0;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> k;
        sum+=k;
        tot+=i;
    }
    tot+=n+n-1;
    cout<<tot-sum;
}