#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a%= b;
		swap(a,b);
	}
	return a;
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
void solve(){
	int n;
	cin>>n;
	vector<vector<ll>> req(n-1);
	ll v[n];
	memset(v,1,sizeof(v));
	for(int i = 0;i<n;i++){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--;
		
	}
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

