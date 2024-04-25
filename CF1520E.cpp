#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;string s;
	cin>>n>>s;
	vector<int> pos;
	for(int i = 0;i<n;i++)if(s[i] == '*')pos.push_back(i);
	ll ans = 0;
	int p = 0;
	for(int i = 0;i<pos.size();i++){
		ans += pos[i]-i;
	}
	ll returns = ans;
	for(int i = 1;i<n;i++){
//		cout<<ans<<' '<<p<<',';
		while(p<pos.size()&&p+i>pos[p])p++;
		ans = ans+p-(pos.size()-p);
		returns = min(returns,ans);
	}
//	cout<<ans<<',';
	cout<<returns<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

