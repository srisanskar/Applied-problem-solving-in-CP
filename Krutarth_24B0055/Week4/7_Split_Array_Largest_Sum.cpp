class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = 0;
        for (int num : nums) right += num;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Greedy check: can we split into k or fewer subarrays with max sum ≤ mid?
            int currentSum = 0;
            int splits = 1;
            for (int num : nums) {
                if (currentSum + num > mid) {
                    splits++;
                    currentSum = 0;
                }
                currentSum += num;
            }

            if (splits <= k) {
                right = mid - 1; // Try to minimize further
            } else {
                left = mid + 1;  // Need larger subarray sum
            }
        }

        return left;
    }
};