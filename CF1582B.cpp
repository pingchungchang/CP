#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	map<int,pii> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(mp.size() == 0||mp.rbegin()->sc.fs != k)mp[i] = make_pair(k,1);
		else mp.rbegin()->sc.sc++;
	}
	ll zv = 1;
	ll o = 0;
	for(auto it:mp){
		pii tmp = it.sc;
		if(tmp.fs == 0){
			zv *= (1LL<<tmp.sc);
		}
		if(tmp.fs == 1){
			o+=tmp.sc;
		}
	}
	cout<<zv*o<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

