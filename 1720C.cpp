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
#define forn(a,b,c) for(int a = b;a<c;a++)
void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	bool flag = false;
	int mn = 4;
	int cnt = 0;
	forn(i,0,n){
		forn(j,0,m){
			if(i != n-1&&v[i][j] == v[i+1][j]&&v[i][j] == '0')flag = true;
			if(j != m-1&&v[i][j] == v[i][j+1]&&v[i][j] == '0')flag = true;
			if(v[i][j] == '1')cnt++;
			if(i != n-1&&j != m-1){
				int tmp = 0;
				forn(k,0,2)forn(l,0,2){
					if(v[i+k][j+l] == '0')tmp++;
				}
				mn = min(mn,3-tmp);
			}
		}
	}
	if(flag)cout<<cnt<<'\n';
	else cout<<cnt-mn+1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

