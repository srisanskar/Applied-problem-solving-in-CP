#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    //These two lines together can speed up input/output by 3x to 10x,
    // which can prevent TLE in tight time limits.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;

    vector<int> w(n) ;
   for(int i = 0;i<n; i++){
    int a ;
    cin>>a;
    w.push_back(a);
   }

   int st = 0;
   int end = n-1;

    int count=0;

    sort(w.begin(),w.end(),greater<int>()); //AO

   while(st<=end){

    if(st==end){
    count++ ; 
    break;
    }

    else if((w[st]+w[end])>x){
        count++;
        st++;
    }
    else {
        count++;
        st++;
        end--;

    }
   }
    
   cout<<count ; 

    return 0;

}