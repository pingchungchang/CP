#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	ll sum = 0;
	ll arr[n];
	for(auto &i:arr)cin>>i,sum+=i;
	sort(arr,arr+n);
	ll d1 = sum/n,d2 = sum/n+1;
	ll c2 = sum-d1*n,c1 = n-c2;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(c1)ans += max(0LL,d1-arr[i]),c1--;
		else ans += max(0LL,d2-arr[i]),c2--;
	}
	cout<<ans;
}
