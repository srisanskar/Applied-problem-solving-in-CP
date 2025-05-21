#include <bits/stdc++.h>
using namespace std;

void moves(int n,vector<int>& move, int s, int d, int a){
    if(n==1){
        move.push_back(s);
        move.push_back(d);
        return;
    }
    moves(n-1,move,s,a,d);
    move.push_back(s);
    move.push_back(d);
    moves(n-1,move,a,d,s);
}

int main(){
    int n;cin>>n;
    vector<int> move;
    int s=1,a=2,d=3;
    moves(n, move, s, d, a);
    cout<<move.size()/2<<endl;
    for(int i=0;i<move.size();i+=2){
        cout<<move[i]<<" "<< move[i+1]<<endl;
    }
}