#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int arr[mxn];
int n;

bool f(int k){
	deque<int> dq;
	for(int i = k+1;i<=n;i++)dq.push_back(arr[i]);
	int pre = 0;
	while(!dq.empty()){
		if(dq.front()<=dq.back()){
			if(pre>dq.front())return false;
			pre = dq.front();
			dq.pop_front();
		}
		else{
			if(pre>dq.back())return false;
			pre = dq.back();
			dq.pop_back();
		}
	}
	return true;
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int l = 0,r = n-1;
	while(l != r){
		int mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
