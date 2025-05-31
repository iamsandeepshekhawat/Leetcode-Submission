class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0) return false;
        return true;
    }
};

// TC = O(1)
// SC = O(1)