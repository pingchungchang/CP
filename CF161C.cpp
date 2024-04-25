#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll ans = 0;
set<pair<pll,pll>> st;

void dfs(pll a,pll b,ll high){
	if(st.find(make_pair(a,b)) != st.end())return;
	if(!high)return;
	if(a.sc<a.fs||b.sc<b.fs)return;
	vector<pll> ta,tb;
	//cout<<a.fs<<' '<<a.sc<<' '<<b.fs<<' '<<b.sc<<' '<<high<<endl;
	ans = max(ans,min(a.sc,b.sc)-max(a.fs,b.fs)+1);
	if(a.fs == a.sc||b.fs == b.sc)return;
	if(a.sc-a.fs+1 == high||b.sc-b.fs+1 == high)return;
	if(a.fs<=high-1&&a.sc>high){
		ta.push_back({a.fs,high-1});
		ta.push_back({1,a.sc^(high)});
	}
	else{
		if(a.fs&high)a.fs ^= high;
		if(a.sc&high)a.sc ^= high;
		ta.push_back(a);
	}
	if(b.fs<=high-1&&b.sc>high){
		tb.push_back({b.fs,high-1});
		tb.push_back({1,b.sc^(high)});
	}
	else{
		if(b.fs&high)b.fs ^= high;
		if(b.sc&high)b.sc ^= high;
		tb.push_back(b);
	}
	if(ta.size() == 2&&tb.size() == 2){
		dfs(ta[0],tb[0],high>>1);
		dfs(ta[1],tb[1],high>>1);
		return;
	}
	for(auto &i:ta){
		for(auto &j:tb)dfs(i,j,high>>1);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pll a,b;
	cin>>a.fs>>a.sc>>b.fs>>b.sc;
	dfs(a,b,1LL<<30);
	cout<<ans;
}
