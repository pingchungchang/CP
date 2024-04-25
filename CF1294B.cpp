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
	pii arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	pii now = {0,0};
	sort(arr,arr+n);
	string ans;
	for(auto &i:arr){
		if(now.fs>i.fs||now.sc>i.sc){
			cout<<"NO\n";
			return;
		}
		while(now.fs != i.fs){
			now.fs++;
			ans += 'R';
		}
		while(now.sc != i.sc){
			now.sc++;
			ans += 'U';
		}
	}
	cout<<"YES\n"<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
