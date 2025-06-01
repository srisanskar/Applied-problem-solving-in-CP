#include <bits/stdc++.h>
using namespace std;

void solve(int N, int K){
    vector<vector<int>> kids;
    int root_N = sqrt(N);
    int count = 0;

    vector<int> vec;
    for(int i = 1; i <= N; i++){
        if (count > root_N){
            count = 0;
            kids.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
        count++;
    }
    if (!vec.empty())
        kids.push_back(vec);

    int row = 0, col = 0;
    for(int i = 0; i < N; i++){
        int j = K % (N - i);

        while(j){
            if (col + j < kids[row].size()){
                col += j;
                j = 0;
            }
            else {
                j -= kids[row].size() - col;
                col = 0;
                row++;
            }
            if (row >= kids.size())
                row = 0;
        }

        while(kids[row].size() <= col){
            col = 0;
            row++;
            if (row >= kids.size())
                row = 0;
        }
        cout << kids[row][col] << " ";
        if (i != N - 1){
            kids[row].erase(kids[row].begin() + col);
            while(kids[row].size() <= col){
                col = 0;
                row++;
                if (row >= kids.size())
                    row = 0;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    int k; cin >> k;
    solve(n, k);
}