class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
            int n=nums.size();
            vector<int> k;
            k.push_back(0);
            int cnt=0;
            for(int i=0;i<n;i++){
               if(i==n-1 && nums[i]==1){
                    cnt++;
                    k.push_back(cnt);
                }
                if(nums[i]==1 && i!=n-1){
                    cnt++;
                }
                else{
                 k.push_back(cnt);
                 cnt=0;
                }
            }
            int maxi=k[0];
            for(int j=0;j<k.size();j++){
                if(k[j]>maxi) maxi=k[j];
            }
            return maxi;
    }
};