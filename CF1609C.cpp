#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 1e6+10;
bool primes[mxn] = {};//true:notprime;false:prime
void solve(){
	int n,e;
	cin>>n>>e;
	vector<int> v(n);
	ll ans = 0;
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<e;i++){
		vector<pll> tmp = {{10,1}};
		for(int j = i;j<n;j+=e){
			if(tmp.back().fs != v[j])tmp.push_back(make_pair(v[j],1));
			else tmp.back().sc++;
		}
		tmp.push_back(make_pair(10,1));
		for(int j = 1;j<tmp.size()-1;j++){
			if(tmp[j].fs != 1 && primes[tmp[j].fs] == false){
				ll l = (tmp[j-1].fs == 1?tmp[j-1].sc+1:1LL);
				ll r = (tmp[j+1].fs == 1?tmp[j+1].sc+1:1LL);
				if(tmp[j].sc>1){
					ans += l+r-2+tmp[j].sc;
				}
				else ans += l*r;
			}
		}
//		for(auto i:tmp)cout<<i.fs<<' '<<i.sc<<',';cout<<";;";
	}
	for(int i = 0;i<n;i++){
		if(v[i] != 1&&!primes[v[i]])ans--;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	for(int i = 2;i<mxn;i++){
		if(primes[i])continue;
		for(int j = i*2;j<mxn;j+=i){
			primes[j] = true;
		}
	}
	int t;
	cin>>t;
	while(t--)solve();
}

