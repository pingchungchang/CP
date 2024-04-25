#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<vector<int>> dp,rdp;
int getval(int sx,int sy,int ex,int ey){
	return dp[ex][ey]-dp[sx-1][ey]-dp[ex][sy-1]+dp[sx-1][sy-1];
}

int rgetval(int sx,int sy,int ex,int ey){
	return rdp[ex][ey]-rdp[sx-1][ey]-rdp[ex][sy-1]+rdp[sx-1][sy-1];
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n+1,vector<int>(m+1,0));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			char c;
			cin>>c;
			v[i][j] = '1'-c;
		}
	}
//	cout<<endl;
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++)cout<<v[i][j];cout<<endl;
//	}
	dp = vector<vector<int>> (n+1,vector<int>(m+1,0));
	rdp = dp;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+v[i][j];
	}
	int ans = INT_MAX;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)rdp[i][j] = rdp[i-1][j]+rdp[i][j-1]-rdp[i-1][j-1]+(1-v[i][j]);
	for(int a = 1;a<=n;a++){
		for(int b = a+4;b<=n;b++){
			vector<int> suff(m+1,0);
			suff[m] = getval(a+1,m,b-1,m)+getval(a,1,a,m-1)+getval(b,1,b,m-1)+rgetval(a+1,1,b-1,m-1);
			for(int i = m-1;i>=2;i--){
				suff[i] = min(suff[i+1],getval(a+1,i,b-1,i)+getval(a,1,a,i-1)+getval(b,1,b,i-1)+rgetval(a+1,1,b-1,i-1));
//				cout<<i<<','<<suff[i]<<endl;
			}
			for(int l = 1;l<=m-3;l++){
				ans = min(ans,suff[l+3]-rgetval(a+1,1,b-1,l)-getval(a,1,a,l)-getval(b,1,b,l)+getval(a+1,l,b-1,l));
//				cout<<rgetval(a+1,1,b-1,l)<<' '<<getval(a,1,a,l)<<' '<<getval(b,1,b,l)<<' '<<getval(a+1,l,b-1,l)<<endl;
			}
//			cout<<a<<' '<<b<<' '<<ans<<'\n';
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

