#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e6+10;
vector<ll> primes;
bitset<mxn> isp;

void solve(){
	ll n;
	cin>>n;
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	ll ans = 0;
	for(int i = 0;i<primes.size()&&primes[i]*primes[i]<n;i++){
		for(int j = i+2;j<primes.size()&&primes[i]*primes[j]*primes[i]*primes[j]<n;j++){
			ll rest = n/(primes[i]*primes[i]*primes[j]*primes[j]);
			int pos = upper_bound(primes.begin(),primes.end(),rest)-primes.begin();
			pos--;
			pos = min(pos,j-1);
			ans += max(0,pos-i);
			//cout<<primes[i]<<' '<<primes[j]<<' '<<i<<' '<<j<<' '<<pos<<endl;
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
