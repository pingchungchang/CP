#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n;
	cin>>n;
	string v[n-2];
	for(auto &i:v)cin>>i;
	bool flag = true;
	string ans = v[0];
	for(int i = 1;i<n-2;i++){
		if(v[i-1][1] != v[i][0]){
			ans += v[i][0];
			flag = false;
		}
		ans += v[i][1];
	}
	if(flag)ans += 'a';
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

