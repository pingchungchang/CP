#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int a;
	cin>>a;
	int arr[3];
	int ans = 0;
	for(int i = 0;i<3;i++)cin>>arr[i];
	for(auto i:arr){
		if(i>a)ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

