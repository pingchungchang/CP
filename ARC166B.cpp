#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;

ll N,arr[3];
vector<pll> v[8];

void add(ll now,int id){
	for(int i = 1;i<8;i++){
		ll tar = 1;
		for(int j = 0;j<3;j++)if(i&(1<<j))tar = tar*arr[j]/__gcd(arr[j],tar);
		v[i].push_back(pll((tar+now-1)/tar*tar-now,id));
		sort(v[i].begin(),v[i].end());
		while(v[i].size()>6)v[i].pop_back();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;for(auto &i:arr)cin>>i;
	for(int i = 1;i<=N;i++){
		ll now;
		cin>>now;
		add(now,i);
	}
	vector<tlll> vv;
	for(int i = 1;i<8;i++){
		for(auto &j:v[i]){
			vv.push_back(tlll(j.fs,j.sc,i));
		}
	}
	ll ans = LLONG_MAX;
	for(auto &i:vv){
		if(get<2>(i) == 7)ans = min(ans,get<0>(i));
		for(auto &j:vv){
			if(get<1>(i) == get<1>(j))continue;
			if((get<2>(i)|get<2>(j)) == 7)ans = min(ans,get<0>(i)+get<0>(j));
			for(auto &k:vv){
				if(get<1>(i) == get<1>(k)||get<1>(j) == get<1>(k))continue;
				if((get<2>(i)|get<2>(j)|get<2>(k)) == 7)ans = min(ans,get<0>(i)+get<0>(j)+get<0>(k));
			}
		}
	}
	cout<<ans<<'\n';
}
