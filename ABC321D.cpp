#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,p;
	cin>>n>>m>>p;
	ll arr[n],brr[m];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	sort(arr,arr+n);
	sort(brr,brr+m,greater<ll>());
	ll suf[m+1] = {};
	for(int i = m-1;i>=0;i--){
		suf[i] = suf[i+1]+brr[i];
	}
	ll ans = 0;
	int pt = 0;
	for(int i = 0;i<n;i++){
		while(pt<m&&arr[i]+brr[pt]>=p)pt++;
		ans += p*pt+arr[i]*(m-pt)+suf[pt];
	}
	cout<<ans;
}
