#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int asd=0;asd<t;asd++){
		string s;
		cin>>s;
		if(s[s.size()-1]!= s[0]){
			s[s.size()-1] = s[0];
		}
		cout<<s;
		cout<<'\n';
	}
}
