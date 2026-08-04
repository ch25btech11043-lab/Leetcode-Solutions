class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0,y=x;
        while(y!=0){
            if(rev > INT_MAX || rev < INT_MIN) return false;
            rev = rev * 10 + y % 10;
            y/=10;
        }
        if(rev==x && x>=0) return true;
        else return false;
    }
};