#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll bin(string s){
	reverse(s.begin(),s.end());
	ll re = 0;
	ll p = 1;
	for(auto &i:s){
		if(i == '1')re ^= p;
		p<<=1;
	}
	return re;
}

void solve(){
	string s;
	cin>>s;
	ll n;
	cin>>n;
	string ans = s;
	for(auto &i:ans)if(i == '?')i = '0';
	for(int i = 0;i<s.size();i++){
		if(s[i] == '?'){
			ans[i] = '1';
			if(bin(ans)>n)ans[i] = '0';
		}
	}
	if(bin(ans)>n)cout<<-1;
	else cout<<bin(ans);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
