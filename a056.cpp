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
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	for(int i = 0;i<n;i++)cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end());
	vector<int> dp(n,1);
	for(int i = 0;i<n;i++){
		for(int j= i-1;j>=0;j--){
			if(v[i].first>v[j].first&&v[i].second>v[j].second){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<*max_element(dp.begin(),dp.end())<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

