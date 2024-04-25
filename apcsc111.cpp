#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define int ll
int n;
int arr[29][29];
vector<int> use;
int ans =0;
void dfs(){
	if(n-use.size()>n*2-use.back()-1)return;
	if(use.back() == n*2-1&&use.size() != n)return;
	if(use.size() == n){
		vector<int> u2;
		int p = 0;
		for(int i = 0;i<n*2;i++){
			if(p != n&&use[p] == i)p++;
			else{
				u2.push_back(i);
			}
		}
		int tmp = 0;
		for(auto i:use){
			for(auto j:u2){
				tmp += arr[i][j];
			}
		}
		ans = max(ans,tmp);
		return;
	}
	for(int i = use.back()+1;i<n*2;i++){
		use.push_back(i);
			if(n-use.size()<=n*2-use.back()-1)dfs();
		use.pop_back();
	}
	return;
}
	main(){
	io
	cin>>n;
	for(int i = 0;i<n*2;i++)for(int j = 0;j<n*2;j++)cin>>arr[i][j];
	use.push_back(0);
	dfs();
	cout<<ans;
}

