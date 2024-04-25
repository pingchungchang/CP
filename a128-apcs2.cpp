#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> dsjset(10010);
int findroot(int a){
	while(a != dsjset[a])a = dsjset[a];
	return a;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)dsjset[i] = i;
	vector<int> v(n+1,10);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(v[a]<v[b]){
			dsjset[a] = b;
			v[b]+= v[a];
		}
		else{
			v[a]+= v[b];
			dsjset[b] = a;
		}
	}
	pii p = make_pair(0,0);
	for(int i = 1;i<=n;i++){
		p = max(p,make_pair(v[i],i));
	}
	vector<int> ans;
	cout<<p.sc<<'\n';
	for(int i = 1;i<=n;i++){
		if(findroot(i) == p.sc)ans.push_back(i);
	}
	for(auto i:ans)cout<<i<<' ';
}

