#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n; 
    vector<int> heights(n);
    for(int i=0 ; i<n ; i++){
        cin >> heights[i];
    }

    int maxH = 0;
    int minH = 0;
    int maxIdx = 0;
    int minIdx = 0;
    for(int i=0 ; i<n ; i++){
        if(heights[i]>maxH){
            maxH = max(maxH , heights[i]);
            maxIdx = max(i,maxIdx);
        }
        else if(heights[i]<minH){
            minH = min(minH , heights[i]);
            minIdx = max(i,maxIdx);
        }

    }

}