#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
	cin>>a>>b;
	if(max(a,b) == 1)cout<<"1/1";
	else{
		int G = __gcd(6,7-max(a,b));
		cout<<(7-max(a,b))/G<<'/'<<6/G;
	}
}
