#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll arr[n*2],brr[n*2];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)cin>>brr[i];
	sort(arr,arr+n);
	sort(brr,brr+n);
	for(int i = n;i<n*2;i++){
		arr[i] = arr[i-n];
		brr[i] = brr[i-n];
	}
	int ans = m;
	for(int i = 0;i<n;i++){
		int d = (brr[i]-arr[0]+m)%m;
		bool flag = true;
		for(int j = 0;j<n;j++){
			if((brr[i+j]-arr[j]+m)%m != d)flag = false;
		}
		//cout<<d<<":"<<flag<<endl;
		if(flag)ans = min(ans,d);
	}
	/*
	for(auto &i:arr)cout<<i<<' ';cout<<endl;
	for(auto &i:brr)cout<<i<<' ';cout<<endl;

   */
	cout<<ans;
}
