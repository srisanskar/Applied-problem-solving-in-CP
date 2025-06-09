#include <bits/stdc++.h>
using namespace std;

bool check(long long time, const vector<long long>& machines, long long t){
    long long produced = 0;
    for(auto k : machines){
        produced += time / k;
        if (produced >= t) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> machines(n);
    for(int i = 0; i < n; ++i){
        cin >> machines[i];
    }

    long long low = 0, high = 1e18, answer = -1;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        if (check(mid, machines, t)){
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
}
