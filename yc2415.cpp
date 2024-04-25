#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string a,b;
	cin>>a>>b;
	if(a.back() == '0'||b.back() == '0')cout<<"Even\n";
	else cout<<"Odd\n";
	return 0;
}
