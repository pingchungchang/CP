#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define mp make_pair
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n+1,vector<int>(m+1,INT_MIN));
	pair<int,pii> small = make_pair(INT_MIN,make_pair(0,0));
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++){
		cin>>v[i][j];
		if(small.fs<v[i][j]){
			small = mp(v[i][j],mp(i,j));
		}
	}
	cout<<max(small.sc.fs,n-small.sc.fs+1)*max(small.sc.sc,m-small.sc.sc+1)<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

