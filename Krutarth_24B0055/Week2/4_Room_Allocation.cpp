#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers(n);
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        customers[i] = {a, b, i};
    }

    sort(customers.begin(), customers.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> room_assignment(n);
    int room_count = 0;

    for(auto [arr, dep, idx] : customers){
        if (!pq.empty() && pq.top().first < arr){
            int room = pq.top().second;
            pq.pop();
            room_assignment[idx] = room;
            pq.push({dep, room});
        } else {
            int room = ++room_count;
            room_assignment[idx] = room;
            pq.push({dep, room});
        }
    }

    cout << room_count << '\n';
    for(int i=0; i<n; ++i){
        cout << room_assignment[i] << " \n"[i == n - 1];
    }
}
