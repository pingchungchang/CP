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
	io
	ll t;
	while(cin>>t){
		t *=6;
		t %= 40;
		if(t<=5)cout<<"("<<t+10<<",5)\n";
		else if(t<=15)cout<<"(15,"<<t-5+5<<")\n";
		else if(t<=25)cout<<"("<<30-t<<",15)\n";
		else if(t<=35)cout<<"(5,"<<40-t<<")\n";
		else cout<<"("<<t-30<<",5)\n";
	}
	return 0;
}

