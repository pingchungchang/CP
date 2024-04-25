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
	ll n;
	cin>>n;
	ll diff[n][n];
	ll arr[n];
	for(auto &i:arr){
		cin>>i;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			diff[i][j] = abs(arr[i]-arr[j]);
		}
	}
	ll primes[] = {3,4,5,7,11,13,17,19,23,29};
	for(int i = 0;i<n;i++){
		for(auto &p:primes){
			int tmp = 0;
			for(int j = 0;j<n;j++){
				if(j == i)tmp++;
				else{
					if(diff[i][j]%p == 0)tmp++;
				}
			}
			if(tmp>=(n+1)/2){
				cout<<p;
				return 0;
			}
		}
	}
	cout<<-1;
}

