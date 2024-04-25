#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int l1,l2,r1,r2;
	cin>>l1>>r1>>l2>>r2;
	cout<<max(0,min(r1,r2)-max(l1,l2));
}

