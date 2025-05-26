#include<iostream>
using namespace std;
// Method...
//Total ways to place 2 knights on 
//k2(k2-1)/2
 

//Subtract  (attacking) configurations: 
//4(k−1)(k−2)

//My soln 
void TwoKnights(long long int i){
    if(i==1){
        cout<<0;
        return;
    }

    if(i==2){
        cout<<6;
        return;
    }

    if(i==3){
        cout<<28;
        return;
    }

    long long int sum=0;

    //long long int Add1 = (2 + 3 + ((i-4)*4)  + 3 + 2) ;
    long long int Add1 = 10 + (i-4)*4 ; 

    for(long long int j = 1 ; j<=i-2 ; j++){
    sum += Add1;
    } 

    //sum+= (1 + 1 + ((i-4)*2) + 1 + 1) ; //2nd last line
    sum+=(4 + (i-4)*2) ;

    long long int  sq = (i*i);
    long long int total = (sq * (sq-1))/2 ; 

    long long int NotAttack = total - sum ; 

    cout<<NotAttack ; 
    return ;

}
int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        TwoKnights(i);
        cout<<endl;
    }

    return 0;

}
