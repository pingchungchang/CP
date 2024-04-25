#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int dif = 0;
	for(int i = 0;i+i<n;i++){
		if(s[i] != s[n-1-i])dif++;
	}
	string ans(n+1,'0');
	if(n&1){
		for(int i = dif;i<=n-dif;i++)ans[i] = '1';
	}
	else{
		for(int i = dif;i<=n-dif;i+=2)ans[i] = '1';
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
