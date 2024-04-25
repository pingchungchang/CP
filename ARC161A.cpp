#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans[n];
	sort(arr,arr+n);
	int pt = 0;
	for(int i = 0;i<n;i+=2){
		ans[i] = arr[pt++];
	}
	for(int i = 1;i<n;i+=2)ans[i] = arr[pt++];
	for(int i = 1;i<n;i+=2){
		if(ans[i]<=max(ans[i-1],ans[i+1])){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}
