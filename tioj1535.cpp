#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e7;
vector<int> primes,emirp;
bitset<mxn*2> isp;

inline bool check(int k){
	for(int i = 0;1LL*primes[i]*primes[i]<=k;i++){
		if(k%primes[i] == 0)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn*2;i++){
		if(!isp[i]){
			if(i<mxn)primes.push_back(i);
			for(int j = i+i;j<mxn*2;j+=i)isp[j] = true;
		}
	}
	isp.flip();
	for(auto i:primes){
		int re = 0;
		int p = i;
		while(i){
			re *= 10;
			re += i%10;
			i/=10;
		}
		if(re == p)continue;
		if(isp[re])emirp.push_back(p);
	}
	int C = 20000;
	vector<int> big;
	for(int i = mxn+1;big.size()<C;i++){
		if(isp[i]){
			int tmp = i;
			int re = 0;
			while(tmp){
				re *= 10;
				re += tmp%10;
				tmp/=10;
			}
			if(re != i&&check(re))big.push_back(i);
		}
	}
	int t;cin>>t;
	for(auto &i:big)emirp.push_back(i);
	while(t--){
		int k;
		cin>>k;
		cout<<emirp[k-1]<<'\n';
	}
	return 0;
}
