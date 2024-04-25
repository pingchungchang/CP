#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	string s = to_string(n);
	if(n%25 == 0){
		cout<<"0\n";
		return;
	}
	reverse(s.begin(),s.end());
	vector<vector<int>> check = {{5,2},{0,0},{0,5},{5,7}};
	int ans = s.size();
	for(auto &i:check){
		int p = 0,c = -1;
		for(int j = 0;j<s.size();j++){
			if(p<2&&i[p] == s[j]-'0')c = j,p++;
		}
		if(p == 2){
			ans = min(ans,c-1);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
