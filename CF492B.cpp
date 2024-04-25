#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
ll n,L;
vector<ll> v;

int main(){
	cin>>n>>L;
	v = vector<ll>(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	ld ans = 0;
	for(int i = 0;i<n;i++){
		if(i == 0)ans = max(ans,(ld)v[i]);
		else{
			ans = max(ans,(ld)(v[i]-v[i-1])/2.0);
		}
	}
	ans = max(ans,(ld)L-v.back());
	cout<<fixed<<setprecision(10)<<ans;
}

