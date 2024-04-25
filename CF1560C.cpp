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
void solve(){
	ll x;
	cin>>x;
	ll tmp = sqrt(x);
	x -= tmp*tmp;
	if(x == 0){
		cout<<tmp<<' '<<1<<'\n';
		return;
	}
	tmp++;
	if(x<=tmp){
		cout<<x<<' '<<tmp<<'\n';
		return;
	}
	else{
		cout<<tmp<<' '<<tmp-(x-tmp)<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

