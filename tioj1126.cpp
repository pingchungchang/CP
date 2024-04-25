#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string s;

void solve(){
	int n = s.size();
	int ans = 1;
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			string tmp = s.substr(i,j-i+1);
			string ss = tmp;
			reverse(ss.begin(),ss.end());
			if(ss == tmp)ans = max(ans,j-i+1);
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s)solve();
}
