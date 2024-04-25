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
int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> turns[m+1];
	ll arr[n+1];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>n)continue;
		ll t = 0;
		if(arr[i]<0){
			ll d = abs(arr[i])/i;
			t += d;
			arr[i] += d*i;
			if(arr[i]<0){
				arr[i] += i;
				t++;
			}
		}
		ll now = arr[i];
		while(now<n&&t<=m){
			turns[t].push_back(now);
			now += i;
			t++;
		}
	}
	ll ans[m+1];
	for(int i = 1;i<=m;i++){
		sort(_all(turns[i]));
		turns[i].erase(unique(_all(turns[i])),turns[i].end());
		for(int j = 0;j<=n;j++){
			if(j>=turns[i].size()||turns[i][j] != j){
				ans[i] = j;
				break;
			}
		}
	}
	for(int i = 1;i<=m;i++)cout<<ans[i]<<'\n';
}

