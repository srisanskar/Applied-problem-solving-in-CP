#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> children(n + 1);
    vector<bool> is_leaf(n + 1, true);
    int root = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] == i) {
            root = i;
        } else {
            children[p[i]].push_back(i);
            is_leaf[p[i]] = false;
        }
    }

    vector<vector<int>> paths;
    for (int i = 1; i <= n; ++i) {
        if (is_leaf[i]) {
            vector<int> path;
            int current = i;
            while (true) {
                path.push_back(current);
                if (current == root) break;
                current = p[current];
            }
            reverse(path.begin(), path.end());
            paths.push_back(path);
        }
    }

    cout << paths.size() << "\n";
    for (auto &path : paths) {
        cout << path.size() << "\n";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
