#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r;
    cin >> l >> r;
    long long n = r - l + 1;
    if (n % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (long long i = l; i < r; i += 2) {
        cout << i << " " << i + 1 << "\n";
    }
    return 0;
}
