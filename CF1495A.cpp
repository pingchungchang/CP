#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	vector<ll> x,y;
	for(int i = 0;i<n*2;i++){
		int a,b;
		cin>>a>>b;
		if(a == 0)y.push_back(abs(b));
		else x.push_back(abs(a));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ld ans = 0;
	for(int i = 0;i<n;i++){
		ans += sqrt(x[i]*x[i]+y[i]*y[i]);
	}
	cout<<fixed<<setprecision(15)<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

