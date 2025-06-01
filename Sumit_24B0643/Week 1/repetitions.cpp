#include <iostream>
using namespace std;

int main(){
    string seq;
    cin >> seq;
    int r=1;
    int arr[1000000]={1}, s=0;
    for (int i=1; i<(seq.length()); i++){
        if (seq[i]==seq[i-1]){
            r++;
        }
        else{
            r=1;
        }
        arr[s++]=r;
    }
    int max=arr[0];
    for (int i=1; i<(seq.length()); i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    cout << max << endl;
}