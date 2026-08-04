class Solution {
public:
    void r(vector<int>& nums,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    void RightRotateByK(vector<int>& nums,int k){
        int n=nums.size();
        r(nums,0,n-1);
        r(nums,0,k-1);
        r(nums,k,n-1);
    }
    void LeftRotateByK(vector<int>& nums,int k){
        int n=nums.size();
        r(nums,0,k-1);
        r(nums,k,n-1);
        r(nums,0,n-1);
    }
    int CheckSort(vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) return 0;
        }
        return 1;
    }
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            RightRotateByK(nums,i);
            int k=CheckSort(nums);
            if(k==1) return true;
            else LeftRotateByK(nums,i);
        }
        return false;
    }
};