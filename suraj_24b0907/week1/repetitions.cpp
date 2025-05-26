#include <iostream>
using namespace std;

int main() {
    string a;
    char c=char('A');
    int pre=0,max=0;
    cin >> a; 
    for (char ch : a) {
        if(ch==c){
            pre+=1;
        }
        else{
            c=ch;
            if (pre > max){
                max=pre;
            }
            pre=1;
        }        
    }
    if (pre > max){
    max=pre;
}   
    cout<<max;
    return 0;
}
