#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
int par[mxn];
int deg[mxn],dep[mxn];
queue<int> q;
int ans = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 2;i<=n;i++){
		cin>>par[i];
		deg[par[i]]++;
	}
	for(int i = 1;i<=n;i++){
		if(!deg[i]){
			dep[i] = 1;
			q.push(i);
		}
	}
	while(!q.empty()&&dep[q.front()]<=m){
		auto now = q.front();
		q.pop();
		ans++;
		dep[par[now]] = dep[now]+1;
		deg[par[now]]--;
		if(!deg[par[now]])q.push(par[now]);
	}
	cout<<ans;
}
