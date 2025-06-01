#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> parent(n + 1);
        vector<vector<int>> children(n + 1);
        int root = -1;
        
        // Read parent information and build children lists
        for (int i = 1; i <= n; i++) {
            cin >> parent[i];
            if (parent[i] == i) {
                root = i;
            } else {
                children[parent[i]].push_back(i);
            }
        }
        
        // Find all leaf nodes (nodes with no children)
        vector<int> leaves;
        for (int i = 1; i <= n; i++) {
            if (children[i].empty()) {
                leaves.push_back(i);
            }
        }
        
        vector<vector<int>> paths;
        vector<bool> visited(n + 1, false);
        
        // Create paths starting from each leaf going up to root
        for (int leaf : leaves) {
            if (!visited[leaf]) {
                vector<int> path;
                int current = leaf;
                
                // Traverse upward until we reach a visited node
                while (!visited[current]) {
                    path.push_back(current);
                    visited[current] = true;
                    if (current == root) break;
                    current = parent[current];
                }
                
                // Reverse to get top-to-bottom order
                reverse(path.begin(), path.end());
                paths.push_back(path);
            }
        }
        
        // Output the result
        cout << paths.size() << "\n";
        for (const auto& path : paths) {
            cout << path.size();
            for (int node : path) {
                cout << " " << node;
            }
            cout << "\n";
        }
    }
    
    return 0;
}
