#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 550;
string arr[mxn];
int pref[mxn][mxn];
int n,m;


void solve(){
	for(int i= 0;i<=n+1;i++){
		for(int j = 0;j<=m+1;j++)pref[i][j] = 0;
		arr[i].clear();
	}
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i],arr[i] = "."+arr[i];
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=m;j++)pref[i][j] = pref[i][j-1]+(arr[i][j] == '*');
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == '.')continue;
			for(int l = 0;(l+j)<=m&&(j-l-1)>=0&&i+l<n;l++){
				if(pref[i+l][l+j]-pref[i+l][j-l-1]==l*2+1)ans++;
				else break;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
