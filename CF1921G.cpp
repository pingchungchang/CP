#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
string arr[mxn],brr[mxn];
vector<int> pref[mxn];
int n,m,k;
int ans;

void flip_flop(){
	for(int i = 0;i<m;i++){
		brr[i] = string(n,'0');
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++)brr[j][i] = arr[i][j];
	}
	for(int i = 0;i<n;i++)arr[i].clear();
	for(int i = 0;i<m;i++)arr[i] = brr[i];
	for(int i = 0;i<m;i++)brr[i].clear();
	swap(n,m);
	return;
}

int calc(){
	for(int i = 0;i<n;i++){
		pref[i] = vector<int>(m,0);
		for(int j = 0;j<m;j++){
			pref[i][j] = (arr[i][j] == '#');
			if(j>0)pref[i][j] += pref[i][j-1];
		}
	}
	int re = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int ts = 0;
			for(int l = j-k,r = i;r<n&&l<j;l++,r++){
				ts += pref[r][j];
				if(l>=0)ts -= pref[r][l];
			}
			re = max(re,ts);
			ts = 0;
			for(int l = j-k,r = i;r>=0&&l<j;l++,r--){
				ts += pref[r][j];
				if(l>=0)ts -= pref[r][l];
			}
			re = max(re,ts);
		}
	}
	return re;
}

void solve(){
	for(int i = 0;i<=n;i++){
		arr[i].clear();
		pref[i].clear();
	}
	cin>>n>>m>>k;
	k++;
	for(int i = 0;i<n;i++)cin>>arr[i];
	if(n>m){
		flip_flop();
	}
	ans = calc();
	for(int i = 0;i<n;i++){
		for(int j = 0;j+j<m;j++)swap(arr[i][j],arr[i][m-1-j]);
	}
	ans = max(ans,calc());
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
