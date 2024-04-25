#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int r,p,s;
	cin>>r>>p>>s;
	string ss;
	cin>>ss;
	string ans(n,'#');
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(ss[i] == 'R'&&p != 0){
			p--;
			ans[i] = 'P';
			cnt++;
		}
		else if(ss[i] == 'P'&&s != 0){
			s--;
			ans[i] = 'S';
			cnt++;
		}
		else if(ss[i] == 'S'&&r != 0){
			r--;
			ans[i] = 'R';
			cnt++;
		}
	}
	for(auto &i:ans){
		if(i == '#'){
			if(r)r--,i = 'R';
			else if(p)p--,i = 'P';
			else s--,i = 'S';
		}
	}
	if(cnt>=(n+1)/2)cout<<"YES\n"<<ans<<'\n';
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
