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
	int arr[3] = {};
	cin>>arr[0]>>arr[1]>>arr[2];
	cout<<max({0,arr[1]-arr[0]+1,arr[2]-arr[0]+1})<<' '<<max({0,arr[0]-arr[1]+1,arr[2]-arr[1]+1})<<' '<<max({0,arr[1]-arr[2]+1,arr[0]-arr[2]+1});
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

