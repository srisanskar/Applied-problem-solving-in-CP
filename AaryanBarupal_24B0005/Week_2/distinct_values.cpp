#include <bits/stdc++.h>//mo's algo
using namespace std;

struct Query {
    int l, r, idx;
};

int block_size;

bool compare(Query a, Query b) {
    if (a.l / block_size != b.l / block_size)
        return a.l / block_size < b.l / block_size;
    return (a.l / block_size % 2) ? (a.r > b.r) : (a.r < b.r);
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    block_size = sqrt(n) + 1;

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a - 1, b - 1, i};
    }

    sort(queries.begin(), queries.end(), compare);

    vector<int> res(q);
    unordered_map<int, int> freq;
    int current_l = 0, current_r = -1;
    int distinct = 0;

    for (Query query : queries) {
        while (current_l > query.l) {
            current_l--;
            int x = arr[current_l];
            if (freq[x] == 0)
                distinct++;
            freq[x]++;
        }
        while (current_r < query.r) {
            current_r++;
            int x = arr[current_r];
            if (freq[x] == 0)
                distinct++;
            freq[x]++;
        }
        while (current_l < query.l) {
            int x = arr[current_l];
            freq[x]--;
            if (freq[x] == 0)
                distinct--;
            current_l++;
        }
        while (current_r > query.r) {
            int x = arr[current_r];
            freq[x]--;
            if (freq[x] == 0)
                distinct--;
            current_r--;
        }
        res[query.idx] = distinct;
    }

    for (int i = 0; i < q; ++i)
        cout << res[i] << "\n";
}

int main() {
    solve();
    return 0;
}//O((N+Q)⋅rootN)