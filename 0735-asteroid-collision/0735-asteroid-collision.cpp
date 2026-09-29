class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            int k = 0;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if(abs(asteroids[i]) > abs(st.top())) {
                    st.pop();
                }
                else if(abs(asteroids[i]) == abs(st.top())) {
                    k = 1;
                    st.pop();
                    break;
                }
                else {
                    k = 1;
                    break;
                }
            }
            if(k == 0)
                st.push(asteroids[i]);
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};