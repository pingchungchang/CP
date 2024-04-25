#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	cin>>s;
	int cnt[2] = {};
	for(auto &i:s)cnt[i-'0']++;
	for(auto &i:s){
		int c = i-'0';
		c^= 1;
		if(!cnt[c]){
			cout<<cnt[0]+cnt[1]<<'\n';
			return;
		}
		cnt[c]--;
	}
	cout<<"0\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
