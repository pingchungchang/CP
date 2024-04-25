#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int r,c,n;
	cin>>r>>c>>n;
	int sum = 0;
	vector<vector<int>> v(r,vector<int>(c,0));
	for(int i = 0;i<r;i++)for(int j = 0;j<c;j++){
		char ddd;
		cin>>ddd;
		if(ddd == 'R'){
			v[i][j] = 1;
			sum++;
		}
	}
	string ssss = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	vector<vector<int>> ans(r,vector<int>(c,-1));
	int t = sum%n;
	sum = (sum+n-1)/n;
	int dir = 1;
	int st = 0;
	int id = 1;
	int val = 0;
	for(int i = 0;i<r;i++){
		for(int j = st;j>=0&&j<c;j+= dir){
			val += v[i][j];
			ans[i][j] = id;
			if(val == sum){
				val = 0;
				if(t == id)sum--;
				id++;
			}
		}
		st = c-1-st;
		dir = -dir;
	}
	for(int i = 0;i<r;i++)for(int j = 0;j<c;j++)if(ans[i][j] > n || ans[i][j] == -1)ans[i][j] = n;
	for(int i = 0;i<r;i++){
		for(int j= 0;j<c;j++){
			cout<<ssss[ans[i][j]-1];
		}
		cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
