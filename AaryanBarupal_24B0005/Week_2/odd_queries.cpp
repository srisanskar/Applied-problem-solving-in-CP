#include<bits/stdc++.h>//prefix sum hashing
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> vec(n + 1);
        vector<long long> pref_sum(n + 1, 0);
        long long sum = 0;
        
        for (int i = 1; i <= n; ++i) {
            cin >> vec[i];
            pref_sum[i] = pref_sum[i - 1] + vec[i];
            sum += vec[i];
        }
        
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            long long temp = sum - (pref_sum[r] - pref_sum[l - 1]) + (long long)(r - l + 1) * k;
            if (temp % 2 == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}//O(t*(n+q))=4e5