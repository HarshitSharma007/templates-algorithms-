class Solution 
{
    public:
    vector<int>v;
    
    void dfs(int src,vector<int>&vis,vector<int> adj[]){
        
        vis[src]=1;
        v.push_back(src);
        for(int i=0;i<adj[src].size();i++){
            if(vis[adj[src][i]]==0)
            dfs(adj[src][i],vis,adj);
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{  
	    v.clear();
	    vector<int>vis(V,0);
	    
	    dfs(0,vis,adj);
	    return v;
	}
};
