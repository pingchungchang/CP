#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll val[] = {1,10,100,1000,10000};

ll calc(string s){
	char big = 'A';
	ll re = 0;
	for(int i = s.size()-1;i>=0;i--){
		if(big<=s[i]){
			re += val[s[i]-'A'];
		}
		else re -= val[s[i]-'A'];
		big = max(big,s[i]);
	}
	//cout<<s<<":"<<re<<'\n';
	return re;
}

void solve(){
	string s;
	cin>>s;
	ll total = 0;
	ll ans = 0;
	char big = 'A';
	int rp[5] = {};
	int lp[5] = {};
	fill(lp,lp+5,s.size()-1);
	for(int i = 0;i<s.size();i++){
		rp[s[i]-'A'] = max(rp[s[i]-'A'],i);
		lp[s[i]-'A'] = min(lp[s[i]-'A'],i);
	}
	ans = calc(s);
	for(int i = 0;i<5;i++){
		string tmp = s;
		for(char j = 'A';j<='E';j++){
			tmp[rp[i]] = j;
			ans = max(ans,calc(tmp));
		}
		tmp = s;
		for(char j = 'A';j<='E';j++){
			tmp[lp[i]] = j;
			ans =max(ans,calc(tmp));
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
