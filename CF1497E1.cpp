#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mx1 = sqrt(1e7)+1;
bitset<mx1> isprime;
vector<int> primes;
int num;
void solve(){
	ll n,k;
	cin>>n>>k;
	short dp[primes.size()] = {};
	int ans = 1;
	set<pair<string,int>> st;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		string s;
		for(int j = 0;j<num;j++){
			short cnt = 0;
			while(k%primes[j] == 0){
				cnt^=1;
				k/=primes[j];
			}
			s += '0'+cnt;
			
		}
		if(st.find({s,k}) == st.end()){
			st.insert({s,k});
		}
		else{
			ans++;
			st.clear();
			st.insert({s,k});
		}
	}
	cout<<ans<<'\n';
	
}
int main(){
	io
	for(int i = 2;i<mx1;i++){
		if(!isprime[i]){
			primes.push_back(i);
			for(int j = i;j<mx1;j+= i){
				isprime[j] = true;
			}
		}
	}
	num = primes.size();
	int t;
	cin>>t;
	while(t--)solve();
}

