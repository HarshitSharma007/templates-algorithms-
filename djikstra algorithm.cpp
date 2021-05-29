#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
vector<pair<int,int> >graph[1000];

int main(){

int n,m,a,b,w;
cin>>n;
cin>>m;
while(m--){
	cin>>a>>b>>w;
	graph[a].push_back({b,w});
	graph[b].push_back({a,w});
	
}
vector<int>dis(n+1,INT_MAX);
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;

pq.push({0,1});
dis[1]=0;
while(!pq.empty()){
	int curr=pq.top().second;
	int curr_d=pq.top().first;
	pq.pop();
	for(pair<int,int>edge : graph[curr]){
		if(curr_d+edge.second<dis[edge.first]){
			dis[edge.first]=curr_d+edge.second;
			pq.push({dis[edge.first],edge.first});
		}
	}
}
for(int i=1;i<=n;i++){
	cout<<dis[i]<<"\n";
}

return 0;}
