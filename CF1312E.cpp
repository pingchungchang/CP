#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 505;
int arr[mxn];
int N;
int dp[mxn];
vector<pii> op[mxn];

int f(int l,int r){
	int cnt[1010] = {};
	for(int i = l;i<=r;i++)cnt[arr[i]]++;
	int re = -1;
	for(int i = 0;i<1009;i++){
		if(cnt[i]&1){
			if(re != -1)return mxn;
			re = i;
		}
		cnt[i+1] += cnt[i]>>1;
	}
	vector<int> v;
	v.push_back(re);
	for(int i = l;i<=r;i++){
		while(v.back()>arr[i]){
			int tmp = v.back();v.pop_back();
			v.push_back(tmp-1);v.push_back(tmp-1);
		}
		if(v.back()<arr[i])return mxn;
		v.pop_back();
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	for(int i = 1;i<=N;i++){
		for(int j = i+1;j<=N;j++){
			if(f(i,j)==1)op[j].push_back(pii(i,1));
		}
	}
	for(int i = 1;i<=N;i++){
		dp[i] = dp[i-1]+1;
		for(auto &j:op[i]){
			dp[i] = min(dp[i],dp[j.fs-1]+j.sc);
		}
	}
	cout<<dp[N];
}
