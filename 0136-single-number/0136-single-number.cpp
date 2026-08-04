class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n=nums.size();
       int maxi=0;
       for(int i=0;i<n;i++){
        int d=0;
        for(int j=0;j<n;j++){
            if(i!=j && nums[i]==nums[j]) d=1;
        }
        if(d==0){
            maxi=nums[i];
        } 
       }
       return maxi;
    }
};