#include <bits/stdc++.h>


//failed
using namespace std;
#define ll long long
typedef struct node{
	int times;
	int dist;
	vector<pair<int,int>> paths;
	node(){
		times=0;
		dist = -1;
	}	
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	while(cin>>n){
		if(n!=0)cin>>m;
		else return 0;
		vector<node> graph(n,node());
		for(int i =0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			graph[a].paths.push_back(make_pair(b,c));
			graph[b].paths.push_back(make_pair(a,c));
		}
		graph[1].times = 1;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push(make_pair(0,1));
		while(graph[0].dist == -1){
			int val = pq.top().first;
			int pos = pq.top().second;
			pq.pop();
			graph[pos].dist = val;
			for(int i =0;i<graph[pos].paths.size();i++){
				int now = graph[pos].paths[i].first;
				if(graph[now].dist == -1){
					if(graph[now].times == 0)pq.push(make_pair(graph[pos].dist+graph[pos].paths[i].second,now));
					graph[now].times+=graph[pos].times;
				}
			}
		}
		cout<<graph[0].times<<'\n';
	}
}
