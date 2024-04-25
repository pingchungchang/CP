#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


string tar;
pll dp[2][20];
pll pa[20][20];

ll check(string s){
	for(auto &i:dp)for(auto &j:i)j = {0,0};
	bool roll = 0;
	dp[0][0] = {0,1};
	for(int i = 0;i<s.size();i++){
		roll ^= 1;
		for(auto &j:dp[roll])j = {0,0};
		if(s[i] != '#'){
			for(int j = 0;j<tar.size();j++){
				auto tmp = pa[j][s[i]-'0'];
				dp[roll][tmp.fs].fs += dp[roll^1][j].fs+dp[roll^1][j].sc*tmp.sc;
				dp[roll][tmp.fs].sc += dp[roll^1][j].sc;
			}
		}
		else{
			for(char c = '0';c<='9';c++){
				for(int j = 0;j<tar.size();j++){
					auto tmp = pa[j][c-'0'];
					dp[roll][tmp.fs].fs += dp[roll^1][j].fs+dp[roll^1][j].sc*tmp.sc;
					dp[roll][tmp.fs].sc += dp[roll^1][j].sc;
				}
			}
		}
	}
	ll sum = 0;
	for(auto &j:dp[roll])sum += j.fs;
	//cout<<s<<":"<<sum<<'\n';
	return sum;
}

ll calc(ll x){
	if(x<0)return 0;
	if(!x)return (tar == "0"?1:0);
	string s = to_string(x);
	ll re = 0;
	re += check(s);
	for(int i = s.size()-1;i>=0;i--){
		s[i]--;
		while(s[i]>='0'){
			if(s[0] == '0'){
				s = s.substr(1,s.size()-1);
				break;
			}
			re += check(s);
			s[i]--;
		}
		s[i] = '#';
	}
	re += check("0");
	while(s.size()){
		for(char c = '1';c<='9';c++){
			s[0] = c;
			re += check(s);
		}
		s.pop_back();
	}
	return re;
}

void solve(){
	for(auto &i:pa)for(auto &j:i)j = {0,0};
	ll L,R;
	cin>>tar>>L>>R;
	for(int i = 0;i<tar.size();i++){
		for(int len = 1;len<=min(i+1,(int)tar.size()-1);len++){
			for(char c = '0';c<='9';c++){
				string pre = tar.substr(0,len);
				string now = tar.substr(i-len+1,len-1)+c;
				if(pre == now)pa[i][c-'0'].fs = max(pa[i][c-'0'].fs,len);
			}
		}
	}
	pa[tar.size()-1][tar.back()-'0'].sc = 1;

	/*
	for(int i = 0;i<=tar.size();i++){
		for(int j = 0;j<10;j++){
			cout<<pa[i][j].fs<<','<<pa[i][j].sc<<' ';
		}cout<<endl;
	}cout<<endl;
   */

	cout<<calc(R)-calc(L-1)<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
