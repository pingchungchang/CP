#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	vector<pair<int,int>> paths;
	int times;
	int dist;
	bool goneto;
	node(){
		times =0;
		goneto = false;
		dist = INT_MAX;
	}
}node;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	while(cin>>n){
		int ans=0;
		if(n==0)return 0;
		cin>>m;
		vector<node> graph(n,node());
		for(int i =0;i<m;i++){
			int s,e,v;
			cin>>s>>e>>v;
			s--;
			e--;
			graph[s].paths.push_back(make_pair(e,v));
			graph[e].paths.push_back(make_pair(s,v));
		}
		graph[1].times=1;
		graph[1].dist =0;
		graph[1].goneto = true;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push(make_pair(0,1));
		while(!pq.empty()){
			int now = pq.top().second;
			int val = pq.top().first;
			pq.pop();
			graph[now].dist = val;
			for(int i = 0;i<graph[now].paths.size();i++){
				int next = graph[now].paths[i].first;
				if(next ==0){
					ans += graph[now].times;
					continue;
				}
				if(graph[next].dist>val){
					graph[next].times+= graph[now].times;
					if(graph[next].goneto == false){
						pq.push(make_pair(val+graph[now].paths[i].second,next));
						graph[next].goneto = true;
					}
				}
			}
			graph[now].times =0;
		}
		cout<<ans<<'\n';
	}
}
