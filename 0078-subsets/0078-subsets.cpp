class Solution {
public:
    void f(vector<int>& nums,vector<int>& curr,vector<vector<int>>& res,int ind){
        if(ind==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        f(nums,curr,res,ind+1);
        curr.pop_back();
        f(nums,curr,res,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        f(nums,curr,res,0);
        return res;
    }
};