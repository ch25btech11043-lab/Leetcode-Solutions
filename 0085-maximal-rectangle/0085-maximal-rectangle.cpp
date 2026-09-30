class Solution {
public:
    int ls(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                ans=max(ans,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            ans=max(ans,heights[element]*(nse-pse-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> prefixsum(n, vector<int>(m));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                prefixsum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,ls(prefixsum[i]));
        }
        return maxArea;
    }
};