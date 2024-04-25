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
int a,b;
int main(){
	io
	cin>>a>>b;
	int ans = 0;
	while(b>0){
		if(a>=12){
			int tmp = min(a/12,b);
			a -= tmp*10;
			b -= tmp;
			ans += tmp;
		}
		else{
			b--;
			a++;
		}
	}
	cout<<ans;
}

