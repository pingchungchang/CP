#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int pref[mxn][202];
int n;

void solve(){
	for(int i = 0;i<=n;i++)memset(pref[i],0,sizeof(pref[i]));
	cin>>n;
	vector<int> pos[202];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k].push_back(i);
		pref[i][k]++;
		for(int j = 1;j<=200;j++)pref[i][j] += pref[i-1][j];
	}
	int ans = 0;
	for(auto &i:pos)ans = max(ans,(int)i.size());
	for(int i = 1;i<=200;i++){
		if(pos[i].empty())continue;
		for(int j = 1;j<=200;j++){
			if(i == j||pos[j].empty())continue;
			int r = pos[i].size()-1;
			for(int l = 0;l<pos[i].size();l++){
				if(l>r)break;
				while(r>l&&pref[n][j]-pref[pos[i][r]][j]<pref[pos[i][l]][j]){
					ans = max(ans,(r-l+1)+min(pref[n][j]-pref[pos[i][r]][j],pref[pos[i][l]][j])*2);
					r--;
				}
				//cout<<i<<' '<<j<<' '<<l<<' '<<r<<' '<<ans<<' '<<pref[n][j]-pref[pos[i][r]][j]<<pref[pos[i][l]][j]<<endl;
				ans = max(ans,(r-l+1)+min(pref[n][j]-pref[pos[i][r]][j],pref[pos[i][l]][j])*2);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
