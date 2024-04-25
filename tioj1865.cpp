#include <bits/stdc++.h>
#include "lib1865.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	int n = GetN();
	int C = 0;
	const int magic = 1e4;
	for(int i = 0;i<n-1;i++){
		for(int j = i;j>=0;j--)Magic_Operate(j);
	}
	End();
	return 0;
}
