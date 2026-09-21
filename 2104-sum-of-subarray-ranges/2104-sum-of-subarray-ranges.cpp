class Solution {
public:
    vector<int> findPGEE(vector<int> arr){
        int n=arr.size();
        vector<int> pgee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]<=arr[i]) st.pop();
            pgee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pgee;
    }
    vector<int> findNGE(vector<int> arr){
        int n=arr.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<arr[i]) st.pop();
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findNSE(vector<int> arr){
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int> arr){
        int n=arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]) st.pop();
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    long long subArrayMax(vector<int> nums){
        int n=nums.size();
        long long total=0;
        vector<int> nge=findNGE(nums);
        vector<int> pgee=findPGEE(nums);
        for(int i=0;i<n;i++){
            int left=i-pgee[i];
            int right=nge[i]-i;
            total+=left*right*1LL*nums[i];
        }
        return total;
    }
    long long subArrayMin(vector<int> nums){
        int n=nums.size();
        long long total=0;
        vector<int> nse=findNSE(nums);
        vector<int> psee=findPSEE(nums);
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total+=left*right*1LL*nums[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums)-subArrayMin(nums);
    }
};