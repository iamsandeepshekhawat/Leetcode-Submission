class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<unsigned long long> rem(60);
        for(int ele : time)
        rem[ele%60]+=1;

        int count=0;
        count+=((rem[0]-1)*rem[0])/2;
        count+=((rem[30]-1)*rem[30])/2;
        for(int i=1;i<=29;i++)
        count+=rem[i]*rem[60-i];

        return count;

    }
};