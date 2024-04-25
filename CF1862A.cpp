#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	string arr[n];
	string s = "vika";
	int pt = 0;
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<m;i++){
		if(pt == s.size())break;
		for(int j = 0;j<n;j++){
			if(arr[j][i] == s[pt]){
				pt++;
				break;
			}
		}
	}
	if(pt == s.size())cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
