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
	int n;
	cin>>n;
	vector<int> arr(n+2,0);
	for(int i = 1;i<=n;i++)cin>>arr[i];
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i] != 0&&arr[i-1] == 0)cnt++;
	}
	cout<<(cnt>2?2:cnt)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

