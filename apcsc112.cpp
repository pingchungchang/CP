#include <bits/stdc++.h>
#include "lib0112.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	Init();
	ll l = 0,r = 1e6;
	while(l != r){
		ll mid = (l+r+1)/2;
		int re = Query(mid);
		if(re == 0)r = mid-1;
		else l = mid;
	}
	Answer(r);
	return 0;
}

