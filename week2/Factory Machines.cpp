#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canProduce(ll time, const vector<ll>& machines, ll t) {
    ll total = 0;
    for (ll k : machines) {
        total += time / k;
        if (total >= t) return true; 
    }
    return false;
}
int main() {
    cin.tie(nullptr);
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }
    ll left = 1;
    ll right = 1e18;
    ll answer = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (canProduce(mid, machines, t)) {
            answer = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    cout << answer << "\n";
    return 0;
}
