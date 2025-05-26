#include <iostream>
using namespace std;

int main(){
    long long n,m=0;
    cin >> n;
    int arr[200000];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<n; i++){
        while (arr[i]<arr[i-1]){
            arr[i]++;
            m++;
        }
    }
    cout << m << endl;
}