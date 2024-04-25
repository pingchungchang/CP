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
	if(n%4 != 0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i = 1;i<=n/4;i++){
		cout<<i*6<<' '<<i*6+4<<' ';
	}
	for(int i = 1;i<=n/4;i++){
		cout<<i*6+1<<' '<<i*6+3<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
