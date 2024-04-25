#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<vector<int>> arr;
pii pos[mxn];
int n,m;

int calc(int col){
	int cnt[n] = {};
	for(int i = 0;i<n;i++){
		int tmp = arr[i][col];
		if(pos[tmp].sc == col){
			cnt[(n+i-pos[tmp].fs)%n]++;
		}
	}
	int re = 1e8;
	for(int i = 0;i<n;i++){
		re = min(re,i+n-cnt[i]);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int C = 0;
	for(auto &i:pos)i = {-1,-1};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			pos[++C] = {i,j};
		}
	}
	assert(C == n*m);
	arr = vector<vector<int>>(n,vector<int>(m));
	for(auto &i:arr){
		for(auto &j:i)cin>>j;
	}
	int ans = 0;
	for(int i = 0;i<m;i++)ans += calc(i);
	cout<<ans;
}
