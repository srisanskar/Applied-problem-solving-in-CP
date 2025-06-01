#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_enough(long long time, const vector<long long>& machines, long long t) {
    long long total = 0;
    for (auto k : machines) {
        total += time/k;
        if (total>=t) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    long long t;
    cin >> n >> t;
    vector<long long> machines(n);
    for (int i=0; i<n; i++) {
        cin >> machines[i];
    }

    long long low = 1;
    long long high = *min_element(machines.begin(), machines.end()) * t;
    while (low<high) {
        long long mid = (low+high)/2;
        if (is_enough(mid, machines, t)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    cout << low << endl;
}