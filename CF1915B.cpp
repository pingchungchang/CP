#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s[3];
	for(auto &i:s)cin>>i;
	int cnt[3] = {};
	for(auto &i:s){
		for(auto &j:i)if(j != '?')cnt[j-'A']++;
	}
	for(int i = 0;i<3;i++)if(cnt[i] != 3)cout<<(char)('A'+i)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
