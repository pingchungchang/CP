#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int n;
const int mxn = 1e5+10;
int dp[mxn] = {};
int ask(int k){
	if(k>n||k<1)return INT_MAX;
	if(dp[k])return dp[k];
	int re;
	cout<<"? "<<k<<endl;
	cin>>re;
	dp[k] = re;
	return re;
}
int main(){
	io
	cin>>n;
	int l = 1,r = n;
	if(ask(l)<min(ask(l-1),ask(l+1))){
		cout<<"! "<<l<<endl;
		return 0;
	}
	if(ask(r)<min(ask(r+1),ask(r-1))){
		cout<<"! "<<r<<endl;
		return 0;
	}
	while(l != r){
		int mid = (l+r)/2;
		int lll = ask(l),rrr = ask(r),mmm = ask(mid);
		if(ask(mid+1)>ask(mid))r = mid;
		else l = mid+1;
	}
	cout<<"! "<<l<<endl;
	return 0;
}

