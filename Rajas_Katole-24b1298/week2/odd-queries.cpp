#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> prefix(n + 1, 0);
    int total_sum_parity = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        total_sum_parity += a[i];
    }
    total_sum_parity %= 2;

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int range_sum = prefix[r] - prefix[l - 1];
        int new_range_sum_parity = (k % 2) * (r - l + 1) % 2;
        int total_parity_after = (total_sum_parity - (range_sum % 2) + new_range_sum_parity) % 2;
        if (total_parity_after < 0) total_parity_after += 2;
        if (total_parity_after % 2 == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}