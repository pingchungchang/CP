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
	int arr[n],brr[n];
	int pos = 0,neg = 0;
	for(auto &i:arr){
		cin>>i;
		if(i>0)pos++;
		else if(i<0)neg++;
	}
	for(auto &i:brr)cin>>i;
	bool flag = true;
	for(int i = n-1;i>0;i--){
		if(arr[i]>0)pos--;
		else if(arr[i]<0)neg--;
		if(arr[i] == brr[i])continue;
		if(brr[i]>arr[i]&&pos == 0)flag = false;
		if(brr[i]<arr[i]&&neg == 0)flag = false;
	}
	if(arr[0] != brr[0])flag = false;
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
