#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int arr[mxn],brr[mxn];
int n;
int ca[mxn],cb[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],ca[arr[i]]++;
	for(int i = 1;i<=n;i++)cin>>brr[i],cb[brr[i]]++;
	for(int i = 1;i<=n;i++){
		if(ca[i]+cb[i]>n){
			cout<<"No\n";
			return 0;
		}
	}
	reverse(brr+1,brr+n+1);
	int tar = -1;
	int pt = 0;
	vector<int> able,need;
	for(int i = 1;i<=n;i++)if(arr[i] == brr[i])tar = arr[i];
	for(int i = 1;i<=n;i++){
		if(arr[i] != tar&&brr[i] != tar)able.push_back(i);
		if(arr[i] == tar&&brr[i] == tar)need.push_back(i);
	}
	while(!need.empty()){
		swap(brr[need.back()],brr[able.back()]);
		need.pop_back();
		able.pop_back();
	}
	cout<<"Yes\n";
	for(int i = 1;i<=n;i++)cout<<brr[i]<<' ';cout<<'\n';
	return 0;

}
