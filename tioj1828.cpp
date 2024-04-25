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
bool f(ll a,ll b,ll c,ll d){
	if(d>=c)return true;
	ld t = (ld)(a)/(c-d)+b;
	if(t*d>10000)return true;
	else return false;
}
const int L = 10000;
void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	if(a == 0&&b == 0){
		cout<<"-1\n";
		return;
	}
	else if(a>10000){
		cout<<"0\n";
		return;
	}
	else if(c == 0){
		if(!a)cout<<"1\n";
		else cout<<"0\n";
	}
    else cout<<(L-a) * (c) / ((c)*b + L) + 1<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

