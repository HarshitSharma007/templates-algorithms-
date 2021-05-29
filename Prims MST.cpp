#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long

int min_vertex(int dist[], bool included[],int V)
{  int min = INT_MAX, mx;
    for (int i = 0; i < V; i++)
        if (included[i] == false && dist[i] < min)
            {min = dist[i], mx = i;}
    return mx;
}

int  prims_MST(int V, vector<vector<int>> &graph) {
    int cost=0;
    int  parent [V],dist [V];
    bool included[V];
    for (int i = 0; i < V; i++)
       {
        dist[i] = INT_MAX;
        included[i] = false;
        }
       dist[0] = 0;
       parent[0] = -1;
    for (int x = 0; x <V-1; x++) {
        int u = min_vertex(dist, included,V);
        included[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && included[v] == false && graph[u][v] <dist[v]){
                parent[v] = u;
                dist[v] = graph[u][v];  }
       }
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        for(int i=0;i<V;i++){
          cost+=graph[parent[i]][i];
        }
          cout<<endl;
    return cost;
  }


int main () {
    //adj matrix with values as weights.
 int V ;  
 cun>>V;      
 vector<vector<int>> graph(V, vector<int>(V));  
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) { 
        cin>>x;
     graph[i][j] = x;
            }
        }
    return prims_MST(V,graph);       
    }
