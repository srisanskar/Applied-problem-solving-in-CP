#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    list<int> circle;
    for (int i = 1; i <= n; ++i)
        circle.push_back(i);

    auto it = circle.begin();
    while (!circle.empty()) {
        int step = k % circle.size();
        for (int i = 0; i < step; ++i) {
            ++it;
            if (it == circle.end()) it = circle.begin();
        }
        cout << *it << " ";
        it = circle.erase(it);
        if (it == circle.end()) it = circle.begin();
    }   
    return 0;
}
