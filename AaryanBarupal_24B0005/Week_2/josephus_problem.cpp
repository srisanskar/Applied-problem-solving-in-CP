#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> children(n);
    for (int i = 0; i < n; i++) {
        children[i] = i + 1;
    }

    long long idx = 0;
    while (!children.empty()) {
        idx = (idx + k) % children.size();
        cout << children[idx] << " ";
        children.erase(children.begin() + idx);
    }
}//O(n^2)
