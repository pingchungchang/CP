#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+1] = {},b[n+1] = {};
	int c[m];
	vector<int> col[n+1];
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++){
		cin>>b[i];
		if(a[i] != b[i])col[b[i]].push_back(i);
	}
	for(int i = 0;i<m;i++)cin>>c[i];
	map<int,int> mp;
	for(int i = 1;i<=n;i++){
		mp[b[i]] = i;
	}
	int ans[m] = {};
	vector<int> done;
	for(int i = m-1;i>=0;i--){
		if(done.empty()&&col[c[i]].empty()&&mp.find(c[i]) == mp.end()){
			cout<<"NO\n";
			return;
		}
		else if(!col[c[i]].empty()){
			done.push_back(col[c[i]].back());
			ans[i] = col[c[i]].back();
			a[col[c[i]].back()] = c[i];
			col[c[i]].pop_back();
		}
		else if(!done.empty()){
			ans[i] = done[0];
		}
		else{
			ans[i] = mp[c[i]];
			done.push_back(mp[c[i]]);
		}
	}
	for(auto &i:col){
		if(!i.empty()){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
