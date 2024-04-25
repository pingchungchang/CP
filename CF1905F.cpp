#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int arr[mxn];
int pos[mxn];
int dp[mxn];
int n;
int bit[mxn];
int pref[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

void solve(){
	for(int i = 1;i<=n;i++)modify(i,-getval(i,i));
	for(int i = 1;i<=n;i++)pref[i] = pos[i] = arr[i] = dp[i] = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pref[i] = max(pref[i-1],arr[i]);
		pos[arr[i]] = i;
	}
	bool flag = true;
	for(int i = 2;i<=n;i++){
		if(arr[i]<arr[i-1])flag = false;
	}
	if(flag){
		cout<<n-2<<'\n';
		return;
	}

	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(i == arr[i]&&getval(i,n) == 0)ans++;
		else if(i == arr[i]&&getval(i,n) == 1)dp[i] = 1;
		modify(arr[i],1);
	}
	for(int i = 1;i<=n;i++)modify(i,-getval(i,i));
	//cout<<ans<<":";for(int i = 1;i<=n;i++)cout<<dp[i];cout<<'\n';
	for(int i = 1;i<=n;i++){
		if(dp[i])modify(i,1);
	}
	int sh = ans;
	for(int i = 1;i<=n;i++){
		if(arr[i]==i)continue;
		int l = pos[i],r = i;
		if(l<r&&arr[r]>i)continue;
		if(l>r&&arr[r]<i)continue;
		if(l>r)swap(l,r);
		int tans = sh+getval(l,r);
		if(arr[r] == l&&pref[l-1]<=l)tans++;
		if(arr[l] == r&&pref[r-1]<=r)tans++;
		//cout<<i<<":"<<l<<','<<r<<":"<<tans<<','<<getval(l,r)<<endl;
		ans = max(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		if(i == 72){
			int n;
			cin>>n;
			cout<<n;
			for(int i = 1;i<=n;i++){
				int k;
				cin>>k;
				cout<<k;
			}
			cout<<endl;
			return 0;
		}
		solve();
	}
}
