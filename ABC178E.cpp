#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
pll arr[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	pll x,y;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		arr[i] = pll(arr[i].fs+arr[i].sc,arr[i].fs-arr[i].sc);
	}
	x = pll(arr[1].fs,arr[1].fs);
	y = pll(arr[1].sc,arr[1].sc);
	for(int i = 1;i<=n;i++){
		x.fs = min(x.fs,arr[i].fs);
		x.sc = max(x.sc,arr[i].fs);
		y.fs = min(y.fs,arr[i].sc);
		y.sc = max(y.sc,arr[i].sc);
	}
	cout<<max(x.sc-x.fs,y.sc-y.fs);
}
