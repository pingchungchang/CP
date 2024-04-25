#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

bool check(string &s){
	int cnt = 0;
	for(int i = 0;i<=s.size()-7;i++){
		if(s.substr(i,7)=="abacaba")cnt++;
	}
	return cnt == 1;
}

void solve(){
	int n;
	string s;
	cin>>n>>s;
	string tar = "abacaba";
	for(int i = 0;i<=n-7;i++){
		string tmp =s.substr(i,7);
		for(int j = 0;j<7;j++){
			if(tmp[j] == '?')tmp[j] = tar[j];
		}
		if(tmp != tar)continue;
		string tt = s;
		for(int j = 0;j<7;j++)tt[i+j] = tmp[j];
		for(auto &j:tt)if(j == '?')j = 'z';
		if(check(tt)){
			cout<<"YES\n"<<tt<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
