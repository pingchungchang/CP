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
	reverse(a.begin(),a.end());
	cout<<(a==b?"YES":"NO");
}
