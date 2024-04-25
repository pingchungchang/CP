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
int n,t;
int d[1001] = {};
int s[1001] = {};
ld f(ld now){
	ld ans = 0;
	for(int i = 0;i<n;i++)ans += d[i]/(s[i]+now);
	return ans;
}
int main(){
	io
	cin>>n>>t;
	for(int i = 0;i<n;i++){
		cin>>d[i]>>s[i];
	}
	ld l = -*min_element(s,s+n)+0.001,r = 1e9;
	while(r-l>1e-9){
		ld mid = (l+r)/2;
		if(f(mid)>t)l = mid;
		else r = mid;
	}
	cout<<fixed<<setprecision(12)<<l;
}

