class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int groups = s.size()/k;

        if(groups*k !=s.size()){
            string add(k-s.size()%k,fill);
            s += add;
            groups = groups + 1;
        }
        vector<string>ans;
        for(int i=0;i<groups;i++)
            ans.push_back(s.substr(i*k,k));
        return ans;
        
    }
};

// TC = O(N)
// SC = O(N)