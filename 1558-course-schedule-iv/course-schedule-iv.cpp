class Solution {
    #define INT_MAX 10000
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> dist(numCourses,vector<int>(numCourses,INT_MAX));
        for(int i=0;i<numCourses;i++)
            dist[i][i] = 0; // No self loop

            unordered_map<int,vector<int>> adj;
            for(auto edge : prerequisites){
                adj[edge[0]].push_back(edge[1]);
                dist[edge[0]][edge[1]] = 1;
            }

            for(int k=0;k<numCourses;k++){ // Included each vertex 1 by1
                for(int i=0;i<numCourses;i++){
                    for(int j=0;j<numCourses;j++){
                        if(dist[i][j] > dist[i][k]+dist[k][j])
                            dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }

            }

            vector<bool> ans;
            for(auto query: queries){
                if(dist[query[0]][query[1]]<INT_MAX)  ans.push_back(true);
                else                                  ans.push_back(false);
            }
            return ans;
        }
};


// TC = O(N³+Q)
// SC = O(N²)