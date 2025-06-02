#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n+1), pre_sum(n+1, 0);

        for (int i=1; i<=n; i++) {
            cin >> a[i];
            pre_sum[i] = pre_sum[i-1] + a[i];
        }

        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            long long sum_outside = pre_sum[l-1] + (pre_sum[n]-pre_sum[r]);
            long long sum_replaced = static_cast<long long>(r- l+1) * k;
            long long total_sum = sum_outside + sum_replaced;
            cout << (total_sum % 2 ? "YES" : "NO") << endl;
        }
    }
}
