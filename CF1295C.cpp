#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s,t;
	cin>>s>>t;
	vector<int> pos[26];
	int n = s.size();
	for(int i = 0;i<n;i++){
		pos[s[i]-'a'].push_back(i);
	}
	int ans = 1;
	int now = -1;
	for(auto &i:t){
		if(pos[i-'a'].empty()){
			cout<<"-1\n";
			return;
		}
		auto it = upper_bound(pos[i-'a'].begin(),pos[i-'a'].end(),now);
		if(it == pos[i-'a'].end()){
			it = pos[i-'a'].begin();
			ans++;
		}
		now = *it;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
