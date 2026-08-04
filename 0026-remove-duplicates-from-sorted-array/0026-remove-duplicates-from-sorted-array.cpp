class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int j=0;
       int n=nums.size();
       if(n<=1) return n;
       for(int i=0;i<n;i++){
        if(i<n-1){
            if(nums[i+1]>nums[i]){
                  nums[j]=nums[i];
                  j++;
            }
        }
        if(i==n-1 && nums[n-1]>=nums[n-2]){
            nums[j]=nums[i];
            j++;
        }
       }
       return j;
    }
};