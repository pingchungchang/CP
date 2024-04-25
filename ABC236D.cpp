#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 16;
int ans = 0;
int n;
int arr[mxn][mxn];

void dfs(int mask,int val = 0){
	if(__builtin_popcount(mask) == n){
		ans = max(ans,val);
		return;
	}
	int re = 0;
	for(int i = 0;i<n;i++){
		if(mask&(1<<i))continue;
		for(int j = i+1;j<n;j++){
			if(mask&(1<<i))continue;
			if(mask&(1<<j))continue;
			dfs(mask^(1<<i)^(1<<j),val^arr[i][j]);
		}
		break;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	n*= 2;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++)cin>>arr[i][j],arr[j][i] = arr[i][j];
	}
	dfs(0);
	cout<<ans;
}
