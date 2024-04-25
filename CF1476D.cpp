#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n;
	string s;
	cin>>n>>s;
	ll p1 = 0,p2 = 1;
	ll ans[n+1];
	fill(ans,ans+n+1,1);
	while(p2 <= n&&p1<n){
		while(p2 != n&&s[p2-1] != s[p2])p2++;
		for(int i = p1;i<p2;i++){
			if(s[i] == 'R')ans[i] = max(ans[i],p2-p1+1);
			else ans[i] = max(ans[i],1LL);
		}
		if(s[p2-1] == 'L')ans[p2] = max(ans[p2],p2-p1+1);
		else ans[p2] = max(1LL,ans[p2]);
//		cout<<p1<<' '<<p2<<endl;
		p1 = p2;
		p2++;
	}
	for(int i = n-2;i>=0;i--){
		if(s[i] == s[i+1]){
			if(s.back() == 'L')ans[n] = max(ans[n],(ll)n-i);
			else ans[n] = max(1LL,ans[n]);
			break;
		}
		if(i == 0){
			if(s.back() == 'L')ans[n] = n+1;
			else ans[n] = max(1LL,ans[n]);
		}
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

