class Solution {
public:
    int minimumRecolors(string blocks, int k) {

     int n = blocks.size();
     int black = 0;
     int min_recoloring = INT_MAX;

     for(int i=0;i<n;i++){
        if(blocks[i]=='B') black = black + 1;
        if(i>=k-1){
            min_recoloring = min(k-black,min_recoloring);
            if(blocks[i-k+1]=='B')
                black = black - 1;
        }
     }   

     return min_recoloring;
    }
};

// TC = O(N)
// SC = O(1)