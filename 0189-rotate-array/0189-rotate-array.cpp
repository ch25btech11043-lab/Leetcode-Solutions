class Solution {
public:
    void reverse(vector<int>& nums,int n){
        for(int i=0;i<n/2;i++){
            swap(nums[i],nums[n-i-1]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums,n);
        reverse(nums,k);
        for(int j=0;j<(n-k)/2;j++){
            swap(nums[j+k],nums[n-j-1]);
        }
    }
};