#include<bits/stdc++.h>//tree representation
using namespace std;
void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>parent(n+1);
        vector<vector<int>>children(n+1);
        int root=-1;
        for(int i=1;i<=n;i++){
            cin>>parent[i];
            if(parent[i]==i){
                root=i;
            }
            else{
                children[parent[i]].push_back(i);
            }
        }
        vector<int>leaves;
        for(int i=1;i<=n;i++){
            if(children[i].empty()){
                leaves.push_back(i);
            }
        }
        vector<vector<int>>paths;
        vector<bool>visited(n+1,false);
        for(int leaf: leaves){
            vector<int>path;
            int current=leaf;
            while(!visited[current]){
                path.push_back(current);
                visited[current]=true;
                if(current==root){
                    break;
                }
                current=parent[current];
            }
            reverse(path.begin(),path.end());
            paths.push_back(path);
        }
        cout<<paths.size()<<'\n';
        for(const auto& path: paths){
            cout<<path.size()<<'\n';
            for(int val: path){
                cout<<val<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}//O(t*n)=2e5


