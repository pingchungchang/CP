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
	int p[] = {1,2,0,4,3};
	int a[] = {0,2,3,1,4};
	for(auto i:p)cout<<i<<' ';cout<<endl;
	for(int i = 0;i<20;i++){
		int tmp[5];
		for(auto j:a)cout<<j<<' ';cout<<endl;
		for(int j= 0;j<5;j++){
			tmp[p[a[j]]] = a[p[j]];
		}
		for(int j = 0;j<5;j++)a[j] = tmp[j];
	}
}

