#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
vector<int> dag[mxn];
int deg[mxn];
int ans[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		dag[b].push_back(a);
		deg[a]++;
	}
	int C = n;
	priority_queue<int,vector<int>,less<int>> pq;
	for(int i = 1;i<=n;i++)if(!deg[i])pq.push(i);
	while(!pq.empty()){
		auto now = pq.top();
		ans[now] =  C--;
		pq.pop();
		for(auto nxt:dag[now]){
			if(!--deg[nxt]){
				pq.push(nxt);
			}
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
}
