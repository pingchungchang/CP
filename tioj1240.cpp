#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	vector<int> lis;
	for(int i = n-1;i>=0;i--){
		auto pos = upper_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
		if(pos == lis.size())lis.push_back(arr[i]);
		else lis[pos] = arr[i];
	}
	cout<<lis.size();
}
