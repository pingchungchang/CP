#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 2e5+10;
int arr[mxn];
bitset<mxn> vis;
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int now = 1;
	while(!vis[now]){
		vis[now] = true;
		now = arr[now];
	}
	vector<int> ans;
	int st = now;
	do{
		ans.push_back(now);
		now = arr[now];
	}while(now != st);
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return 0;
}
