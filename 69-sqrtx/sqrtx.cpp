class Solution {
public:
    int mySqrt(int x) {
        long long y = 0;
        while(y*y<=x) y = y+1;
        return y-1;
    }
};

// TC = O(√x)
// SC = O(1)