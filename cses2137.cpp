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
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")

const int mxn = 3000;
bitset<3000> arr[mxn];
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		arr[i] = bitset<3000>(s);
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			ll tmp = (arr[i]&arr[j]).count();
			ans += tmp*(tmp-1)/2;
		}
	}
	cout<<ans;
}

