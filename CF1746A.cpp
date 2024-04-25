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
void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	int cnt = 0;
	for(auto &i:arr){
		cin>>i;
		if(i)cnt++;
	}
	if(cnt == n||(cnt>=1&&k>=1))cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

