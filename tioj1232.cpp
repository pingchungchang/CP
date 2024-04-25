#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n,r;
//	n = 10,r = 10;
	cin>>n>>r;
	string pre;
	string now;
	for(int i = 0;i<n;i++)now += '0'-i+n-1;
	pre = now.substr(0,r);
	vector<string> ans;
	ans.push_back(pre);
	while(prev_permutation(now.begin(),now.end())){
		if(pre == now.substr(0,r))continue;
		pre = now.substr(0,r);
		ans.push_back(pre);
		if(ans.size()>=r+n)break;
	}
	if(r+n>ans.size()-1)cout<<ans[ans.size()-1];
	else cout<<ans[r+n-1];
}
