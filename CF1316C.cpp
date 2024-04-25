#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	n--,m--;
	ll arr[n+1],brr[m+1];
	for(auto &i:arr)cin>>i,i%=p;
	for(auto &i:brr)cin>>i,i%=p;
	int a = 0,b = 0;
	for(int i = 0;i<=n;i++){
		if(arr[i])a = i;
	}
	for(int i = 0;i<=m;i++)if(brr[i])b = i;
	cout<<a+b;
}
