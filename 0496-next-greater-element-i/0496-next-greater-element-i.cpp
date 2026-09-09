class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> f(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (st.empty())
                f[i] = -1;
            else
                f[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(f[j]);
                    break;
                }
            }
        }
        return ans;
    }
};