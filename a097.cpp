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
#define int ll
main(){
	int x,y;
	io
	while(cin>>x>>y){
		int a = 1,b = 1;
		int total = x+y;
		for(int i = 1;i*i<=total;i++){
			if(total%i != 0)continue;
			a = total/i;
			b = i;
			if((a-2)*(b-2) == y&&(a+b-2)*2 == x){
				break;
			}
//			cout<<i<<endl;
		}
		cout<<max(a,b)<<' '<<min(a,b)<<'\n';
	}

}
//?2(a+b-1) = x
//(a-2)*(b-2) = y;
//ab = x+y
//ab-2b-2a+4 = y+x
