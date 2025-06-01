#include <bits/stdc++.h>
using namespace std;

struct Query{
    int l, r, idx;
};

// sqrt(2e5)
const int block_size = 450;

bool compare(Query a, Query b){
    if (a.l / block_size != b.l / block_size)
        return a.l / block_size < b.l / block_size;
    return a.r < b.r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for(int i=0; i<N; ++i){
        cin >> x[i];
    }

    map<int, int> comp;
    int compressed_val = 0;
    for(int i=0; i<N; ++i){
        if (comp.find(x[i]) == comp.end()){
            comp[x[i]] = compressed_val++;
        }
        x[i] = comp[x[i]];
    }

    vector<Query> queries(Q);
    for(int i = 0; i < Q; ++i){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; // converting to 0-based index
        queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), compare);

    vector<int> freq(compressed_val, 0);
    int current_l = 0, current_r = -1;
    int distinct = 0;
    vector<int> ans(Q);

    for(Query q : queries){
        while(current_l > q.l){
            current_l--;
            if (freq[x[current_l]] == 0){
                distinct++;
            }
            freq[x[current_l]]++;
        }
        while(current_r < q.r){
            current_r++;
            if (freq[x[current_r]] == 0){
                distinct++;
            }
            freq[x[current_r]]++;
        }
        while(current_l < q.l){
            freq[x[current_l]]--;
            if (freq[x[current_l]] == 0){
                distinct--;
            }
            current_l++;
        }
        while(current_r > q.r){
            freq[x[current_r]]--;
            if (freq[x[current_r]] == 0){
                distinct--;
            }
            current_r--;
        }
        ans[q.idx] = distinct;
    }

    for(int i = 0; i < Q; ++i){
        cout << ans[i] << "\n";
    }
}