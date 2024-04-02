class Solution {
public:
    vector<int> plusOne(vector<int>& n) {
         for(int i=n.size()-1;i>=0;i--){
            if(n[i]<9){
                n[i]++;
                return n;
            }
            else{
                n[i]=0;
            }
        }
        n.push_back(0);
        n[0]=1;
        return n;
    }
};