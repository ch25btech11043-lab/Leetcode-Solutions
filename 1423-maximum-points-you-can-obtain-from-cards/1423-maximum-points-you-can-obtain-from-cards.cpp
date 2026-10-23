class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int n=cardPoints.size();
        int l=k-1;
        int r=n-1;
        ans=lsum+rsum;
        for(int j=0;j<k;j++){
            lsum-=cardPoints[l];
            rsum+=cardPoints[r];
            ans=max(ans,lsum+rsum);
            l--;
            r--;
        }
        return ans;
    }
};