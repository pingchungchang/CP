#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n-1];
	for(auto &i:arr)cin>>i;
	int ans[n] = {};
	fill(ans,ans+n,100000000);
	for(int i = 0;i<n-1;i++){
		ans[i] = min(ans[i],arr[i]);
		ans[i+1] = min(ans[i+1],arr[i]);
	}
	int total = 0;
	for(auto &i:ans)total += i;
	cout<<total;
}
