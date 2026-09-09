class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    ans.push_back(nums[j]);
                    k=1;
                    break;
                }
            }
            if(k==1) continue;
            for(int l=0;l<i;l++){
                if(nums[l]>nums[i]){
                    ans.push_back(nums[l]);
                    k=1;
                    break;
                }
            }
            if(k==0) ans.push_back(-1);
        }
        return ans;
    }
};