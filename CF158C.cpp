#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int q;
	cin>>q;
	string now = "/";
	while(q--){
		string cmd;
		cin>>cmd;
		if(cmd == "pwd"){
			cout<<now<<'\n';
		}
		else{
			cin>>cmd;
			if(cmd[0] == '/')now = "/";
			for(auto &i:cmd)if(i == '/')i = ' ';
			stringstream ss(cmd);
			while(ss>>cmd){
				if(cmd == ".."){
					now.pop_back();
					while(now.back() != '/')now.pop_back();
				}
				else{
					now += cmd+"/";
				}
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
