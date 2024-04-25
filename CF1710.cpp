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
	ll n,m,k;
	cin>>n>>m>>k;
	ll ndp = n,mdp = m;
	vector<pll> v(k);
	for(int i = 0;i<k;i++)cin>>v[i].fs;
	for(auto &i:v){
		i = make_pair(i.fs/n,i.fs/m);
	}
	ll more = 0;
	ll left = m;
	for(auto i:v){
		if(i.fs <= 1)continue;
		more += i.fs-2;
		if(left == 1&&more>0){
			cout<<"YES\n";
			return;
		}
		if(left != 1)left -= i.fs;
		if(left<=0){
			cout<<"YES\n";
			return;
		}
	}
	left = n,more = 0;
	for(auto i:v){
		if(i.sc<=1)continue;
		more += i.sc-2;
		if(left == 1&&more>0){
			cout<<"YES\n";
			return;
		}
		if(left != 1)left -= i.sc;
		if(left<=0){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

