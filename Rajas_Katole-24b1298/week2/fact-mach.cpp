#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool canMake(ll time, const vector<ll>& k, ll t) {
    ll products = 0;
    for (ll machine : k) {
        products += time / machine;
        if (products >= t) return true;
    }
    return false;
}

int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> k(n);
    for (ll& x : k) cin >> x;

    ll left = 1, right = 1e18, ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canMake(mid, k, t)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
