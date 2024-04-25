#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double

pll tar,arr[2],O;

ld dist(pll a,pll b){
	return sqrt((a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc));
}

bool calc(ld r){
	bool flag = false;
	for(auto &i:arr){
		if(dist(O,i) <= r&&dist(i,tar)<=r)flag = true;
	}
	if(dist(O,arr[0])<=r&&dist(arr[1],tar)<=r&&dist(arr[0],arr[1])<=r*2)flag = true;
	swap(arr[0],arr[1]);
	if(dist(O,arr[0])<=r&&dist(arr[1],tar)<=r&&dist(arr[0],arr[1])<=r*2)flag = true;
	return flag;
}

void solve(){
	cin>>tar.fs>>tar.sc;
	for(auto &i:arr)cin>>i.fs>>i.sc;
	ld l = 0,r = 1e9;
	for(int i =0;i<60;i++){
		ld mid = (l+r)/2;
		if(calc(mid))r = mid;
		else l = mid;
	}
	cout<<fixed<<setprecision(10)<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	O = {0,0};
	int t;cin>>t;
	while(t--)solve();
}
