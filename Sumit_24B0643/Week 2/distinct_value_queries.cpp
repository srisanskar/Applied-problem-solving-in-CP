#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, q, a, b;
    cin >> n >> q;

    vector<int> arr;
    for (int i=0; i<n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    
    for (int i=0; i<q; i++) {
        vector<int> sarr, carr;

        cin >> a >> b;

        for (int j=a-1; j<b; j++) {
            sarr.push_back(arr[j]);
        }

        for (int j:sarr) {
            bool f = false;
            for (int k:carr) {
                if (k==j) {
                    f = true;
                }
            }
            if (f==false){
                carr.push_back(j);
            }
        }

        cout << carr.size() << endl;
    }
}