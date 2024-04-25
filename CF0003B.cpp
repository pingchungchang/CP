#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,cap;
vector<pll> v[2];
int sz[2];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>cap;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a-1].push_back({b,i+1});
		sz[a-1] = v[a-1].size();
	}
	for(auto &i:v)sort(i.begin(),i.end());
	for(auto &i:v)i.push_back({0,0});
	for(auto &i:v)reverse(i.begin(),i.end());
	for(auto &i:v){
		for(int j = 1;j<i.size();j++)i[j].fs += i[j-1].fs;
	}
	pll ans = make_pair(v[0][min(cap,sz[0])].fs,0LL);
	for(int i = 1;i+i<=min(sz[1]*2,cap);i++){
		ll d = cap-i*2;
		d = min(d,sz[0]);
		//cout<<i<<":"<<d<<endl;
		ans = max(ans,make_pair(v[1][i].fs+v[0][d].fs,i));
	}
	cout<<ans.fs<<'\n';
	vector<int> vv;
	for(int i = 1;i<=ans.sc;i++){
		vv.push_back(v[1][i].sc);
	}
	for(int i = 1;i<=min(sz[0],cap-ans.sc*2);i++){
		vv.push_back(v[0][i].sc);
	}
	sort(vv.begin(),vv.end());
	for(auto &i:vv)cout<<i<<' ';
	return 0;
}
