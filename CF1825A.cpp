#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int n = s.size();
	bool flag = true;
	bool f2 = true;
	for(int i = 0;i<n;i++){
		if(s[i] != s[0])flag = false;
		else if(s[i] != s[n-1-i])f2 = false;
	}
	if(flag){
		cout<<"-1\n";
		return;
	}
	else if(!f2)cout<<n<<'\n';
	else cout<<n-1<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
