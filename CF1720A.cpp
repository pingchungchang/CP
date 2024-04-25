#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a*d == c*b)cout<<"0\n";
	else if(a*b*c*d == 0)cout<<1<<'\n';
	else if((a*d)%(c*b) == 0||(b*c)%(a*d) == 0)cout<<"1\n";
	else cout<<"2\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

