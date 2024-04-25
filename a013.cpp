#include <bits/stdc++.h>
using namespace std;

map<char,int> m;
void solve(string a,string b){
	int xa = 0,xb = 0;
	int now = 1;
	for(int i = a.size()-1;i>=0;i--){
		xa += m[a[i]];
		if(now>m[a[i]]){
			xa -= 2*m[a[i]];
		}
		now = max(now,m[a[i]]);
	}
	now = 1;
	for(int i = b.size()-1;i>=0;i--){
		xb += m[b[i]];
		if(now>m[b[i]]){
			xb -= 2*m[b[i]];
		}
		now = max(now,m[b[i]]);
	}
	int dif = abs(xa-xb);
	string ans;
	while(dif>1000){
		ans += 'M';
		dif -= 1000;
	}
	if(dif>)
}
int main(){
	m['I'] = 1;
	m['D'] = 500;
	m['M'] = 1000;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100; 
	string a,b;
	while(cin>>a>>b){
		solve(a,b);
	}
}
