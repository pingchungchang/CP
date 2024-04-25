#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll inf = 1e18;

vector<ll> calc(ll a,ll b,ll d,ll n){
	vector<ll> re;
	for(ll i = b;i>=a;i-=d)re.push_back(i);
	while(re.size()<n&&re.back()-d>0){
		re.push_back(re.back()-d);
	}
	sort(re.begin(),re.end());
	while(re.size()<n)re.push_back(re.back()+d);
	sort(re.rbegin(),re.rend());
	return re.size()>n?vector<ll>(1,inf):re;
}

void solve(){
	ll n,x,y;
	cin>>n>>x>>y;
	vector<ll> ans = {(ll)1e18};
	for(int i = 1;i<=y-x;i++){
		if((y-x)%i == 0){
			ans = min(ans,calc(x,y,i,n));
		}
	}
	for(auto &i:ans)cout<<i<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
