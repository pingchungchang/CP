#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll x,y;
	cin>>x>>y;
	set<ll> st;
	while(x<y&&st.find(x) == st.end()){
		st.insert(x);
		if(x%2 == 0)x = x*3/2;
		else x--;
	}
	if(x<y)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
