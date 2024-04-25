#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll


void solve(){
	int n,m,h;
	cin>>n>>m>>h;
	vector<tuple<int,int,int>> v;
	for(int i = 0;i<n;i++){
		vector<int> vv(m);
		for(auto &j:vv)cin>>j;
		sort(vv.begin(),vv.end());
		ll cnt = 0,pen = 0,dt = 0;
		for(auto &j:vv){
			dt += j;
			if(dt>h)break;
			pen += dt;
			cnt++;
		}
		v.push_back(make_tuple(-cnt,pen,i));
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++){
		if(get<2>(v[i]) == 0){
			cout<<i+1<<'\n';
			return;
		}
	}
	assert(false);
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
