#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
ll a,b;
bitset<mxn> isp;
vector<ll> primes;

void solve(){
	if(a>b)swap(a,b);
	ll tmp = 1;
	for(int i = b;i>a;i--)tmp *= i;
	tmp++;
	auto p = upper_bound(primes.begin(),primes.end(),a)-primes.begin();
	ll ans = p;
	for(int i = 0;i<primes.size();i++){
		if(tmp%primes[i] == 0){
			if(i>=p)ans++;
			while(tmp%primes[i] == 0)tmp/=primes[i];
		}
	}
	if(tmp>1)ans++;
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	while(cin>>a>>b)solve();
}
