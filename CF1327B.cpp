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
	vector<int> v[n+1];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			v[i].push_back(tmp);
		}
	}
	bool boy[n+1] = {},girl[n+1] = {};
	for(int i = 1;i<=n;i++){
		for(auto &j:v[i]){
			if(!boy[j]){
				boy[j] = true;
				girl[i] = true;
				break;
			}
		}
	}
	pii p = {0,0};
	for(int i = n;i>=1;i--){
		if(!boy[i])p.sc = i;
		if(!girl[i])p.fs = i;
	}
	if(!p.fs)cout<<"OPTIMAL\n";
	else{
		cout<<"IMPROVE\n"<<p.fs<<' '<<p.sc<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
