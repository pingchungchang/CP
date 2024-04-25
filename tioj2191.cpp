#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll cross(pll a,pll b){
	return (a.fs*b.sc-b.fs*a.sc);
}
bool cmp(pair<pll,ll> &a,pair<pll,ll> &b){
	return cross(a.fs,b.fs)>cross(b.fs,a.fs);
}
int main(){
	ll n;
	cin>>n;
	vector<pair<pll,ll>> tmp(n);
	for(ll i = 0;i<n;i++){
		cin>>tmp[i].fs.fs>>tmp[i].fs.sc>>tmp[i].sc;
		if(tmp[i].fs.fs<0){
			tmp[i].fs.fs = -tmp[i].fs.fs;
			tmp[i].fs.sc = -tmp[i].fs.sc;
		}
		else if(tmp[i].fs.fs == 0)tmp[i].fs.sc = 1;
	}
	sort(tmp.begin(),tmp.end(),cmp);
	vector<pair<pll,ll>> v;
	for(ll i = 0;i<n;i++){
		if(!v.empty()&&cross(v.rbegin()->fs,tmp[i].fs) == 0)v.rbegin()->sc += tmp[i].sc;
		else v.push_back(tmp[i]);
	}
	n = v.size();
	ll pre[n*2];
	memset(pre,0,sizeof(pre));
	for(ll i = 0;i<n;i++)v.push_back(v[i]);
	for(ll i = 1;i<2*n;i++){
		v[i].sc+= v[i-1].sc;
	}
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	ll small[2*n];
	ll ans = 0;
	for(ll i = 0;i<2*n;i++){
		pq.push(make_pair(v[i].sc,i));
		while(i-pq.top().sc>n)pq.pop();
		ans = max(ans,v[i].sc-pq.top().fs);
	}
	cout<<ans;
}

