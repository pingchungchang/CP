#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 0;i<=n;i++){
		int ta = i,tb = n-i;
		if(ta*(ta-1)/2+tb*(tb-1)/2 == k){
			cout<<"YES\n";
			while(ta--)cout<<1<<' ';
			while(tb--)cout<<-1<<' ';
			cout<<'\n';
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
