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
	int cnt = 0,ans = 0;
	for(auto &i:s){
		if(i == '[')cnt++;
		else if(i == ']'){
			if(cnt>0){
				ans++;
				cnt--;
			}
		}
	}
	cnt = 0;
	for(auto &i:s){
		if(i == '(')cnt++;
		else if(i == ')'){
			if(cnt>0){
				ans++;
				cnt--;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
