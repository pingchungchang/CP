#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int x;
	int arr[3];
	cin>>x;
	for(int i= 0;i<3;i++)cin>>arr[i];
	for(int i = 0;i<3;i++){
		if(arr[i] == i+1){
			cout<<"NO\n";
			return;
		}
	}
	if(arr[x-1] == 0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

