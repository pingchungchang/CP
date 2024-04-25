#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	for(int i = 0;i<n;i++){
		if(a[i] == b[i])continue;
		if(b[n-1-i] == b[i])swap(a[i],b[n-1-i]);
		else swap(b[i],a[n-1-i]);
	}
	if(a == b)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
