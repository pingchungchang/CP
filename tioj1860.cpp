#include <bits/stdc++.h>
#include "lib1860.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ld E = exp(1);
void solve(){
	int n = Count_How_Many_Loli();
	int k = n/E;
	if(n == 8)k = 3; 
	int big = 0;
	for(int i = 0;i<k;i++){
		big = max(big,Get_Loli_Moeness());
	}
	for(int i = k;i<n;i++){
		int tmp = Get_Loli_Moeness();
		if(i == n-1){
			You_Choose_This_Loli();
			return;
		}
		if(tmp>big){
			You_Choose_This_Loli();
			return;
		}
	}
	return;
}
int main(){
	int t = Start_The_Loli_Dream();
	while(t--)solve();
}

