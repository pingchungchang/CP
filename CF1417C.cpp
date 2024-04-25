#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> cnt[n+1];
	int arr[n];
	for(int i = 1;i<=n;i++)cnt[i].push_back(-1);
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		cnt[arr[i]].push_back(i);
	}
	for(int i = 1;i<=n;i++)cnt[i].push_back(n);
	vector<pair<int,int>> st;
	int able[n+2] = {};
	fill(able,able+n+2,n+1);
	for(int i = n;i>=1;i--){
		int len = cnt[i][1]-cnt[i][0];
		for(int j = 1;j<cnt[i].size();j++){
			len = max(len,cnt[i][j]-cnt[i][j-1]);
		}
		able[len] = i;
	}
	int pre = able[0];
	for(int i = 1;i<=n;i++){
		pre = min(pre,able[i]);
		if(pre<=n)cout<<pre<<' ';
		else cout<<"-1 ";
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
