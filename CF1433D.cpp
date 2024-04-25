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
	vector<int> v(n+1);
	for(int i = 1;i<=n;i++)cin>>v[i];
	int now = 1;
	for(int i = 1;i<=n;i++){
		if(v[now] != v[i]){
			now = i;
			break;
		}
	}
	if(v[now] == v[1]){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i = 2;i<=n;i++){
		if(v[i] != v[1]){
			cout<<1<<' '<<i<<'\n';
		}
		else cout<<now<<' '<<i<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

