#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int pl = 0,pr = n-1;
	int ans = n;
	int tar = arr[0];
	while(pl<n&&arr[pl] == tar)pl++;
	while(pr>=0&&arr[pr] == tar)pr--;
	ans = min(ans,pr-pl+1);
	pl = 0,pr = n-1;
	tar = arr[n-1];
	while(pl<n&&arr[pl] == tar)pl++;
	while(pr>=0&&arr[pr] == tar)pr--;
	ans = min(ans,pr-pl+1);
	ans = max(ans,0);
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
