#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers; // (arrival, departure, index)
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers.emplace_back(a, b, i);
    }

    sort(customers.begin(), customers.end());

    // (end_time, room_number)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> room_assignments(n);
    int room_count = 0;

    for (auto &[start, end, idx] : customers) {
        if (!pq.empty() && pq.top().first < start) {
            // Reuse room
            auto [_, room] = pq.top(); pq.pop();
            pq.emplace(end, room);
            room_assignments[idx] = room;
        } else {
            // New room
            ++room_count;
            pq.emplace(end, room_count);
            room_assignments[idx] = room_count;
        }
    }

    cout << room_count << '\n';
    for (int room : room_assignments)
        cout << room << " ";
    cout << '\n';

    return 0;
}
