#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define endl '\n'

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(3));
	for(int i = 0;i<n;i++)cin>>v[i][0];
	for(int i = 0;i<n;i++){
		cin>>v[i][1];
		v[i][2] = i;
	}
	sort(v.begin(),v.end());
	int mn = v.back()[1];
	
	string ans(n,'0');
	vector<int> big(n,0);
	big[0] = v[0][1];
	for(int i = 1;i<n;i++)big[i] = max(big[i-1],v[i][1]);
	ans[v.back()[2]] = '1';
	for(int i= n-2;i>=0;i--){
		if(big[i]>=mn)ans[v[i][2]] = '1';
		else break;
		mn = min(mn,v[i][1]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
