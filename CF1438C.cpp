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
#define forn(x,a,b) for(int x = a;x<=b;x++)
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	int tar[n][m];
	forn(i,0,n-1)forn(j,0,m-1)cin>>arr[i][j];
	int now = 1;
	forn(i,0,n-1){
		now = i;
		forn(j,0,m-1){
			if(now&1)tar[i][j] = 1;
			else tar[i][j] = 0;
			now++;
		}
		
	}
	forn(i,0,n-1){
		forn(j,0,m-1){
			if(arr[i][j] %2 != tar[i][j]%2)arr[i][j]++;
		}
	}
	forn(i,0,n-1){
		forn(j,0,m-1){
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

