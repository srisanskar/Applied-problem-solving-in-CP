#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    set<int> alive;
    for (int i = 1; i <= n; ++i)
        alive.insert(i);

    auto it = alive.begin();
    for (int i = 0; i < n; ++i) {
        int remaining = alive.size();
        long long skip = k % remaining;
        // Move 'skip' positions forward
        while (skip--) {
            ++it;
            if (it == alive.end()) it = alive.begin();
        }
        cout << *it << " ";
        // Erase current element and move to the next one
        auto next_it = std::next(it);
        if (next_it == alive.end()) next_it = alive.begin();
        alive.erase(it);
        it = next_it;
    }
    return 0;
}
