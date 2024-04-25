#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	int cnt = 0;
	for(auto &i:arr)cin>>i,cnt+=i;;
	if(cnt>n/2){
		cout<<cnt-(cnt&1)<<'\n';
		for(int i = 0;i<cnt-(cnt&1);i++)cout<<1<<' ';
	}
	else{
		cout<<n-cnt<<'\n';
		for(int i = 0;i<n-cnt;i++)cout<<"0 ";
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
