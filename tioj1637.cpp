#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn =1e6+10;
int n;
int arr[mxn];
deque<int> dq;
int sum = 0;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++)cin>>arr[i];
	arr[0] = 1e18;
	dq.push_back(0);
	int ans = 0;
	for(int i = 1;i<n;i++){
		while(arr[dq.back()]<arr[i]){
			sum -= arr[dq.back()]*(dq.end()[-1]-dq.end()[-2]);
			dq.pop_back();
		}
		sum += arr[i]*(i-dq.back());
		ans += sum;
		dq.push_back(i);
	}
	cout<<ans;
}
