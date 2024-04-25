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
	int a,b;
	cin>>a>>b;
	ld x = sqrt(a*a+b*b);
	cout<<fixed<<setprecision(10)<<a/x<<' '<<b/x;
}

