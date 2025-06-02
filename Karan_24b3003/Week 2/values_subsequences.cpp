#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int BLOCK_SIZE;

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int block_a = l / BLOCK_SIZE;
        int block_b = other.l / BLOCK_SIZE;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r); 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    BLOCK_SIZE = sqrt(n);

    vector<int> arr(n);
    vector<int> values;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        values.push_back(arr[i]);
    }

    // Coordinate Compression
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < n; ++i) {
        arr[i] = lower_bound(values.begin(), values.end(), arr[i]) - values.begin();
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].l; --queries[i].r; 
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> freq(values.size(), 0);
    vector<int> answer(q);
    int curr_l = 0, curr_r = -1, distinct = 0;

    auto add = [&](int x) {
        if (freq[x] == 0) ++distinct;
        ++freq[x];
    };

    auto remove = [&](int x) {
        --freq[x];
        if (freq[x] == 0) --distinct;
    };

    for (auto& query : queries) {
        while (curr_l > query.l) add(arr[--curr_l]);
        while (curr_r < query.r) add(arr[++curr_r]);
        while (curr_l < query.l) remove(arr[curr_l++]);
        while (curr_r > query.r) remove(arr[curr_r--]);
        answer[query.idx] = distinct;
    }

    for (int i = 0; i < q; ++i)
        cout << answer[i] << '\n';

    return 0;
}
