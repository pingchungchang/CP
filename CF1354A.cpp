#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b>=a){
		cout<<b<<'\n';
		return;
	}
	if(c <= d){
		cout<<"-1\n";
		return;
	}
	cout<<b+(a-b+c-d-1)/(c-d)*c<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
