#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	if(n&1){
		cout<<n+9<<' '<<9;
	}
	else{
		cout<<n+4<<' '<<4;
	}
	return 0;
}
