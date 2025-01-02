class Solution {
public:
    int maxScore(string s) {
        int n =s.size();
        int one_count=0;
        for(int i=0;i<n;i++)
            if(s[i]=='1')
                one_count = one_count + 1;

                int zero_count = 0;
                int max_score = 0;
                for(int i=0;i<n-1;i++){
                    if(s[i]=='1')  one_count = one_count- 1;
                    else           zero_count = zero_count + 1;
                    max_score = max(max_score,zero_count + one_count);       
                }

     return max_score;

    }
    
};

// TC=  O(n) 
// SC = O(1)