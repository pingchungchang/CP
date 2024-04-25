#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double

const int mxn = 2e5+10;

pll arr[mxn];
ld pref[mxn];
ld dp[mxn];
deque<pair<int,ld>> dq;
int n,k;
inline ld dist(pll a,pll b){
	return sqrt((a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 0;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1]+dist(arr[i],arr[i-1]);
	}
	dq.push_back(make_pair(0,(ld)0));
	for(int i = 1;i<=n;i++){
		while(i-dq.front().fs>k)dq.pop_front();
		dp[i] = pref[i]+dq.front().sc;
		ld tval = dp[i]+dist(arr[0],arr[i+1])+dist(arr[0],arr[i])-pref[i+1];
		while(!dq.empty()&&dq.back().sc>tval)dq.pop_back();
		dq.push_back(make_pair(i,tval));
	}
	//for(int i = 0;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	cout<<fixed<<setprecision(10)<<dp[n]+dist(arr[0],arr[n]);
}
