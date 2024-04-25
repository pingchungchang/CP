#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	int a;
	cin>>a;
	int ax[a+1];
	for(int i = 0;i<a;i++)cin>>ax[i];
	ax[a] = h+1;
	int b;
	cin>>b;
	int ay[b+1];
	for(int i = 0;i<b;i++)cin>>ay[i];
	ay[b] = w+1;
	vector<int> v[a+1];
	for(auto &i:arr){
		int x = lower_bound(ax,ax+a+1,i.fs)-ax;
		if(x>=a+1)exit(0);
		v[x].push_back(i.sc);
	}
	int big = 0,small = 1e9;
	for(auto &i:v){
		map<int,int> mp;
		for(auto &j:i){
			j = lower_bound(ay,ay+b+1,j)-ay;
			mp[j]++;
		}
		for(auto &j:mp){
			big = max(big,j.sc);
			small = min(small,j.sc);
		}
		if(mp.size() != b+1)small = 0;
	}
	cout<<small<<' '<<big<<'\n';
	return 0;
}
