#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	if(a<c){
		cout<<"1 ";
	}
	else cout<<"-1 ";
	if(c<a*b)cout<<b<<'\n';
	else cout<<"-1\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
