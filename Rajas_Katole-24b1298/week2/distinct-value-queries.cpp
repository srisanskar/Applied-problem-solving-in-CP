#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int BLOCK_SIZE;

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        int block_l = l / BLOCK_SIZE;
        int block_ol = other.l / BLOCK_SIZE;
        if (block_l != block_ol)
            return block_l < block_ol;
        return (block_l & 1) ? (r < other.r) : (r > other.r);
    }
};

int n, q;
int a[MAXN];
int freq[MAXN * 5];  // adjust size based on coordinate compression
int answer[MAXN];
vector<Query> queries;
int current_answer = 0;
map<int, int> compressor;

void add(int x) {
    freq[x]++;
    if (freq[x] == 1) current_answer++;
}

void remove(int x) {
    freq[x]--;
    if (freq[x] == 0) current_answer--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    vector<int> raw(n);
    for (int i = 0; i < n; ++i) {
        cin >> raw[i];
    }

    // Coordinate compression
    vector<int> sorted_raw = raw;
    sort(sorted_raw.begin(), sorted_raw.end());
    sorted_raw.erase(unique(sorted_raw.begin(), sorted_raw.end()), sorted_raw.end());
    for (int i = 0; i < (int)sorted_raw.size(); ++i) {
        compressor[sorted_raw[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = compressor[raw[i]];
    }

    BLOCK_SIZE = sqrt(n);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;  // convert to 0-indexed
        queries.push_back({l, r, i});
    }

    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    for (auto query : queries) {
        while (r < query.r) add(a[++r]);
        while (r > query.r) remove(a[r--]);
        while (l < query.l) remove(a[l++]);
        while (l > query.l) add(a[--l]);
        answer[query.idx] = current_answer;
    }

    for (int i = 0; i < q; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}
