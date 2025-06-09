#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long pair_lcm = lcm(a[i], a[j]);
            result = gcd(result, pair_lcm);
        }
    }
    cout << result << endl;
    return 0;
}
