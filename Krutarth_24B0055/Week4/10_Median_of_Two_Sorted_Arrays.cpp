class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;

        int left = 0, right = m;

        // Define min and max values explicitly
        int MIN_INT = numeric_limits<int>::min();
        int MAX_INT = numeric_limits<int>::max();

        while (left <= right) {
            int i = (left + right) / 2;
            int j = totalLeft - i;

            int A_left = (i == 0) ? MIN_INT : nums1[i - 1];
            int A_right = (i == m) ? MAX_INT : nums1[i];
            int B_left = (j == 0) ? MIN_INT : nums2[j - 1];
            int B_right = (j == n) ? MAX_INT : nums2[j];

            if (A_left <= B_right && B_left <= A_right) {
                if ((m + n) % 2 == 0) {
                    return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
                } else {
                    return max(A_left, B_left);
                }
            } else if (A_left > B_right) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return 0.0; // Should never reach here for valid input
    }
};