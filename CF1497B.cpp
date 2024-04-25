#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> mods(m+2,0);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mods[k%m]++;
	}
	int ans =0;
	if(mods[0] != 0)ans++;
	mods[0] = 0;
	if(m%2 == 0){
		if(mods[m/2] != 0)ans++;
		mods[m/2] = 0;
	}
	for(int i = 1;i<m;i++){
		if(mods[i] == mods[m-i]&&mods[i] != 0)ans++;
		else ans += abs(mods[i]-mods[m-i]);
		mods[i] = mods[m-i] = 0;
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

