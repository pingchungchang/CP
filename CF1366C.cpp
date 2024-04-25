#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int cnt[n+m][2] = {};
	vector<vector<int>> arr(n,vector<int>(m,0));
	for(auto &i:arr){
		for(auto &j:i)cin>>j;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cnt[i+j][arr[i][j]]++;
		}
	}
	int len = n+m-2;
	int ans = 0;
	//for(int i = 0;i<=len;i++)cout<<cnt[i][0]<<' ';cout<<'\n';
	//for(int i = 0;i<=len;i++)cout<<cnt[i][1]<<' ';cout<<'\n';
	for(int i = 0;i<=len;i++){
		if(i == len-i)continue;
		int sum = cnt[i][0]+cnt[i][1]+cnt[len-i][0]+cnt[len-i][1];
		ans += min(sum-cnt[i][0]-cnt[len-i][0],sum-cnt[i][1]-cnt[len-i][1]);
	}
	ans>>=1;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
