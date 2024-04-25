#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,m,k;
	cin>>n>>k>>m;
	string s;
	cin>>s;
	int b = 0;
	string ans;
	for(auto &i:s){
		b|=1<<(i-'a');
		if(__builtin_popcount(b) == k){
			ans += i;
			b = 0;
		}
	}
	if(ans.size()>=n){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
	for(int i = 0;i<k;i++){
		if(b&(1<<i))continue;
		ans += 'a'+i;
		break;
	}
	while(ans.size()<n)ans += 'a';
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
