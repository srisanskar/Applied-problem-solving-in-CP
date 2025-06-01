#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;  // (x, y, index)
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges.emplace_back(x, y, i);
    }

    // Sort by x ascending, y descending
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    vector<int> contains(n), contained(n);

    // Check for "contained" (if current range is contained by a previous one)
    int max_y = 0;
    for (auto &[x, y, idx] : ranges) {
        if (y <= max_y)
            contained[idx] = 1;
        max_y = max(max_y, y);
    }

    // Check for "contains" (if current range contains a later one)
    int min_y = 1e9 + 1;
    for (int i = n - 1; i >= 0; --i) {
        auto &[x, y, idx] = ranges[i];
        if (y >= min_y)
            contains[idx] = 1;
        min_y = min(min_y, y);
    }

    for (int x : contains) cout << x << " ";
    cout << '\n';
    for (int x : contained) cout << x << " ";
    cout << '\n';

    return 0;
}
