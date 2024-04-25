#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int p1 = max_element(arr,arr+n)-arr,p2 = min_element(arr,arr+n)-arr;
	if(p1>p2)swap(p1,p2);
	cout<<min({n-(p2-p1)+1,p2+1,n-p1})<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
