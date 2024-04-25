#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	vector<ll> a(n),b(n);
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++)cin>>b[i];
	ll diff = -1;
	for(int i = 0;i<n;i++){
		diff = max(a[i]-b[i],diff);
	}
	if(diff<0){
		cout<<"NO\n";
		return;
	}
	for(int i = 0;i<n;i++){
		if(max(a[i]-diff,0LL) != b[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

