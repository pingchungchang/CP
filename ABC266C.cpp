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
int cross(pll a,pll b){
	return (a.fs*b.sc-a.sc*b.fs>0);
}
int main(){
	io
	pll arr[4];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	pll vec[5];
	for(int i = 0;i<3;i++)vec[i] = {arr[i+1].fs-arr[i].fs,arr[i+1].sc-arr[i].sc};
	vec[3] = {arr[0].fs-arr[3].fs,arr[0].sc-arr[3].sc};
	vec[4] = vec[0];
	for(int i = 1;i<5;i++){
		if(cross(vec[i],vec[i-1])!=cross(vec[1],vec[0])){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
}

