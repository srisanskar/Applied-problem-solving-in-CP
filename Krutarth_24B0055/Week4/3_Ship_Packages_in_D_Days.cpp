class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        
        // Manually calculate sum instead of using accumulate
        int right = 0;
        for (int w : weights) {
            right += w;
        }

        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int currentLoad = 0, neededDays = 1;
            for (int w : weights) {
                if (currentLoad + w > mid) {
                    neededDays++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }

            if (neededDays <= days) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};