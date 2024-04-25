#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans = 0;
	ans = max(ans,a+b+c);
	ans = max(ans,a*b+c);
	ans = max(ans,a*(b+c));
	ans = max(ans,(a+b)*c);
	ans = max(ans,a+b*c);
	ans = max(ans,a*b*c);
	cout<<ans;
}

