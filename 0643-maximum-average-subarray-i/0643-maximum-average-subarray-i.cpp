class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = k - 1;
        double sum = 0;

        for (int i = 0; i < k; i++)
            sum += nums[i];

        double maxsum = sum;

        while (r < n - 1) {
            sum -= nums[l];
            l++;
            r++;
            sum += nums[r];

            maxsum = max(maxsum, sum);
        }

        return maxsum / k;
    }
};