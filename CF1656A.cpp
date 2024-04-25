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
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	cout<<min_element(arr,arr+n)-arr+1<<' '<<max_element(arr,arr+n)-arr+1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
/*
if x is odd:k = 2
if x is even
n*(n-1)/2+m*n = x
if n is odd: n*(m+(n-1)/2) = x
if n is even (n/2)*(m*2+n-1) = x
*/
