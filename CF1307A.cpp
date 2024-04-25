#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,d;
	cin>>n>>d;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<n;i++){
		int tmp = min(d/i,arr[i]);
		arr[0] += tmp;
		d -= tmp*i;
	}
	cout<<arr[0]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
