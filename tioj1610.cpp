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
	int n;
	cin>>n;
	int arr[n],brr[n-1];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	sort(arr,arr+n);
	sort(brr,brr+n-1,greater<int>());
	ll ans = 0;
	ll w = 0;
	for(int i = 0;i<n;i++){
		if(i)ans += w*(brr[i-1]);
		w += arr[i];
	}
	cout<<ans;
}
