#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v[k+1];
	for(int i = 1;i<=k;i++){
		v[i].push_back(0);
	}
	for(int i = 1;i<=n;i++){
		int c;
		cin>>c;
		v[c].push_back(i);
	}
	for(int i = 1;i<=k;i++)v[i].push_back(n+1);
	int ans = n;
	for(int i = 1;i<=k;i++){
		vector<int> dif;
		for(int j = 1;j<v[i].size();j++){
			dif.push_back(v[i][j]-v[i][j-1]-1);
		}
		sort(dif.begin(),dif.end());
		int c = (dif.back())/2;
		dif.pop_back();
		dif.push_back(c);
		ans = min(ans,*max_element(dif.begin(),dif.end()));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
