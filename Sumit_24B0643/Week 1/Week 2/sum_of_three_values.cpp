#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end());

    for (int i=0; i<n-2; i++) {
        int left = i+1;
        int right = n-1;

        while (left<right) {
            long long sum = arr[i].first + arr[left].first + arr[right].first;
            if (sum==x) {
                cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << endl;
                return 0;
            } else if (sum<x) {
                ++left;
            } else {
                --right;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}