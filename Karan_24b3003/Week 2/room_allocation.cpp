#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers[i] = {a, b, i};
    }
    sort(customers.begin(), customers.end());
    // {departure_day, room_number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> result(n);
    int room_count = 0;

    for (auto &[a, b, idx] : customers) {
        if (!pq.empty() && pq.top().first < a) {
            auto [end_time, room_no] = pq.top();
            pq.pop();
            result[idx] = room_no;
            pq.push({b, room_no});
        } else {
            ++room_count;
            result[idx] = room_count;
            pq.push({b, room_count});
        }
    }

    cout << room_count << "\n";
    for (int i = 0; i < n; ++i) cout << result[i] << " ";
    cout << "\n";

    return 0;
}
