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
	ll sum = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		sum += k;
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		sum -= k;
	}
	if(sum==0)cout<<"Draw\n";
	else if(sum>0)cout<<"Tsondu\n";
	else cout<<"Tenzing\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
