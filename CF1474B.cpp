#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e4+10;
vector<int> primes;
int ans[mxn];

void solve(){
	ll d;
	cin>>d;
	cout<<ans[d]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(ans,ans+mxn,mxn*mxn);
	for(int i = 2;i<mxn;i++){
		bool flag = true;
		for(int j = 2;j*j<=i;j++){
			if(i%j == 0){
				flag = false;
				break;
			}
		}
		if(flag)primes.push_back(i);
	}
	for(int i = 0;i<primes.size();i++){
		for(int j = i+1;j<primes.size();j++){
			int d = min(primes[i]-1,primes[j]-primes[i]);
			ans[d] = min(ans[d],primes[i]*primes[j]);
		}
		if(primes[i]<1e3)ans[primes[i]-1] = min(ans[primes[i]-1],primes[i]*primes[i]*primes[i]);
	}
	for(int i = mxn-2;i>=0;i--)ans[i] = min(ans[i],ans[i+1]);
	int t;
	cin>>t;
	while(t--)solve();
}
