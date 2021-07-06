	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int>v;
	    vector<int>vis(V,0);
	    queue<int>q;
	    q.push(0);
	    vis[0]=1;
	    
	    while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        v.push_back(t);
	        
	        for(int i=0;i<adj[t].size();i++){
	            if(vis[adj[t][i]]==0){
	                vis[adj[t][i]]=1;
	                q.push(adj[t][i]);
	            }
	        }
	        
	    }
	    return v;
	}
