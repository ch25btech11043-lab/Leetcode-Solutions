class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int l=0;
        int r=0;
        int n=nums.size();
        int zeroes=0;
        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes<=k){
                ans=max(ans,r-l+1);
            }
            else{
                while(zeroes > k) {
                if(nums[l] == 0) zeroes--;
                l++;
                }
            }
            r++;
        }
        return ans;
    }
};