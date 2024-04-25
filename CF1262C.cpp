#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string s;

void change(int l,int r){
	reverse(s.begin()+l,s.begin()+r+1);
	return;
}

void solve(){
	int n,k;
	cin>>n>>k;
	cin>>s;
	s = "#"+s;
	vector<pii> ans;
	k--;
	for(int i = 1;i<=k*2;i++){
		if(i&1){
			if(s[i] == ')'){
				int p = 0;
				for(p = i+1;s[p] != '(';p++);
				ans.push_back({i,p});
				change(i,p);
			}
		}
		else{
			if(s[i] != ')'){
				int p = 0;
				for(p = i+1;s[p] != ')';p++);
				ans.push_back({i,p});
				change(i,p);
			}
		}
	}
	for(int i = k*2+1;i<=n;i++){
		if(s[i] == ')'){
			int p = i+1;
			for(;p<=n&&s[p] == ')';p++);
			if(p<=n){
				ans.push_back({i,p});
				change(i,p);
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
