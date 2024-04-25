#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
const ll mxn = 1e5+10;

vector<ll> arr[mxn];

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

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int m;
		cin>>m;
		while(m--){
			int k;
			cin>>k;
			arr[i].push_back(k);
		}
		sort(arr[i].begin(),arr[i].end());
	}

	while(q--){
		int a,b;
		cin>>a>>b;
		ll ans = 0;
		ll sum = 0;
		int pt = 0;
		for(int i = 0;i<arr[a].size();i++){
			while(pt<arr[b].size()&&arr[b][pt]<arr[a][i]){
				sum = mad(sum,arr[b][pt]);
				pt++;
			}
			ans = mad(ans,sum*inv(arr[a][i])%mod);
			//cout<<arr[a][i]<<":"<<pt<<' ';
		}
		cout<<ans*inv(1LL*arr[a].size()*arr[b].size()%mod)%mod<<'\n';
	}
	return 0;

}
