#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const int mxn = 1e4+2;
int grid[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int p;
		cin>>p;
		int turn = (i&1?1:-1);
		grid[p] = turn;
		int lp = p-1,rp = p+1;
		for(;grid[lp] != turn&&lp>0;lp--);
		for(;grid[rp] != turn&&rp<mxn;rp++);
		if(lp != 0)for(int j = lp;j<=p;j++)grid[j] = turn;
		if(rp<mxn)for(int j = p;j<=rp;j++)grid[j] = turn;
	}
	int cnt[2] = {};
	for(auto &i:grid){
		if(i==1)cnt[1]++;
		if(i==-1)cnt[0]++;
	}
	if(cnt[0] == cnt[1])cout<<"Aaw";
	else if(cnt[0]<cnt[1])cout<<"BrineTW";
	else cout<<"Repkironca";
}
