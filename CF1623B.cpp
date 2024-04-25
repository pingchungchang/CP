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
	int n;
	cin>>n;
	vector<pii> range(n);
	for(int i = 0;i<n;i++)cin>>range[i].fs>>range[i].sc;
	int cnt[n+1] = {};
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<n;j++){
			if(range[j].fs<=i&&range[j].sc>=i)cnt[i]++;
		}
	}
//	for(auto i:cnt)cout<<i<<' ';cout<<'\n';
	int left[n+2] = {};
	left[0] = 1;
	left[n+1] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(cnt[j] == i){
				int l = j,r = j;
				while(left[l] == 0)l--;
				l++;
				while(left[r] == 0)r++;
				r--;
				cout<<l<<' '<<r<<' '<<j<<'\n';
				left[j] = 1;
			}
		}
	}
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

