class Solution {
public:
    int xorOperation(int n, int start) {
        int x=start;
        int y=0;
        for(int i=0;i<n;i++){
            y=y^x;
            x+=2;
        }
        return y;
    }
};