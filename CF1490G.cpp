#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<n;i++)arr[i] += arr[i-1];
	deque<pll> dq;
	for(int i = 0;i<n;i++){
		if(!dq.empty()&&dq.back().fs>=arr[i])continue;
		dq.push_back({arr[i],i});
	}
	while(m--){
		ll tar;
		cin>>tar;
		auto it = lower_bound(dq.begin(),dq.end(),make_pair(tar,-1LL));
		if(it == dq.end()&&arr[n-1]<=0){
			cout<<-1<<' ';
			continue;
		}
		else if(it != dq.end()){
			cout<<it->sc<<' ';
			continue;
		}
		ll dt = (tar-dq.back().fs)/arr[n-1];
		ll ans = 0;
		ans += dt*n-1;
		tar -= dt*arr[n-1];
		if(tar>dq.back().fs){
			tar -= arr[n-1];
			ans += n;
		}
		it = lower_bound(dq.begin(),dq.end(),make_pair(tar,-1LL));
		ans += it->sc+1;
		cout<<ans<<' ';
		continue;
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
