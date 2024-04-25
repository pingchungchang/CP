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
int main(){
	io
	int n;
	cin>>n;
	pll arr[n+1];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
	arr[n] = arr[0];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans = ans+arr[i-1].fs*arr[i].sc-arr[i-1].sc*arr[i].fs;
	}
	cout<<abs(ans);
}

