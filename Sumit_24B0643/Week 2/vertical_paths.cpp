#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        cin >> parent[i];
    }

    set<vector<int>> paths;
    for (int i=0; i<n; i++) {
        vector<int> path;
        int current = i;
        while (current != -1) {
            path.push_back(current);
            current = parent[current] - 1;
        }
        paths.insert(path);
    }

    cout << paths.size() << endl;
}
