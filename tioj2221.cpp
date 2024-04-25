#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll big = 2e9+10;
const ll sh = 3e9+10;
const ll mxn = 1010;
map<pll,ll> mp;
pll arr[mxn];

inline ll dist(pll a,pll b){
	return (a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			pll tmp = {arr[i].fs+arr[j].fs,arr[i].sc+arr[j].sc};
			tmp.fs += big;
			tmp.sc += big;
			mp[make_pair(tmp.fs*sh+tmp.sc,dist(arr[i],arr[j]))]++;
		}
	}
	ll ans = 0;
	for(auto &i:mp)ans += i.sc*(i.sc-1)/2;
	cout<<ans;
}
