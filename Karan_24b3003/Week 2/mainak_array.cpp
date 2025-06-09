#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long g = a[0];
    for (int i = 1; i < n; ++i)
        g = gcd(g, a[i]);
    for (int i = 0; i < n; ++i)
        a[i] /= g;
    long long result = a[0];
    for (int i = 1; i < n; ++i) {
        long long l = lcm(a[0], a[i]);
        result = gcd(result, l);
    }
    cout << result * g << '\n';
    return 0;
}
