#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dsjset[(int)1e5*2+5];

int root(int now){
	if(dsjset[now] == now)return now;
	dsjset[now] = root(dsjset[now]);
	return dsjset[now];
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<ll,pair<int,int>>> edges(m);
	for(int i =0;i<n;i++)dsjset[i] = i;
	for(int i =0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		edges[i] = make_pair(c,make_pair(a-1,b-1));
	}
	ll ans = 0;
	sort(edges.begin(),edges.end());
	for(int i =0;i<m;i++){
		int a = edges[i].second.first,b = edges[i].second.second;
		int ra = root(a);
//		cout<<'\n';
		int rb = root(b);
//		cout<<"\n\n";
//		cout<<ra<<' '<<rb<<'\n';
		if(ra == rb)continue;
		dsjset[ra] = rb;
		ans += edges[i].first;
	}
	int check = 0;
	for(int i =0;i<n;i++){
		if(dsjset[i] == i)check++;
	}
	if(check >1)cout<<"IMPOSSIBLE";
	else cout<<ans;
}
