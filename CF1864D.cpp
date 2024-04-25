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
	string arr[n];
	for(auto &i:arr)cin>>i,i = "#"+i;
	pll pref[2][n+1];
	for(auto &i:pref)for(auto &j:i)j = {0,0};
	bool roll = 0;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ll val = 0;
		roll ^= 1;
		for(auto &j:pref[roll])j = {0,0};
		for(int j = 0;j<=n;j++){
			val += pref[roll^1][j].fs;
			int c = arr[i][j]-'0';
			if(((val+c)&1)&&j){
				pref[roll][max(0,j-1)].fs++;
				pref[roll][min(n,j+1)].sc--;
				ans++;
			}
			val += pref[roll^1][j].sc;
		}
		for(int j = 0;j<=n;j++){
			if(!j)pref[roll][j].fs += pref[roll^1][j].fs;
			if(j<n)pref[roll][j].fs += pref[roll^1][j+1].fs;
			if(j)pref[roll][j].sc += pref[roll^1][j-1].sc;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
