#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	string s;
	if(n == 1&&m == 0){
		cout<<"0 0";
		return 0;
	}
	if(n*9<m||m == 0){
		cout<<"-1 -1";
		return 0;
	}
	for(int i = 0;i<n;i++){
		if(m>=9){
			m -= 9;
			s += '9';
		}
		else{
			s += '0'+m;
			m = 0;
		}
	}
	string ss = s;
	reverse(s.begin(),s.end());
	if(s[0] == '0'){
		s[0] = '1';
		for(int i = 1;i<s.size();i++){
			if(s[i] != '0'){
				s[i] = s[i]-1;
				break;
			}
		}
	}
	cout<<s<<' '<<ss;
}
