#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int x;
	cin>>x;
	int cnt = 0;
	while(x!= 0){
		if((x&1))cnt++;
		x>>=1;
	}
	cout<<cnt;
}

