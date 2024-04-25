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
const int mxn = 2e5+10;
bitset<mxn> dp;
int main(){
	io
	ll d;
	cin>>d;
	int arr[101] = {};
	for(int i = 0;i<d;i++){
		int k;
		cin>>k;
		arr[k]++;
	}
	for(auto &i:arr)i/=2;
	dp[0] = true;
	for(int i = 0;i<=100;i++){
		while(arr[i]){
			arr[i]--;
			for(int j = mxn;j>=i;j--){
				if(dp[j-i])dp[j] = true;
			}
		}
	}
	int ans =0;
	for(int i = 0;i<mxn;i++){
		if(dp[i])ans++;
	}
	cout<<ans;
}

