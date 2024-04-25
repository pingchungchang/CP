#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll mod = 998244353;
const int mxn = 2e5+10;
ll arr[mxn],N,pref[mxn];
ordered_set dp[mxn][3];
ll sh[mxn][3];
//p:+,c:-

ll calc(int s,int e,ll lim){
	if(s>e)return 0;
	pref[s-1] = 0;
	for(int i = s;i<=e;i++)pref[i] = pref[i-1]+arr[i];
	ll re = 0;
	for(int i = s;i<=e;i++){
		dp[i-1][1].swap(dp[i][2]);sh[i][2] = sh[i-1][1]-arr[i];
		dp[i-1][2].swap(dp[i][1]);sh[i][1] = sh[i-1][2]+arr[i];
		if(i != s)dp[i][1].insert(-pref[i-1]+arr[i]-sh[i][1]);
		re += dp[i][1].size()-dp[i][1].order_of_key(lim-sh[i][1]-(pref[e]-pref[i])+1);
	}
	for(int i = s-1;i<=e;i++){
		for(int j = 0;j<3;j++){
			dp[i][j].clear();
			sh[i][j] = 0;
		}
	}
	//cout<<s<<' '<<e<<' '<<lim<<":"<<re<<endl;
	return re;
}

void init(){
	return;
}

void solve(){
	init();
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i],pref[i] = pref[i-1]+arr[i];
	ll ans = calc(1,N,0)+calc(1,N-1,arr[N])+calc(2,N-1,-arr[1]+arr[N])+calc(2,N,-arr[1]);
	pref[0] = 0;
	for(int i = 1;i<=N;i++)pref[i] = pref[i-1]+arr[i];
	for(int i = 1;i<=N;i++){
		ans += (pref[i]>pref[N]-pref[i]);
	}
	cout<<ans%mod<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
