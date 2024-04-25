#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}

void solve(){
	int n;
	cin>>n;
	int g[2] = {};
	int arr[n];
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		g[i%2] = gcd(k,g[i%2]);
	}
	int flag = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]%g[(i+1)%2] == 0){
//			cout<<g[0]<<' '<<g[1]<<' '<<arr[i]<<'\n';
			flag |= (1<<(i%2));
		}
	}
	if(flag == 3)cout<<"0\n";
	else{
		if((flag&1) != 0)cout<<g[0]<<'\n';
		else cout<<g[1]<<"\n";
	}
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
