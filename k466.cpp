#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	pii up = {-1,0},down = {-1,0};
	for(int i = 1;i<=n;i++){
		int arr[m];
		for(auto &j:arr)cin>>j;
		int u = 0,d = 0;
		for(int j = 1;j<m;j++){
			u += max(0,arr[j]-arr[j-1]);
			d += max(0,arr[j-1]-arr[j]);
		}
		up = max(up,make_pair(u,-i));
		down = max(down,make_pair(d,-i));
	}
	cout<<-up.sc<<'\n'<<-down.sc;
}
