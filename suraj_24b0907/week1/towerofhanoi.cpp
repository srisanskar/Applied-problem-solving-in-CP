#include <iostream>
#include <vector>
using namespace std;
void fun(int n,int i,int f, int t,vector<int>& vec){
    if(n==1){
        vec.push_back(i);
        vec.push_back(f);       
    }
    else if (n==2){
        vec.push_back(i);
        vec.push_back(t);
        vec.push_back(i);
        vec.push_back(f);
        vec.push_back(t);
        vec.push_back(f);
    }
    else{
        fun(n-1,i,t,f,vec);
        vec.push_back(i);
        vec.push_back(f);
        fun(n-1,t,f,i,vec);    
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    fun(n,1,3,2,vec);
    cout<<int(vec.size()/2)<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
        if(i%2==1){
            cout<<endl;
        }
    }
}