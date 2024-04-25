#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	int arr[5] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[k]++;
	}
	int ans = arr[4];
	if(arr[3]<=arr[1]){
		ans += arr[3];
		arr[1]-= arr[3];
	}
	else{
		ans += arr[3];
		arr[1] = 0;
	}
	ans += arr[2]/2;
	if(arr[2]%2 == 1){
		arr[1] -= 2;
		ans ++;
		arr[2] = 0;
	}
	if(arr[1] > 0)ans += (arr[1]+3)/4;
	cout<<ans;
}

