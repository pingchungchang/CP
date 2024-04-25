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
	string s[10];
	int a = INT_MAX,b=0,c =INT_MAX,d =0;
	for(int i =0;i<10;i++){
		cin>>s[i];
		for(int j = 0;j<10;j++){
			if(s[i][j] == '#'){
				c = min(c,j+1);
				d = max(d,j+1);
				a  =min(a,i+1);
				b = max(b,i+1);
			}
		}
	}
	cout<<a<<' '<<b<<'\n'<<c<<' '<<d;
}

