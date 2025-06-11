class Solution {
public:
    bool canmakebouqets(vector<int>& bloomDay, int m, int k, int day){
         int bouqets=0, flowers=0;
         for(int bloom : bloomDay){
            if(bloom<=day){
                flowers++;
                if(flowers==k){
                    bouqets++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
         }
            return bouqets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalflowers = (long long)m*k;
        if(totalflowers > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans =-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canmakebouqets(bloomDay, m,  k, mid)){
                ans =mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = n1 + n2;
        vector<int> arr(n3);
        for (int i = 0; i < n1; i++) {
            arr[i] = nums1[i];
        }
        for (int i = 0; i < n2; i++) {
            arr[n1 + i] = nums2[i];
        }
        sort(arr.begin(),arr.end());
        if (n3 % 2 == 0) {
            return (arr[n3 / 2 - 1] + arr[n3 / 2]) / 2.0;
        } else {
            return arr[n3 / 2];
        }
    }
};