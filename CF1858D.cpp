#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 3030;
ll pdp[mxn][mxn],sdp[mxn][mxn];
int n,k;

void solve(){

	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			pdp[i][j] = sdp[i][j] = 0;
		}
	}

	cin>>n>>k;
	ll ans[n+1];
	memset(ans,0,sizeof(ans));
	string s;
	cin>>s;
	s = "#"+s;
	ll pref[n+1];
	pref[0] = 0;
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+(s[i] == '1');

	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=n;j++){
			pdp[i][j] = pdp[i-1][j];
			int l = 0,r = i;
			while(l != r){
				int mid = (l+r)>>1;
				if(pref[i]-pref[mid]>j)l = mid+1;
				else r = mid;
			}
			pdp[i][j] = max(pdp[i][j],i-l);
		}
	}

	for(int i = n;i>=1;i--){
		for(int j = 0;j<=n;j++){
			sdp[i][j] = sdp[i+1][j];
			int l = i-1,r = n;
			while(l != r){
				int mid = (l+r+1)>>1;
				if(pref[mid]-pref[i-1]>j)r = mid-1;
				else l = mid;
			}
			sdp[i][j] = max(sdp[i][j],l-i+1);
		}
	}

	/*
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=k;j++)cout<<sdp[i][j]<<' ';cout<<endl;
	}
   */

	assert(pdp[n][k] == sdp[1][k]);

	for(ll len = 0;len<=n;len++){
		ll tans = -1;
		for(ll i = len;i<=n;i++){
			if(!i)tans = pdp[n][k];
			else{
				ll d = len-(pref[i]-pref[i-len]);
				d = k-d;
				//cout<<len<<' '<<i<<":"<<d<<endl;
				if(d<0)continue;
				tans = max(tans,pdp[i-len][d]);
				tans = max(tans,sdp[i+1][d]);
			}
		}
		//cout<<len<<":"<<tans<<endl;
		if(tans == -1)continue;
		for(ll i = 1;i<=n;i++){
			ans[i] = max(ans[i],tans*i+len);
		}
	}

	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
