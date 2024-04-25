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
	string s,ans;
	cin>>s;
	int c = 0;
	for(auto &i:s){
		c |= 1<<(i-'A');
		if(__builtin_popcount(c) == 4)ans += i,c = 0;
	}
	for(auto i:"ATCG"){
		if(c&(1<<(i-'A')))continue;
		ans += i;
		break;
	}
	cout<<ans;
}
