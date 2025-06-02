#include<bits/stdc++.h>
using namespace std;
struct Data{
    long long val;
    int idx;
};
bool cmp(const Data& a, const Data& b){
    return a.val<b.val;
}
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<Data>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].val;
        vec[i].idx=i+1;
    }
    sort(vec.begin(),vec.end(),cmp);

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        long long target = x - vec[i].val;
        while (left < right) {
            long long current_sum = vec[left].val + vec[right].val;
            if (current_sum == target) {
                cout << vec[i].idx << " " << vec[left].idx << " " << vec[right].idx << endl;
                return 0;
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}