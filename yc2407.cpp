#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
	float c;
	cin>>a>>b>>c;
	int ans = round((a+b)*(c+1));
	cout<<ans;
}
