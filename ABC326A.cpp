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
	if(a>=b&&a-b<=3)cout<<"Yes";
	else if(a<=b&&b-a<=2)cout<<"Yes";
	else cout<<"No";
}
