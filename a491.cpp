#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	int r,c;
	cin>>r>>c;
	ll v[r+1][c+1];
	memset(v,0,sizeof(v));
	ll total = 0;
	pair<int,int> p = make_pair(1,1);
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			cin>>v[i][j];
			total += (v[i][j])*(j-1+i-1);
			v[i][j] = v[i][j]-v[i-1][j-1]+v[i][j-1]+v[i-1][j];
		}
	}
	ll ans[c+1];
	memset(ans,0,sizeof(ans));
	ll x = total;
	ans[1] = total;
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			if(j== 1&&i != 1){
				ans[j] = ans[j]+v[i-1][c]-(v[r][c]-v[i-1][c]);
			}
			else if(j != 1){
				ans[j] = ans[j-1]+v[r][j-1]-(v[r][c]-v[r][j-1]);
			}
			if(x>ans[j]){
				x = ans[j];
				p = make_pair(i,j);
			}
		}
	}
	cout<<p.first<<' '<<p.second<<'\n'<<x*100<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
