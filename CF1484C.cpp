#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> pos[n+1];
	int ans[m+1] = {};
	int cnt[m+1] = {};
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		cnt[i] = k;
		while(k--){
			int tmp;
			cin>>tmp;
			pos[tmp].push_back(i);
		}
	}
	for(int i = 1;i<=n;i++){
		int num = 0;
		for(auto &j:pos[i]){
			if(ans[j])continue;
			if(cnt[j] == 1&&!ans[j]){
				num++;
				ans[j] = i;
			}
		}
		if(num>(m+1)/2){
			cout<<"NO\n";
			return;
		}
		for(auto &j:pos[i]){
			cnt[j]--;
			if(num == (m+1)/2)continue;
			if(ans[j])continue;
			ans[j] = i;
			num++;
		}
	}
	cout<<"YES\n";
	for(int i = 1;i<=m;i++)cout<<ans[i]<<' ';cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
