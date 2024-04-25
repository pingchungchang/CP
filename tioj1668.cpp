#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1LL<<17;
bitset<mxn> isp;
vector<int> primes;

void solve(){
	int L,R;
	cin>>L>>R;
	bool p[R-L+1] = {};
	for(auto &i:primes){
		int s = (L+i-1)/i*i;
		if(s == i)s+=i;
		for(int j = s;j<=R;j+=i){
			p[j-L] = true;
		}
	}
	int ans = 0;
	for(int i = L;i<=R;i++)if(!p[i-L])ans++;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
