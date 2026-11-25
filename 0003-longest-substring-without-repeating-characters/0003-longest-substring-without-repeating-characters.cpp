class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int ans=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]>=l){
                l=max(l,mpp[s[i]]+1);
            }
            int len=i-l+1;
            ans=max(ans,len);
            mpp[s[i]]=i;
        }
        return ans;
    }
};