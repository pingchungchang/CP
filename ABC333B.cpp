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
	string a,b;
	cin>>a>>b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int d1 = a[1]-a[0],d2 = b[1]-b[0];
	if(d1+d2 == 5||d1==d2)cout<<"Yes";
	else cout<<"No";
}
