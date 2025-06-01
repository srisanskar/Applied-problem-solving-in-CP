#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);  // {value, original_index}
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;  // store original index (1-based)
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        int target = x - a[i].first;
        int l = i + 1, r = n - 1;

        while (l < r) {
            int sum = a[l].first + a[r].first;
            if (sum == target) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
