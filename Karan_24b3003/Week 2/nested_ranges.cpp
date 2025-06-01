#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, i};
    }
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });

    vector<int> contains(n, 0), contained(n, 0);
    int max_y = 0;
    for (auto &[x, y, idx] : ranges) {
        if (y <= max_y) contained[idx] = 1;
        max_y = max(max_y, y);
    }

    int min_y = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        auto &[x, y, idx] = ranges[i];
        if (y >= min_y) contains[idx] = 1;
        min_y = min(min_y, y);
    }

    for (int i = 0; i < n; ++i) cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i) cout << contained[i] << " ";
    cout << "\n";

    return 0;
}
