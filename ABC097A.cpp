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
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(abs(a-c)<=d||(abs(a-b)<=d&&abs(c-b)<=d))cout<<"Yes";
	else cout<<"No";
	return 0;
}

