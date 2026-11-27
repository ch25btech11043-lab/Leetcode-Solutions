class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int l=0;
        int r=0;
        int n=nums.size();
        int zeroes=0;
        queue<int> st;
        while(r<n){
            if(nums[r]==0){
                zeroes++;
                st.push(r);
            }
            if(zeroes<=k){
                ans=max(ans,r-l+1);
            }
            else{
                l=st.front()+1;
                st.pop();
                zeroes--;
            }
            r++;
        }
        return ans;
    }
};