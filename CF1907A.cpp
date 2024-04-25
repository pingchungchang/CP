#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

void solve(){
	pii pos;
	string s;
	cin>>s;
	pos = make_pair(s[0]-'a'+1,s[1]-'0');
	vector<pii> ans;
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			if(i == pos.fs&&j == pos.sc)continue;
			if(i == pos.fs||j == pos.sc)ans.push_back(make_pair(i,j));
		}
	}
	for(auto &i:ans){
		char c = 'a'+i.fs-1;
		cout<<c<<i.sc<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
