#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> event;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        event.push_back({a, 1, i});
        event.push_back({b, 2, i});
    }

    sort(event.begin(), event.end());

    vector<int> rooms;
    int count = 0;
    vector<int> ch(n+1);

    for (vector<int> i : event) {
        if (i[1]==1) {
            if (rooms.empty()) {
                count++;
                rooms.push_back(count);
            }
            ch[i[2]] = rooms.back();
            rooms.pop_back();
        }
        if (i[1]==2) {
            rooms.push_back(ch[i[2]]);
        }
    }

    cout << count << "\n";
    for (int i=1; i<=n; i++) {
        cout << ch[i] << " ";
    }
    cout << endl;
}