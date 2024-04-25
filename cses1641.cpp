#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	pair<int,int> arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second = i+1;
	}
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			int now = m-arr[i].first-arr[j].first;
			int pos = upper_bound(arr,arr+n,make_pair(now,INT_MAX))-arr-1;
			if(pos<0)break;
			if(arr[pos].first == now&&pos != i&&pos != j){
				cout<<arr[pos].second<<' '<<arr[i].second<<' '<<arr[j].second<<'\n';
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
