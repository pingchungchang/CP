#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;
const int mxn = 1e5+10;
bitset<mxn> done;
vector<int> v;
int n;
string s;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll pw(ll a,ll b){
	a %= mod;
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

ll calc(ll k){
	int cnt[k] = {};
	for(int i = 0;i<n;i++){
		if(s[i] == '.')cnt[i%k]=1;
	}
	ll re = 1;
	for(auto &i:cnt)if(!i)re = mad(re,re);
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>s;
	vector<int> primes;
	bool flag = true;
	int nn = n;
	while(flag){
		flag = false;
		for(int i = 2;i*i<=nn;i++){
			if(nn %i == 0){
				primes.push_back(i);
				nn/=i;
				flag = true;
				break;
			}
		}
	}
	if(nn != 1)primes.push_back(nn);
	sort(primes.begin(),primes.end());
	primes.resize(unique(primes.begin(),primes.end())-primes.begin());
	ll ans = 1;
	for(auto &i:primes){
		if(i != n)ans = mad(ans,mad(calc(n/i),mod-1));
	}
	cout<<ans;
}
