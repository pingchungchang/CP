#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
const ll mod = 998244353;

ll N,M;
vector<ll> facs,cnt;
ll arr[mxn];
const ll B = 13;
int dp[1<<B],num[1<<B];
ll pw[mxn];

int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
int mub(int a,int b){
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	cin>>M;
	pw[0] = 1;
	for(int i = 1;i<mxn;i++)pw[i] = mad(pw[i-1],pw[i-1]);
	for(int i = 1;i<=N;i++)cin>>arr[i];
	if(M == 1){
		ll C = 0;
		for(int i = 1;i<=N;i++)if(arr[i] == 1)C++;
		cout<<mub(pw[C],1)<<'\n';
		return 0;
	}
	bool flag = true;
	ll tmp = M;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=tmp;i++){
			if(tmp%i == 0){
				cnt.push_back(0);
				facs.push_back(i);
				while(tmp%i == 0)tmp/=i,cnt.back()++;
				flag = true;
				break;
			}
		}
	}
	if(tmp != 1){
		facs.push_back(tmp);
		cnt.push_back(1);
	}
	for(int i = 1;i<=N;i++){
		int mask = 0;
		bool f = true;
		for(int j = 0;j<facs.size();j++){
			int c = 0;
			while(arr[i]%facs[j] == 0)c++,arr[i]/=facs[j];
			if(c>cnt[j])f = false;
			else if(c == cnt[j])mask|=1<<j;
		}
		if(arr[i] != 1)f = false;
		if(f)num[mask]++;
	}
	int mx = 1<<facs.size();
	dp[0] = 1;
	for(int i = 0;i<mx;i++){
		int C = mub(pw[num[i]],1);
		for(int j = mx-1;j>=0;j--){
			dp[i|j] = mad(dp[i|j],1ll*dp[j]*C%mod);
		}
	}
	cout<<dp[mx-1]<<'\n';
}
