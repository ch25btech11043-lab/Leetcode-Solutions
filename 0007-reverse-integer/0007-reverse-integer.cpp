class Solution {
public:
    int reverse(int x) {
        int c = 0;
        long long f = x, d = 0, k = 0, l = x;

        if (x == 0) return 0;

        while (f != 0) {
            c++;
            f /= 10;
        }

        for (int i = 0; i < c; i++) {
            k = l % 10;

            for (int j = 1; j < c - i; j++) {
                k *= 10;
            }

            d += k;

            if (d > INT_MAX || d < INT_MIN)
                return 0;

            l /= 10;
        }

        return (int)d;
    }
};