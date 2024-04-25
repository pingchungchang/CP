#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3030;
pii arr[mxn];
vector<int> all;
int n;
int dp[mxn*2][mxn*2];

void solve(){
	cin>>n;
	all = {0};
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		all.push_back(arr[i].fs);
		all.push_back(arr[i].sc);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 1;i<=n;i++){
		arr[i].fs = lower_bound(all.begin(),all.end(),arr[i].fs)-all.begin();
		arr[i].sc = lower_bound(all.begin(),all.end(),arr[i].sc)-all.begin();
	}
	for(int i = 0;i<=all.size();i++){
		for(int j = 0;j<=all.size();j++)dp[i][j] = 0;
	}
	int ans = 1;
	sort(arr+1,arr+n+1,[&](pii& a,pii& b){
		return a.sc == b.sc?a.fs>b.fs:a.sc<b.sc;
	});
	//for(int i = 1;i<=n;i++)cout<<arr[i].fs<<' '<<arr[i].sc<<',';cout<<'\n';
	int pt = 1;
	vector<pii> pre;
	for(int i = 1;i<=n;i++){
		while(pt<=arr[i].sc){
			for(int j = 0;j<=all.size();j++)dp[j][pt] = dp[j][pt-1];
			pt++;
		}
		dp[arr[i].fs][arr[i].sc] = max(dp[arr[i].fs][arr[i].sc],1);
		int pp = arr[i].sc;
		for(auto &j:pre){
			while(pp >= min(j.fs,arr[i].fs)){
				dp[pp][arr[i].sc] = max(dp[pp][arr[i].sc],dp[pp+1][arr[i].sc]);
				pp--;
			}
			if(j.fs>=arr[i].fs){
				dp[arr[i].fs][arr[i].sc] = 
					max(dp[arr[i].fs][arr[i].sc],1+dp[j.fs][j.sc]+dp[j.sc+1][arr[i].sc]);
			}
			if(j.sc<arr[i].fs){
				dp[j.fs][arr[i].sc] = 
					max(dp[j.fs][arr[i].sc],dp[arr[i].fs][arr[i].sc]+dp[j.fs][arr[i].fs-1]);
			}
		}
		while(pp>=0){
			dp[pp][arr[i].sc] = max(dp[pp][arr[i].sc],dp[pp+1][arr[i].sc]);
			pp--;
		}
		/*
		cout<<i<<" "<<pt<<":";
		for(int j = 0;j<all.size();j++){
			cout<<dp[j][arr[i].sc]<<' ';
		}
		cout<<'\n';
	   */
		for(int j = 0;j<all.size();j++)ans = max(ans,dp[j+1][arr[i].sc]+dp[0][j]);
		pre.push_back(arr[i]);
		sort(pre.rbegin(),pre.rend());
	}
	cout<<ans<<'\n';
	return;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
