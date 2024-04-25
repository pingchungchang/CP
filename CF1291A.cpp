#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int lst = -1;
	for(int i = 0;i<n;i++){
		if((s[i]-'0')%2 == 1)lst = i;
	}
	int p = -1;
	for(int i = 0;i<lst;i++){
		if((s[i]-'0')&1)p = i;
	}
	if(p != -1&&lst != -1){
		cout<<s[p]<<s[lst]<<'\n';
		return;
	}
	else cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
