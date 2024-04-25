#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a = -1;
	for(int i = 0;i<n;i++){
		if(s[i]>s[0]){
			a = i;
			break;
		}
	}
	if(a != -1)s = s.substr(0,a);
	for(int i = 0;i<s.size();i++){
		if(s[i] == s[0]&&s.substr(i,n-i)>s.substr(0,n-i)){
			s = s.substr(0,i);
		}
	}
	int pos = s.size()-1;
	while(pos>0&&s[pos] == s[0])pos--;
	s = s.substr(0,pos+1);
	while(s.size()<m)s += s;
	cout<<s.substr(0,m);
}

