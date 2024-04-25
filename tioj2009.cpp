#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
int arr[mxn],tar[mxn];
int n,k;
int ans = 0;

void flip(int p){
	ans++;
	for(int i = 0;i<k;i++){
		arr[i+p]++;
		if(arr[i+p]>9)arr[i+p] -= 9;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)cin>>tar[i];
	for(int i = 0;i+k<=n;i++){
		while(arr[i] != tar[i])flip(i);
	}
	for(int i =0;i<n;i++){
		if(arr[i] != tar[i]){
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
}
