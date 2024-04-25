#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	pll now;
	cin>>now.fs>>now.sc;
	for(int i = 1;i<n;i++){
		ll ta,tb;
		cin>>ta>>tb;
		ll d = max((now.fs+ta-1)/ta,(now.sc+tb-1)/tb);
		now.fs = ta*d,now.sc = tb*d;
	}
	cout<<now.fs+now.sc;
}
