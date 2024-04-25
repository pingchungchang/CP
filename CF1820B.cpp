#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	string s;
	cin>>s;
	s += s;
	int dp = 0,ans = 0;
	for(auto &i:s){
		if(i == '0'){
			dp = 0;
		}
		else{
			dp++;
		}
		ans = max(ans,dp);
	}
	ans = min(ans,(int)s.size()/2);
	if(ans >= s.size()/2){
		cout<<ans*ans<<'\n';
		return;
	}
	int re = 0;
	for(int i = 1;i<=ans;i++){
		re = max(re,i*(ans-i+1));
	}
	cout<<re<<'\n';

	/*
	int len = 0;
	for(auto &i:s){
		if(i == '0')break;
		len++;
	}
	int len2 = 0;
	for(int i =s.size()-1;i>=0;i--){
		if(s[i] == '0')break;
		len2++;
	}
	if(len == s.size()){
		cout<<re<<'\n';
		return;
	}
	re = max(re,(len2+1)*len);
	int sh = 0;
	for(int i = len2;i<s.size();i++){
		if(len2<0)break;
		re = max(re,(len-sh)*i);
		sh++;
		len2--;
	}
	cout<<re<<'\n';
	return;
	*/
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
