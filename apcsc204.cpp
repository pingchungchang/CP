#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n;
	cin>>n;
	vector<vector<ll>>v(n+1);
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	for(ll i = 1;i<=n;i++){
		v[i].push_back(n+1);
	}
	vector<ll> ans(n+10,INT_MAX);
	for(ll i = 1;i<=n;i++){
		ll pre = 0;
		ll gap = 0LL;
		for(auto &j:v[i]){
			gap = max(gap,j-pre);
			pre = j;
		}
		ans[gap] = min(i,ans[gap]);
	}
	for(ll i = 1;i<=n;i++){
		ans[i] = min(ans[i],ans[i-1]);
		if(ans[i] > n)cout<<-1<<' ';
		else cout<<ans[i]<<" ";
	}
	return 0;
}

