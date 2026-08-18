class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bi=0;bi<32;bi++){
            int cnt=0;
            for(int i=0;i<=nums.size()-1;i++){
                if(nums[i]&(1<<bi)) cnt++;
            }
            if(cnt%3==1) ans=ans|(1<<bi);
        }
        return ans;
    }
};