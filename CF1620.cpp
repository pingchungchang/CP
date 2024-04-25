#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		string s;
		cin>>s;
		s = 'E'+s;
		s+= 'E';
		int p1 = 0,p2 = s.size()-1;
		while(s[p1]== 'E'&&p1<s.size())p1++;
		while(s[p2] == 'E'&&p2>=0)p2--;
		if(p1 == p2)cout<<"NO\n";
		else cout<<"YES\n";
	}
}
