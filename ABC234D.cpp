#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> req(n);
	for(int i =0 ;i<n;i++)cin>>req[i];
	vector<bool> used(n+1,false);
	int now = n-k+1;
	
	vector<int> ans(n-k+1);
	for(int i = n-1;i>=k-1;i--){
		ans[i-k+1] = now;
		used[req[i]] = true;
		if(req[i]>=now){
			now--;
			while(used[now] == true)now--;
		}
	}
	for(int i:ans)cout<<i<<' ';;
}
