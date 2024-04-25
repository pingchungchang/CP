#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	vector<int> pos[26];
	for(int i = 0;i<s.size();i++)pos[s[i]-'a'].push_back(i);
	string ans;
	int now = -1;
	bitset<26> done;
	done.reset();
	for(int i = 0;i<26;i++)if(pos[i].empty())done[i] = true;
	int c = 26-done.count();
	/*
	for(int i = 0;i<26;i++){
		if(pos[i].empty())continue;
		cout<<(char)('a'+i)<<":";for(auto &j:pos[i])cout<<j<<' ';cout<<endl;
	}

   */
	while(c--){
		for(int i = 25;i>=0;i--){
			if(done[i])continue;
			auto pt = *lower_bound(pos[i].begin(),pos[i].end(),now);
			done[i] = true;
			bool flag = true;
			for(int j = 0;j<26;j++){
				if(done[j])continue;
				if(pos[j].back()<pt)flag = false;
			}
			if(flag){
				ans += 'a'+i;
				now = pt;
				break;
			}
			done[i] = false;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
