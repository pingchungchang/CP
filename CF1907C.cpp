#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int n;
string s;

void solve(){
	cin>>n>>s;
	int cnt[26] = {};
	for(auto &i:s)cnt[i-'a']++;
	int big = *max_element(cnt,cnt+26);
	if(big+big>n)cout<<big-(n-big)<<'\n';
	else cout<<(n&1)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
