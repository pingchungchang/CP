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
	int mod[3] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mod[k%3]++;
	}
	int ans = 0;
	for(int i = 0;i<6;i++){
		int d = max(0,mod[i%3]-n/3);
		ans += d;
		mod[i%3] -= d;
		mod[(i+1)%3] += d;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
