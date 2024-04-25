#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int n;
void solve(){
	int arr[n+2];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	arr[0] = arr[n+1] = 2e9;
	int ans[n+2] = {};
	deque<int> dq;
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&arr[dq.back()]<arr[i])dq.pop_back();
		ans[i] += i-dq.back();
		if(dq.back() != 0)ans[i]++;
		dq.push_back(i);
	}
	dq.clear();
	dq.push_back(n+1);
	for(int i = n;i>=1;i--){
		while(!dq.empty()&&arr[dq.back()]<arr[i])dq.pop_back();
		ans[i] += dq.back()-i-1;
		if(dq.back() != n+1)ans[i]++;
		dq.push_back(i);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
