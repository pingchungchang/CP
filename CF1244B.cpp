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
	string s;
	cin>>s;
	int ans = n;
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			if(s[i] == '0'||s[j] == '0')continue;
			if(i == j)ans = max(ans,n+1);
			else ans = max(ans,n+2);
			ans = max({ans,(j-i+1)*2,i+(j-i+1)*2,n-j-1+(j-i+1)*2,(i+1)*2,(n-j)*2});
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
