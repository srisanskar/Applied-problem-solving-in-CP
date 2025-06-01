#include <bits/stdc++.h>
using namespace std;

int bit_array[600010];

void add_value(int pos, int val, int n){
    for(; pos <= n; pos += pos & -pos)
        bit_array[pos] += val;
}

int prefix_sum(int pos){
    int result = 0;
    for(; pos > 0; pos -= pos & -pos)
        result += bit_array[pos];
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<array<int, 3>> intervals(n);
    vector<int> endpoints;

    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        intervals[i] = {x, y, i};
        endpoints.push_back(y);
    }

    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    sort(endpoints.begin(), endpoints.end());
    endpoints.erase(unique(endpoints.begin(), endpoints.end()), endpoints.end());

    auto get_index = [&](int val){
        return int(lower_bound(endpoints.begin(), endpoints.end(), val) - endpoints.begin()) + 1;
    };

    vector<int> contains_other(n), contained_by_other(n);

    fill(bit_array, bit_array + n * 2 + 10, 0);

    for(int i = n - 1; i >= 0; i--){
        int idx = get_index(intervals[i][1]);
        int id = intervals[i][2];
        contains_other[id] = prefix_sum(idx);
        add_value(idx, 1, int(endpoints.size()));
    }

    fill(bit_array, bit_array + n * 2 + 10, 0);

    for(int i = 0; i < n; i++){
        int idx = get_index(intervals[i][1]);
        int id = intervals[i][2];
        contained_by_other[id] = i - prefix_sum(idx - 1);
        add_value(idx, 1, int(endpoints.size()));
    }

    for(int x : contains_other) cout << (x ? 1 : 0) << ' ';
    cout << '\n';
    for(int x : contained_by_other) cout << (x ? 1 : 0) << ' ';
    cout << '\n';
}
