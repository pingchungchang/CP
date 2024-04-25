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
int n,L;
int arr[mxn],brr[mxn];
ld pref[mxn];

inline bool f(ld k){
	ld big = 0;
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		pref[i] += arr[i]-brr[i]*k;
	}
	ld sm = 0;
	for(int i = L;i<=n;i++){
		sm = min(sm,pref[i-L]);
		if(pref[i]>=sm)return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>L;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	ld l = 0,r = 1e9;
	for(int i = 0;i<=100;i++){
		ld mid = (l+r)/2;
		if(f(mid))l = mid;
		else r = mid;
	}
	cout<<fixed<<setprecision(10)<<l;
}
