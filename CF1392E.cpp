#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 25;
ll arr[mxn][mxn];
int n;

void solve(){
	vector<pii> ans;
	pii now = {0,0};
	ll sum;
	cin>>sum;
	for(int i = 0;i<n*2-1;i++){
		ans.push_back(now);
		if(now.fs == n-1)now.sc++;
		else if(now.sc == n-1)now.fs++;
		else if(now.fs&1){
			if(arr[now.fs][now.sc+1]&sum){
				now.sc++;
			}
			else now.fs++;
		}
		else{
			if(arr[now.fs+1][now.sc]&sum)now.fs++;
			else now.sc++;
		}
	}
	for(auto &i:ans){
		cout<<i.fs+1<<' '<<i.sc+1<<endl;
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<mxn;i+=2){
		ll start = 1<<(i-1);
		for(int j = 0;j<mxn;j++){
			arr[i][j] = start;
			start<<=1;
			assert(start<1e16);
		}
	}
	cin>>n;
	/*

   */
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++)cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	int q;
	cin>>q;
	while(q--)solve();
}
