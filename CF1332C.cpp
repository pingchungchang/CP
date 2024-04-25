#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int cnt[(k+1)/2][26] = {};
	for(int i = 0;i<n;i+=k){
		string tmp = s.substr(i,k);
		for(int j = 0;j<k;j++){
			cnt[min(j,k-j-1)][tmp[j]-'a']++;
		}
	}
	int ans = n;
	for(auto &i:cnt)ans -= *max_element(i,i+26);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
