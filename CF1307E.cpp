#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 5050;
const ll mod = 1e9+7;
ll ans = 0,cnt = 0;
short arr[mxn];
short pref[mxn][mxn];
vector<int> v[mxn];
ll N,M;

ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
ll mub(ll a,ll b){
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 1;i<=N;i++)cin>>arr[i],pref[arr[i]][i] = 1;
	for(int i = 1;i<=N;i++)for(int j = 1;j<=N;j++)pref[i][j] += pref[i][j-1];
	for(int i = 1;i<=M;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	for(int i = 1;i<=N;i++)sort(v[i].begin(),v[i].end());
	ans = 0;
	cnt = 1;
	for(int i = 1;i<=N;i++){
		int pt = 0;
		while(pt<v[i].size()&&v[i][pt]<=pref[i][N])pt++;
		if(pt != 0){
			ans++;
			cnt = cnt*pt%mod;
		}
	}
	for(int i = 1;i<=N;i++){
		ll ts = 0,tc = 1;
		for(int j = 1;j<=N;j++){
			ll lp = 0,rp = 0;
			while(lp<v[j].size()&&v[j][lp]<=pref[j][i])lp++;
			while(rp<v[j].size()&&v[j][rp]<=pref[j][N]-pref[j][i])rp++;
			//cerr<<i<<' '<<j<<":"<<lp<<' '<<rp<<endl;
			if(arr[i] == j){
				if(!lp||v[j][lp-1] != pref[j][i]){
					ts = -1;
					break;
				}
				ts++;
				if(rp-(rp>=lp))ts++,tc = tc*(rp-(rp>=lp))%mod;
			}
			else{
				if(lp>=rp)swap(lp,rp);
				if(lp == 1&& rp == 1)ts++,tc = tc*2%mod;
				else if(lp)ts+=2,tc = tc*lp%mod*(rp-1)%mod;
				else if(rp)ts++,tc = tc*rp%mod;
			}
		}
		//cout<<i<<":"<<ts<<' '<<tc<<endl;
		if(ts>ans)ans = ts,cnt = tc;
		else if(ts==ans)cnt = mad(cnt,tc);
	}
	cout<<ans<<' '<<cnt<<'\n';
}
