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
	ll n;
	cin>>n;
	ll arr[n];
	ll total = 0;
	for(auto &i:arr){
		cin>>i;
		total += i;
	}
	if(abs(total)&1){
		cout<<"-1\n";
		return;
	}
	int tar = 1;
	if(total<0)tar = -1;
	vector<pii> ans;
	for(int i = 0;i<n-1;i++){
		if(total == 0){
			ans.push_back({i,i});
			continue;
		}
		if(arr[i] == 0&&arr[i+1] == tar){
			total -= tar*2;
			ans.push_back({i,i+1});
			i++;
		}
		else if(arr[i] == tar&&arr[i+1] == tar){
			total -= 2*tar;
			ans.push_back({i,i+1});
			i++;
		}
		else ans.push_back({i,i});
	}
	if(ans.empty()||ans.back().sc != n-1)ans.push_back({n-1,n-1});
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

