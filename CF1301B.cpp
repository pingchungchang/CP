#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
int arr[mxn];
int n;

void solve(){
	pair<int,int> range = {1e9,1};
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		if(arr[i] == -1){
			if(i!=n-1){
				if(arr[i+1] != -1){
					range.first = min(range.first,arr[i+1]);
					range.second = max(range.second,arr[i+1]);
				}
			}
			if(i != 0){
				if(arr[i-1] != -1){
					range.first = min(range.first,arr[i-1]);
					range.second = max(range.second,arr[i-1]);
				}
			}
		}
	}
	for(int i = 0;i<n;i++){
		if(arr[i] == -1)arr[i] = (range.first+range.second)/2;
	}
	int ans = 0;
	for(int i = 1;i<n;i++)ans = max(ans,abs(arr[i]-arr[i-1]));
	cout<<ans<<' '<<(range.first+range.second)/2<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
