class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        pq.push({1,{0,0}});
        vis[0][0]=1;
        int dr[]={0,-1,-1,-1,0,1,1,1};
        int dc[]={-1,-1,0,+1,+1,+1,0,-1};
        while(!pq.empty()){
            auto need=pq.front();
            int wt=need.first;
            int row=need.second.first;
            int col=need.second.second;
             if(row==n-1 && col==m-1) return wt;
            pq.pop();
            for(int i=0;i<8;i++){
                int new_row=row+dr[i];
                int new_col=col+dc[i];
                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && 
                     !vis[new_row][new_col] &&grid[new_row][new_col]==0){
                        vis[new_row][new_col]=1;
                        pq.push({wt+1,{new_row,new_col}});
                       
                     }
            }

        }
        return -1;
    }
};