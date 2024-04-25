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
	int n,k;
	cin>>n>>k;
	map<int,int> mp;
	mp[(1<<30)] = -1;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		mp[tmp]++;
	}
	ll s = -1,e = -1;
	pii ans= make_pair(-1,-1);
	for(auto i:mp){
		if(i.sc<k){
			if(ans.sc-ans.fs<=e-s&&e != -1){
				ans = make_pair(s,e);
			}
			s = e = -1;
		}
		else{
			if(i.fs-e!= 1){
				if(ans.sc-ans.fs<=e-s&&e != -1){
					ans = make_pair(s,e);
				}
				s = e= i.fs;
			}
			else{
				e++;
			}
		}
	}
	if(ans.fs == -1)cout<<-1<<'\n';
	else cout<<ans.fs<<' '<<ans.sc<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
/*
8 2
9 9 7 5 8 7 10 7
*/
