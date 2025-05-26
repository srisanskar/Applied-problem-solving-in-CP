#include <iostream>
#include <numeric>
using namespace std;
int fun(int t,string s,string a,int r, int b,int arr[7][7],int x,int y){    
    if(t>100){return t;}
    int l=s.length(),p=t;
        if(b<0 || r<0 || b>6 || r>6){return 0;} 
    if(b==0 && r==0 && l>=1){return 0;}
    if (b==6 && r==0){
        if(l==48){cout<<"a"<<endl;return 1;}
        else {return 0;}
    }            
    if(l!=0 ){
        if(arr[x][y]!=0){return 0;};
            arr[x][y]=1;
    }
    if(l==48){arr[x][y]=0;return 0;}
    if(a[l]=='U'){cout<<"u"<<endl;t+=fun(p,s+a[l],a,r,b-1,arr,x,y-1);}
    else if(a[l]=='D'){cout<<"d"<<endl;t+=fun(p,s+a[l],a,r,b+1,arr,x,y+1);}
    else if(a[l]=='R'){cout<<"r"<<endl;t+=fun(p,s+a[l],a,r+1,b,arr,x+1,y);}
    else if(a[l]=='L'){cout<<"l"<<endl;t+=fun(p,s+a[l],a,r-1,b,arr,x-1,y);}
    else if (a[l]=='?' ){t=t+fun(p,s+'D',a,r,b+1,arr,x,y+1)+fun(p,s+'R',a,r+1,b,arr,x+1,y)+fun(p,s+'L',a,r-1,b,arr,x-1,y)+fun(p,s+'U',a,r,b-1,arr,x,y-1);}    
    arr[x][y]=0;
    return t;
}
int main() {
    string a,s="";
    int arr[7][7] {};
    arr[0][0]=-2;
    arr[0][6]=-2;
    getline(cin, a);
    int t=0;
    int l=fun(0,s,a,0,0,arr,0,0);
    cout<<l;
}