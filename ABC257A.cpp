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
	int n;
	cin>>n;
	string s = "#";
	for(char i = 'A';i<='Z';i++){
		for(int j = 0;j<n;j++)s += i;
	}
	int x;
	cin>>x;
	cout<<s[x];
}

