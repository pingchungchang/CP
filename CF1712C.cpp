#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1e5+10;
int n;
int arr[mxn];

bool f(int now){
	set<int> st;
	for(int i = 0;i<n;i++){
		if(st.size() != now)st.insert(arr[i]);
	}
	vector<int> tmp(n);
	for(int i = 0;i<n;i++){
		if(st.find(arr[i]) != st.end())tmp[i] = 0;
		else tmp[i] = arr[i];
	}
	for(int i = 1;i<n;i++)if(tmp[i]<tmp[i-1])return false;
	return true;
}
void solve(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int l = 0,r = n;
	while(l != r){
		int mid = (l+r)/2;
		if(f(mid)){
			r = mid;
		}
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

