#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q;
int a[MAXN];
int ans[MAXN];
int freq[MAXN];
int cnt = 0;

map<int, int> compress;
int compressed[MAXN];

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int block_size = sqrt(n);
        if (l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return ((l / block_size) & 1) ? (r > other.r) : (r < other.r);
    }
};

vector<Query> queries;

void add(int pos) {
    if (++freq[compressed[pos]] == 1)
        cnt++;
}

void remove(int pos) {
    if (--freq[compressed[pos]] == 0)
        cnt--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<int> values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.push_back(a[i]);
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < values.size(); ++i)
        compress[values[i]] = i;

    for (int i = 0; i < n; i++)
        compressed[i] = compress[a[i]];

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l - 1, r - 1, i});
    }

    sort(queries.begin(), queries.end());

    int currL = 0, currR = -1;
    for (const auto& q : queries) {
        while (currL > q.l) add(--currL);
        while (currR < q.r) add(++currR);
        while (currL < q.l) remove(currL++);
        while (currR > q.r) remove(currR--);
        ans[q.idx] = cnt;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return 0;
}
