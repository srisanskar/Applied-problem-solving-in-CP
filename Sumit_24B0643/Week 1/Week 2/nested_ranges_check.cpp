#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void res(vector<vector<int>> range) {
    vector<int> test(n+1);
    int pos = 0;

    for (vector<int> r:range) {
        if (pos >= -r[1]) {
            test[r[2]] = 1;
        }
        pos = max(pos, -r[1]);
    }

    for (int i=1; i<=n; i++) {
        cout << test[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    vector<vector<int>> range1;
    vector<vector<int>> range2;

    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        range1.push_back({y, -x, i});
        range2.push_back({x, -y, i});
    }

    sort(range1.begin(), range1.end());
    sort(range2.begin(), range2.end());
    res(range1);
    res(range2);
}