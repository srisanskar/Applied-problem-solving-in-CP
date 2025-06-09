#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> arr(n); // {value, original_index}
    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        arr[i] = {val, i + 1}; // 1-based indexing
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; ++i){
        int required = target - arr[i].first;
        int left = i + 1, right = n - 1;

        while(left < right){
            int sum = arr[left].first + arr[right].first;
            if (sum == required){
                cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << '\n';
                return 0;
            } else if (sum < required){
                ++left;
            } else {
                --right;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
