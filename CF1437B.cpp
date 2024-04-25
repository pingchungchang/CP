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
	cin>>n;
	string s;
	cin>>s;
	int tmp = 0;
	int ans = INT_MAX;
	int now = 1;
	int pre = 0;
	for(auto &i:s){
		if(now == i-'0'){
			pre = 0;
		}
		else{
			if(pre == 0)tmp++;
			pre =  1;
		}
		now ^= 1;
	}
	ans = min(ans,tmp);
	tmp = 0;now = 0;pre= 0;
	for(auto &i:s){
		if(now == i-'0'){
			pre = 0;
		}
		else{
			if(pre == 0)tmp++;
			pre = 1;
		}
		now ^= 1;
	}
	ans = min(ans,tmp);
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

