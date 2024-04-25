#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mxn = 1e4+10;
vector<int> lpf(mxn,0);
vector<map<int,int>> v(mxn);
vector<int> primes;
int main(){
	for(int i = 2;i<mxn;i++){
		if(lpf[i] == 0){
			primes.push_back(i);
			lpf[i] = i;
		}
		for(int auto:x:primes){
			if(x*i>=mxn)break;
			lpf[x*i] = x;
			if(x == lpf[i])break;
		}
	}
}

