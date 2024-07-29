class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>adj) 
	{
	    // code here
	    vector<int>end(V,0);
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        for(auto node : adj[i]){
	            end[node]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(end[i]==0){ 
	            ans.push_back(i);
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        for(auto it: adj[node]){
	            if(end[it]!=0){
	                end[it]--;
	                if(end[it]==0){
	                    ans.push_back(it);
	                    q.push(it);
	                }
	                
	            }
	            
	        }
	    }
         reverse(ans.begin(),ans.end());
         if(ans.size()==V)
         return ans;
         return {};
	    
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(int i=0;i< prerequisites.size();i++){
            int u= prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[u].push_back(v);
        }
        return topoSort(numCourses,adj);
    }
};