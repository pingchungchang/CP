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
	string s;
	cin>>s;
	string ans;
	char pre = '0';
	for(auto &i:s){
		if(i == '1'){
			if(pre == '2')ans += '0';
			else ans += '1';
		}
		else{
			if(pre == '1')ans += '0';
			else ans += '1';
		}
		pre = '0'+(ans.back()-'0')+(i-'0');
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
