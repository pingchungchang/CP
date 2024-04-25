#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		for(int j = 1;j<m;j++){
			if(s[j] == s[j-1]&&s[j] == 'T'){
				s[j-1] = 'P';
				s[j] = 'C';
			}
		}
		cout<<s<<'\n';
	}
}
