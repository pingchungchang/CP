#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i = 1;i<n;i++)cin>>arr[i];
	arr[0] = 1;
	int brr[n];
	for(auto &i:brr)cin>>i;
	sort(arr,arr+n);
	sort(brr,brr+n);
	int ans = n;
	int pt = 0;
	for(auto &i:arr){
		while(pt<n&&i>=brr[pt])pt++;
		if(pt<n&&i<brr[pt])ans--,pt++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
