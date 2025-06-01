#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) {
        cin >> x;
    }

    long long ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            long long lcm = a[i] / __gcd(a[i], a[j]) * a[j];
            ans = __gcd(ans, lcm);
        }
    }

    cout << ans << endl;
}
