#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	vector<ll> ans;
	ll now = 1,total = 1;
	while(total<=n){
		ans.push_back(now);
		now<<=1;
		total += now;
	}
	total -= now;
	ll d = n-total;
	if(d)ans.push_back(d);
	sort(ans.begin(),ans.end());
	ans.erase(lower_bound(ans.begin(),ans.end(),1));
	cout<<ans.size()<<'\n';
	cout<<ans[0]-1<<' ';
	for(int i = 1;i<ans.size();i++){
		cout<<ans[i]-ans[i-1]<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
