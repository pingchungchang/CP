#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int ans[30][30];
int ans2[30][30];

void solve(){
	memset(ans,0,sizeof(ans));
	memset(ans2,0,sizeof(ans2));
	int n,m,k;
	cin>>n>>m>>k;
	int dist = n-1+m-1;
	if(dist>k||((k-dist)&1)){
		cout<<"NO\n";
		return;
	}
	int r = 0;
	for(int i = 0;i<m-1;i++){
		ans[0][i] = ans[1][i] = r&1;
		r++;
	}
	for(int i = 0;i<n-1;i++){
		ans2[i][m-1] = r&1;
		r++;
	}
	ans2[0][0] = ans2[0][1] = 1;
	ans2[n-2][m-2] = ans2[n-2][m-1]^1;
	ans[n-1][m-2] = ans[n-2][m-2] = ans2[n-2][m-1];
	cout<<"YES\n";
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m-1;j++)cout<<(ans[i][j]?'R':'B')<<' ';
		cout<<'\n';
	}
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<m;j++)cout<<(ans2[i][j]?'R':'B')<<' ';
		cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
