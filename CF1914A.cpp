#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int cnt[27] = {};
	int n;
	string s;
	cin>>n>>s;
	for(auto &i:s)cnt[i-'A'+1]++;
	int ans = 0;
	for(int i = 1;i<=26;i++){
		ans += cnt[i]>=i;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
