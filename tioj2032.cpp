#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1<<22;
int paths[mxn];
bitset<mxn> goneto;
int id[mxn];
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<(1<<n);i++){
		int tmp  = i;
		for(int ii = 0;ii<n;ii++)tmp ^=(1<<ii);
		int k;
		cin>>k;
		while(k--){
			int j;
			cin>>j;
			tmp^=(1<<j);
		}
		paths[i] = tmp;
	}
	cout<<"Yes\n";
	vector<int> all;
	int now = 0;
	while(!goneto[now]){
		goneto[now] = true;
		all.push_back(now);
		now = paths[now];
	}
	bool flag = false;
	vector<int> total;
	for(auto &i:all){
		if(i == now)flag = true;
		if(flag)total.push_back(i);
	}
	cout<<total.size()<<'\n';
	for(auto &i:total)cout<<i<<' ';
}

