#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> paths;
int main(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	string s,e;
	cin>>s>>e;
	map<string,pair<int,int>> dist;
	for(auto i:paths){
		dist[i.first] = make_pair(INT_MAX,0);
	}
	dist[s] = make_pair(10,0);
	for(int asd = 0;asd<n;asd++){
		for(auto i:paths){
			string now = i.first;
			pair<int,int> val = dist[now];
			if(val.first == INT_MAX)continue;
			for(auto nxt:i.second){
				pair<int,int> j = dist[nxt];
				if(i.first[0] == nxt[0]){
					dist[nxt] = min(dist[nxt],make_pair(val.first+(val.second+1)/3*5,(val.second+1)%3));
				}
				else dist[nxt]  = min(dist[nxt],make_pair(val.first+5+(val.second+1)/3*5,(val.second+1)%3));
			}
		}
	}
	cout<<dist[e].first<<'\n';
}
