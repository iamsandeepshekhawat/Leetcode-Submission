class Solution {
    #define pip pair<int,pair<int,int>>

    bool isValid(int& x,int& y,int& m,int& n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n));

        priority_queue<pip,vector<pip>,greater<pip>> minheap;  // Cost,row,col
        minheap.push(make_pair(0,make_pair(0,0)));
        vector<int> dx = {0,0,1,-1}; // Right Left Up Down(RLDU)
        vector<int> dy = {1,-1,0,0};

        while(!minheap.empty()){
            pip curr = minheap.top();
            minheap.pop();

            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            if(visited[x][y]==true) // Already Processed
               continue;
            if(x==m-1 and y==n-1)   // Reached Destination
                return cost;
                visited[x][y] = true;

                for(int i=0;i<4;i++){ // RLDU
                  int newX = x + dx[i];
                  int newY = y + dy[i];
                  if(isValid(newX,newY,m,n) and !visited[newX][newY]){
                    int new_cost = cost;
                    new_cost += (i+1)==grid[x][y]?0:1;
                    minheap.push(make_pair(new_cost,make_pair(newX,newY)));
                  }

                }
            }
            return 0;
        
    }
};

// TC = O(MNLogMN)
// SC = O(MN)