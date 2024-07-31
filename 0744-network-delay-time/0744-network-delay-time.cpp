class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({wt,v});
        }
        vector<int>dist(n+1,1e9);
        dist[0]=0;
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dist[it.second]>dist[node]+it.first){
                    dist[it.second]=dist[node]+it.first;
                    pq.push({dist[node]+it.first,it.second});
                }
            }
        }
        int maxi=*max_element(dist.begin(),dist.end());
        if(maxi!=1e9) return maxi;
        return -1;
    }
};