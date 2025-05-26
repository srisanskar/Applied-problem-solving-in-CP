#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  
  long int n;
  cin>>n;
  long int x;
  cin>>x;
  long int arr[n];
  for(long int i=0; i<n;++i){
    long int p;
    cin >>p;
    arr[i]=p;
  }
  sort(arr, arr + n);
  long int i=0,j=n-1,m=0;
  while(i<=j){
    if(arr[i]+arr[j]<=x){
      ++i;
    }
    --j;
    ++m;
  }
  cout<<m;
  
  
    
  
}