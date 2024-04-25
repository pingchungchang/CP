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
	ll a,b,c;
	cin>>a>>b>>c;
	if((a+c)%(b*2) == 0){
		cout<<"YES\n";
	}
	else if((b*2-c) > 0&&(b*2-c)%a == 0){
		cout<<"YES\n";
	}
	else if((b*2-a) > 0&&(b*2-a)%c == 0){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

