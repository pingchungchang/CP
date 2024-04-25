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
	ll a,b;
	cin>>a>>b;
	string s;
	cin>>s;
	ll dist = 0;
	char pre = '0';
	ll ans = 0;
	bool flag = true;
	for(auto &i:s){
		if(i == '1'){
			if(flag){
				ans += a;
				flag = false;
			}
			else if(pre == '0'){
				ans += min(dist*b,a);
			}
			dist = 0;
		}
		else{
			dist++;
		}
		pre = i;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

