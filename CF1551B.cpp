#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int cnt[26] = {};
	for(auto &i:s)cnt[i-'a']++;
	int shift = 0,one = 0;
	for(auto i:cnt){
		if(i >= 2)shift++;
		else if(i == 1)one++;
	}
	cout<<shift+one/2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
