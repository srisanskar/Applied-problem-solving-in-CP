#include <bits/stdc++.h>
using namespace std;

void moves(int n, vector<vector<int>> move, int s, int d, int a){
    if(n==1){
        move.push_back(s,d);
        return
    }
    moves(n-1, move, s,a,d);
    move.push_back(s,d);
    moves(n-1,move,a,d,s);
}

int main(){
    int n;cin>>n;
    vector<vector<int>> move;
    int s=1;
    int a=2;
    int d=3;
    cout<<move.size()<<endl;
    for(auto mov:move){
        cout<<mov[0]<<" "<< mov[1]<<endl;
    }
}