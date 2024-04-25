#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int a,b;
	cin>>a>>b;
	if(b>a)swap(a,b);
	int dx = abs(a-b);
	if(dx>=min(a,b)){
		cout<<min(a,b)<<'\n';
	}
	else{
		int ans = dx;
		a-= dx*2;
		b -= dx;
		ans += a/3*2;
		a%=3,b%=3;
		if(a>=2)ans++;
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
