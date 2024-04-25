#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int L = 0,R = 0;
	for(auto &i:s){
		if(i == 'L')L--;
		else R++;
	}
	cout<<R-L+1;
}
