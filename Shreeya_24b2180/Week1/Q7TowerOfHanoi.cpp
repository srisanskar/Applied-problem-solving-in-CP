#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

// void DiscCount(int n,int st, int e, int sp,int &count){
//     if(n==1){
//         // cout<<st<<" "<<e<<endl;
//         count+=1;
//         return;
    
//     }

//     DiscCount(n-1,st,sp,e,count);
//     //cout<<st<<" "<<e<<endl;
//     count+=1;
//     DiscCount(n-1,sp,e,st,count);


//     return;

// }

void Hanoi(int n,int st, int e, int sp){
    if(n==1){
        cout<<st<<" "<<e<<endl;
        return;
    
    }

    Hanoi(n-1,st,sp,e);
    cout<<st<<" "<<e<<endl;
    Hanoi(n-1,sp,e,st);


    return ;

}

int main(){

    int n;
    cin>>n;

    //int count = 0;

    //DiscCount(n,1,3,2,count);
    //cout<<count<<endl; 

    cout<<pow(2,n) - 1 <<endl; //num of moves reqd... 2powern - 1 ;
    Hanoi(n,1,3,2);

    return 0;

}

//M2 
//#include <iostream>
// #include <vector>
// using namespace std;

// vector<pair<int, int>> moves;

// void move(int n, int a, int b, int c) {
//     if (n == 1) {
//         moves.emplace_back(a, b);
//     } else {
//         move(n - 1, a, c, b);
//         move(1, a, b, c);
//         move(n - 1, c, b, a);
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     move(n, 1, 3, 2);
//     cout << moves.size() << "\n";
//     for (auto [a, b] : moves) {
//         cout << a << " " << b << "\n";
//     }
// }