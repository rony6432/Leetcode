class Solution {
public:
    void Bfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
          queue<int>q;
          q.push(node);
          vis[node]=1;
          while(!q.empty()){
            int newNode=q.front();
            q.pop();
            for(int i=0;i<isConnected[newNode].size();i++){
                if(isConnected[newNode][i]==1 && !vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
          }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        int cityCnt=0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                cityCnt++;
                Bfs(i,isConnected,vis);
            }
        }
        return cityCnt;
    }
};