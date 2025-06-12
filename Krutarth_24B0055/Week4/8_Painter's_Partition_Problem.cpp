class Solution {
    public:
        int minTime(vector<int>& boards, int k) {
            int low = *max_element(boards.begin(), boards.end());
            int high = accumulate(boards.begin(), boards.end(), 0);
            int result = high;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                if (isPossible(boards, k, mid)) {
                    result = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
    
            return result;
        }
    private:
        bool isPossible(const vector<int>& boards, int k, int maxTime) {
            int painters = 1;
            int currentSum = 0;
    
            for (int length : boards) {
                if (length > maxTime) return false;
    
                if (currentSum + length > maxTime) {
                    painters++;
                    currentSum = length;
    
                    if (painters > k) return false;
                }
                else {
                    currentSum += length;
                }
            }
    
            return true;
        }
};