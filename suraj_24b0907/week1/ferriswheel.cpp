#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, max;
    cin >> n >> max;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i=0,j=n-1,t=0;
    while (i<=j) {
        if (v[i]+v[j] <= max) {
            i++;
        }
        j--;
        t++;
    }
    cout << t << endl;
}