#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	vector<ll> ans;
	ans.push_back(n);
	while(n != 1){
		ll p = 1;
		while(n%p == 0)p<<=1;
		while(n<=p||n%p != 0)p>>=1;
		//cout<<n<<' '<<p<<endl;
		ans.push_back(n-p);
		n -= p;
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
