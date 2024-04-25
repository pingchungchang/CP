#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll ttttt = 712271227;
const pll mod = make_pair(ttttt,998244353);
const pll p = make_pair(10,10);
const int mxn = 1010;
pll arr[mxn];
string s;
int N;
map<pll,ll> mp;

inline ll mad(ll a,ll b,ll m){
	a+=b;
	return a>=m?a-m:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>s;
		pll now = make_pair(0,0);
		for(auto &j:s){
			now.fs = now.fs*p.fs%mod.fs;
			now.sc = now.sc*p.sc%mod.sc;
			now.fs = mad(now.fs,j-'0',mod.fs);
			now.sc = mad(now.sc,j-'0',mod.sc);
		}
		arr[i] = now;
		mp[now]++;
	}
	ll ans = 0;
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			pll tmp = make_pair(arr[i].fs*arr[j].fs%mod.fs,arr[i].sc*arr[j].sc%mod.sc);
			if(mp.find(tmp) != mp.end())ans += mp[tmp];
		}
	}
	cout<<ans;
}
