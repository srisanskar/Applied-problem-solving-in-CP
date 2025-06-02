#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool is_enough_time(const vector<ll>& machines, ll time, ll t) {
    ll total = 0;
    for (ll m : machines) {
        total += time / m;
        if (total >= t) return true; 
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;

    vector<ll> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }
    ll low = 1;
    ll high = *min_element(machines.begin(), machines.end()) * t;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (is_enough_time(machines, mid, t)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << '\n';
    return 0;
}
