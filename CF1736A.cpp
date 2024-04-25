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

void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	int type = 0,c1 = 0,c2 = 0;
	for(auto &i:a)if(i)c1++;
	for(auto &i:b)if(i)c2++;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i]){
			if(a[i] == 1)type |= 4;
			else type |= 2;
		}
	}
	if(type == 4||type == 2||type == 0){
		cout<<abs(c1-c2)<<'\n';
	}
	else{
		cout<<abs(c1-c2)+1<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

