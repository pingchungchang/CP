#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int a,b,c,x;
	cin>>a>>b>>c>>x;
	if(x<=a){
		cout<<1;
		return 0;
	}
	if(x<=b){
		cout<<fixed<<setprecision(9)<<(double)(c/(double)(b-a));
		return 0;
	}
	cout<<0;
	return 0;
}

