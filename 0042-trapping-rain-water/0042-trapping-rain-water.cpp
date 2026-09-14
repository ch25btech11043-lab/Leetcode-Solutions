class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> prevmaxx(n);
        vector<int> suffmaxx(n);
        int a=height[0];
        int b=height[n-1];
        for(int i=0;i<n;i++){
            a=max(a,height[i]);
            prevmaxx[i]=a;
        }
        for(int i=n-1;i>=0;i--){
            b=max(b,height[i]);
            suffmaxx[i]=b;
        }
        for(int i=1;i<n-1;i++){
            if(height[i]<prevmaxx[i] && height[i]<suffmaxx[i]){
                ans+=min(prevmaxx[i],suffmaxx[i])-height[i];
            }
        }
        return ans;
    }
};