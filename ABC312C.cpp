#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> all;
	int arr[n],brr[m];
	for(auto &i:arr)cin>>i,all.push_back(i);
	for(auto &i:brr)cin>>i,all.push_back(i);
	for(auto &i:arr)all.push_back(i+1);
	for(auto &i:brr)all.push_back(i+1);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	sort(arr,arr+n);
	sort(brr,brr+m);
	int p1 = 0,p2 = 0;
	for(auto &i:all){
		while(p1<n&&arr[p1]<=i)p1++;
		while(p2<m&&brr[p2]<i)p2++;
		if(p1>=m-p2){
			cout<<i;
			return 0;
		}
	}
	cout<<brr[m-1]+1;
	return 0;
}
