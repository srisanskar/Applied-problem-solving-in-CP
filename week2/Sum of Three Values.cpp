#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        int left = i + 1;
        int right = n - 1;
        long long target = x - arr[i].first;

        while (left < right) {
            long long sum = arr[left].first + arr[right].first;
            if (sum == target) {
                cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << "\n";
                return 0;
            }
            if (sum < target)
                ++left;
            else
                --right;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
