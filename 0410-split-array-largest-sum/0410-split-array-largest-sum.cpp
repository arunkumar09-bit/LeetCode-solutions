class Solution {
public:
    int countparts(vector<int>& nums, int maxsum) {
        int n = nums.size();
        int parts = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= maxsum) {
                sum += nums[i];
            } else {
                parts++;
                sum = nums[i];
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int parts = countparts(nums, mid);
            if (parts > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};