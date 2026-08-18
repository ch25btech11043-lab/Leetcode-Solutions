class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        while(i<nums.size()-1){
            if(((nums[i]^nums[i-1]) == 0)&&((nums[i]^nums[i+1]) == 0)) i+=3;
            else{
                if((nums[i]^nums[i-1])==0) return nums[i+1];
                else return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};