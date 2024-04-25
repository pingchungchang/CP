#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int dif[n-1];
	for(int i = 0;i<n-1;i++){
		dif[i] = arr[i+1]-arr[i];
	}
	long long total[2] = {0,0};
	for(int i = 0;i<n-1;i++){
		total[i&1] += dif[i];
	}
	if(n&1)cout<<"YES\n";
	else if(total[0]>=0)cout<<"YEs\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
