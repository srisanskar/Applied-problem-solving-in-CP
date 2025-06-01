#include<iostream>
using namespace std;

void CoinPiles(long long int &a,long long int &b){
    //Since each move removes three coins, 
    //the total number of coins must be divisible by three.
    if ((a + b) % 3 != 0) {
        cout << "NO";
        return;
    }
    if (max(a, b) > 2 * min(a, b)) {
        cout << "NO";
        return;
    }
    cout << "YES";

    
    //recursion not reqd.. TLE...Simple mathematical problem...

}
int main(){

    long long int n;
    cin>>n;
    
    for(long long int i=0;i<n;i++){
    long long int a,b;
    cin>>a>>b;
    CoinPiles(a,b);
    cout<<endl;
    }

    return 0;

}
