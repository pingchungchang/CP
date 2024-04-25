#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 3e5+10;
const ll mod = 998244353;
ll fac[mxn*2],ifac[mxn*2],cat[mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> arr[n+2];
	arr[1].push_back(1);
	arr[n+1].push_back(-1);
	for(int i = 0;i<k;i++){
		int l,r;
		cin>>l>>r;
		arr[l].push_back(i+2);
		arr[r+1].push_back(-i-2);
	}
	set<pll> st;
	int pt = 0;
	map<int,int> mp;
	map<pll,ll> cnt;
	for(int i = 1;i<=n;i++){
		while(!arr[i].empty()){
			if(arr[i].back()>0){
				if(mp.find(arr[i].back()) == mp.end())mp[arr[i].back()] = ++pt;
				st.insert({mp[arr[i].back()],arr[i].back()});
			}
			else{
				st.erase({mp[-arr[i].back()],-arr[i].back()});
			}
			arr[i].pop_back();
		}
		cnt[make_pair(st.rbegin()->sc,st.size())]++;
	}
	ll ans = 1;
	for(auto &i:cnt){
		if(i.sc&1){
			cout<<"0\n";
			return;
		}
		ans = ans*cat[i.sc>>1]%mod;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn*2;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	cat[0] = 1;
	for(int i = 1;i<mxn;i++)cat[i] = inv(i+1)*fac[i*2]%mod*ifac[i]%mod*ifac[i]%mod;
	int t;cin>>t;
	while(t--)solve();
}
