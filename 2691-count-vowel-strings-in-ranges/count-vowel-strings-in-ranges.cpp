class Solution {
     bool isVowel(char& c){
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u');
        }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
      int n = words.size();
      vector<int> prefix_sum(n+1,0);

      //Pre-compute prefix sum for count of strings starting and ending with vowel
      for(int i=0;i<n;i++){
        char start = words[i][0];
        char end = words[i].back();
        if(isVowel(start) and isVowel(end))
            prefix_sum[i+1] =  1 + prefix_sum[i];
            else
            prefix_sum[i+1] = prefix_sum[i];
      }

      //Compute each Query
      vector<int>res;
      for(auto query: queries){
        int count =prefix_sum[query[1] + 1] - prefix_sum[query[0]];
        res.push_back(count);
      }
      return res;
    }
};

// TC = O(N+Q)
// SC = O(N)