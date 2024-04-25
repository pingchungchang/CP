#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll N,K,C;
vector<ll> fac;

inline ll f(ll now){
	ll re = 0;
	for(int i = 0;i<(1<<fac.size());i++){
		ll tmp = 1;
		for(int j = 0;j<fac.size();j++)if(i&(1<<j))tmp *= fac[j];
		re += (__builtin_popcount(i)&1?-1ll:1ll)*(now/tmp);
	}
	return re;
}

inline bool check(ll k){
	for(auto &i:fac)if(k%i == 0)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>K>>C;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = (fac.empty()?2:fac.back());i*i<=N;i++){
			if(N%i == 0){
				flag = true;
				fac.push_back(i);
				while(N%i == 0)N/=i;
			}
		}
	}
	if(N != 1)fac.push_back(N);
	ll l = 1,r = 1e18;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid)>=K)r = mid;
		else l = mid+1;
	}
	while(C--){
		while(!check(l))l++;
		cout<<l++<<' ';
	}
	return 0;
}
