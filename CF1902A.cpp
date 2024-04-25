#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int c = 0;
	for(auto &i:s)c += (i=='0'?1:-1);
	if(c>0){
		cout<<"YES\n";
		return;
	}
	for(int i = 0;i+1<n;i++){
		if(s[i] != s[i+1]){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
