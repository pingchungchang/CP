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
	int n;
	while(cin>>n){
		if(!n)return 0;
		if(n%400 == 0){
			cout<<"a leap year\n";
		}
		else if(n%100 == 0){
			cout<<"a normal year\n";
		}
		else if(n%4 == 0){
			cout<<"a leap year\n";
		}
		else cout<<"a normal year\n";
	}
}

