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
	int n,k;
	cin>>n>>k;
	string arr[k];
	for(auto &i:arr)cin>>i;
	if(k == 1){
		for(auto &i:arr[0]){
			if(i == '1')cout<<0;
			else cout<<1;
		}
		return 0;
	}
	else if(k == 2){
		string tmp(n,'#');
		int cnt = 0;
		for(int i = 0;i<n;i++){
			if(arr[0][i] == arr[1][i]){
				if(arr[0][i] == '1')tmp[i] = '0';
				else tmp[i] = '1';
			}
			cnt++;
		}
		cnt /=2;
		for(int i = 0;i<n;i++){
			if(tmp[i] != '#')continue;
			if(cnt>0)tmp[i] = arr[0][i];
			else tmp[i] = arr[1][i];
		}
		cout<<tmp;
	}
	else{
	}
}

