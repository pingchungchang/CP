#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
const int sq = sqrt(mxn);
ll suf1[mxn][sq],suf2[mxn][sq];
int n,q;
ll arr[mxn];

void solve(){
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<sq;j++)suf1[i][j] = suf2[i][j] = 0;
	}
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int d = 1;d<sq;d++){
		for(int i = n;i>0&&i>n-d;i--){
			ll s = 0;
			for(int j = i;j>0;j-=d){
				s += arr[j];
				suf1[j][d] = s;
				if(j+d<=n)suf1[j][d] += suf1[j+d][d];
				suf2[j][d] = s;
			}
		}
	}
	while(q--){
		ll s,d,k;
		cin>>s>>d>>k;
		ll e = s+d*(k-1);
		if(d>=sq){
			ll ans = 0;
			ll sum = 0;
			for(int i = e;i>=s;i-=d){
				sum += arr[i];
				ans += sum;
			}
			cout<<ans<<' ';
		}
		else{
			if(e+d>n)cout<<suf1[s][d]<<' ';
			else cout<<suf1[s][d]-(suf1[e+d][d]+suf2[e+d][d]*k)<<' ';
		}
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
