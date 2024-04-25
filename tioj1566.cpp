#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e7+10;
deque<pii> big,small;
ll n,m,d;
vector<pii> ans;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>d;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		while(!big.empty()&&i-big.front().sc>=m)big.pop_front();
		while(!small.empty()&&i-small.front().sc>=m)small.pop_front();
		while(!big.empty()&&big.back().fs<=k)big.pop_back();
		big.push_back({k,i});
		while(!small.empty()&&small.back().fs>=k)small.pop_back();
		small.push_back({k,i});
		if(big.front().fs-small.front().fs == d)ans.push_back({max(0LL,i-m+1),i});
	}
	for(int i = n;i<=n+m-2;i++){
		while(!big.empty()&&i-big.front().sc>=m)big.pop_front();
		while(!small.empty()&&i-small.front().sc>=m)small.pop_front();
		if(big.empty()||small.empty())break;
		if(big.front().fs-small.front().fs == d)ans.push_back({i-m+1,n-1});
	}
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return 0;
}
