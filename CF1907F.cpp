#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
int arr[mxn*2],brr[mxn*2];
int n;
deque<int> dq;

void solve(){
	dq.clear();
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i],arr[i+n] = arr[i],brr[i] = arr[i];
	reverse(brr,brr+n);
	for(int i = 0;i<n;i++)brr[i+n] = brr[i];
	int ans = 1e9;

	for(int i = 0;i<n;i++){
		while(!dq.empty()&&arr[dq.back()]>arr[i])dq.pop_back();
		dq.push_back(i);
	}
	for(int i = n;i<n*2;i++){
		while(!dq.empty()&&i-dq.front()>=n)dq.pop_front();
		while(!dq.empty()&&arr[dq.back()]>arr[i])dq.pop_back();
		dq.push_back(i);
		if(dq[0] == i-n+1&&dq.size() == n){
			ans = min(ans,n*2-i-1);
		}
	}
	dq.clear();
	for(int i = 0;i<n;i++){
		while(!dq.empty()&&brr[dq.back()]>brr[i])dq.pop_back();
		dq.push_back(i);
	}
	for(int i = n;i<n*2;i++){
		while(!dq.empty()&&i-dq.front()>=n)dq.pop_front();
		while(!dq.empty()&&brr[dq.back()]>brr[i])dq.pop_back();
		dq.push_back(i);
		if(dq[0] == i-n+1&&dq.size() == n){
			ans = min(ans,n*2-i-1+1);
		}
	}
	dq.clear();

	for(int i = 0;i<n;i++){
		while(!dq.empty()&&arr[dq.back()]<arr[i])dq.pop_back();
		dq.push_back(i);
	}
	for(int i = n;i<n*2;i++){
		while(!dq.empty()&&i-dq.front()>=n)dq.pop_front();
		while(!dq.empty()&&arr[dq.back()]<arr[i])dq.pop_back();
		dq.push_back(i);
		if(dq[0] == i-n+1&&dq.size() == n){
			ans = min(ans,n*2-i-1+1);
		}
	}
	dq.clear();
	for(int i = 0;i<n;i++){
		while(!dq.empty()&&brr[dq.back()]<brr[i])dq.pop_back();
		dq.push_back(i);
	}
	for(int i = n;i<n*2;i++){
		while(!dq.empty()&&i-dq.front()>=n)dq.pop_front();
		while(!dq.empty()&&brr[dq.back()]<brr[i])dq.pop_back();
		dq.push_back(i);
		if(dq[0] == i-n+1&&dq.size() == n){
			ans = min(ans,n*2-i-1+2);
		}
	}
	dq.clear();
	cout<<(ans>n*2?-1:ans)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
