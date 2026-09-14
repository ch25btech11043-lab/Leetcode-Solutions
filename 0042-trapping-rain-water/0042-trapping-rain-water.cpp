class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> suffmaxx(n);
        int prevmaxx=height[0];
        int b=height[n-1];
        for(int i=n-1;i>=0;i--){
            b=max(b,height[i]);
            suffmaxx[i]=b;
        }
        for(int i=1;i<n-1;i++){
            prevmaxx=max(prevmaxx,height[i]);
            if(height[i]<prevmaxx && height[i]<suffmaxx[i]){
                ans+=min(prevmaxx,suffmaxx[i])-height[i];
            }
        }
        return ans;
    }
};