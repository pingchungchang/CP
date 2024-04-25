#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	string in[n];
	for(auto &i:in)cin>>i;
	string arr[n];
	for(auto &i:arr)i = string(m,'#');
	bool flag = true;
	for(int i = 0;i<n;i++){
		char now = "WR"[i&1];
		for(int j = 0;j<m;j++){
			now = (now == 'W'?'R':'W');
			if(in[i][j] == '.')continue;
			else if(in[i][j] != now)flag = false;
		}
	}
	if(flag){
		cout<<"YES\n";
		for(int i = 0;i<n;i++){
			char now = "WR"[i&1];
			for(int j = 0;j<m;j++){
				now = (now == 'W'?'R':'W');
				cout<<now;
			}
			cout<<'\n';
		}
		return;
	}
	flag = true;
	for(int i = 0;i<n;i++){
		char now = "WR"[(i&1)^1];
		for(int j = 0;j<m;j++){
			now = (now == 'W'?'R':'W');
			if(in[i][j] == '.')continue;
			else if(in[i][j] != now)flag = false;
		}
	}
	if(flag){
		cout<<"YES\n";
		for(int i = 0;i<n;i++){
			char now = "WR"[(i&1)^1];
			for(int j = 0;j<m;j++){
				now = (now == 'W'?'R':'W');
				cout<<now;
			}
			cout<<'\n';
		}
	}
	else{
		cout<<"NO\n";
		return;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
