#include <bits/stdc++.h>
using namespace std;

void solve(){
    int node_count;
    cin >> node_count;

    vector<int> parent(node_count + 1);
    vector<vector<int>> children(node_count + 1);

    // Read parent array and build child lists
    for(int node = 1; node <= node_count; ++node){
        cin >> parent[node];
        if (parent[node] != node){
            children[parent[node]].push_back(node);
        }
    }

    // Identify all leaf nodes (no children)
    vector<int> leaf_nodes;
    for(int node = 1; node <= node_count; ++node){
        if (children[node].empty()){
            leaf_nodes.push_back(node);
        }
    }

    vector<vector<int>> all_paths;
    vector<bool> visited(node_count + 1, false);

    // From each leaf, build the path up to the root
    for(int leaf : leaf_nodes){
        vector<int> path;
        int current = leaf;

        while(!visited[current]){
            path.push_back(current);
            visited[current] = true;
            if (parent[current] == current) break;
            current = parent[current];
        }

        reverse(path.begin(), path.end());
        all_paths.push_back(path);
    }

    // Output result
    cout << all_paths.size() << '\n';
    for(const auto& path : all_paths){
        cout << path.size() << '\n';
        for(int node : path){
            cout << node << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}