#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
vector<pii> sz[mxn];
string arr[mxn];
int n;

void solve(){
	for(int i = 0;i<=n+2;i++){
		arr[i].clear();
	}
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int ans = 0;
	for(int s = n;s>=1;s--){
		for(int i = 0;i<n;i++){
			if(ans == s)break;
			for(int j = 0;j<n;j++){
				if(ans == s)break;;
				int C = 0;
				for(auto &k:sz[s]){
					pii tmp = {i+k.fs,j+k.sc};
					if(tmp.fs>=n||tmp.fs<0||tmp.sc>=n||tmp.sc<0)continue;
					if(arr[tmp.fs][tmp.sc] == 'N')C++;
				}
				if(C == sz[s].size()){
					cout<<s<<'\n';
					return;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	for(int i =1;i<mxn;i++){
		for(int j = 0;j<=i+2;j++)sz[i].push_back({j,0});
		for(int j = 0;j<=i+2;j++)sz[i].push_back({j,j});
		for(int j = 0;j<=i+2;j++)sz[i].push_back({j,i+2});
		sort(sz[i].begin(),sz[i].end());
		sz[i].erase(unique(sz[i].begin(),sz[i].end()),sz[i].end());
	}
	int t;cin>>t;
	while(t--)solve();
}
