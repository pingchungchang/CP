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
int f(int now){
	if(now == 0)return 1;
	return now*f(now-1);
}
int main(){
	io
	int n;
	cin>>n;
	cout<<f(n);
}

