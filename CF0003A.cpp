#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string a,b;
	cin>>a>>b;
	pii s,t;
	s = {a[0]-'a',a[1]-'0'};
	t = {b[0]-'a',b[1]-'0'};
	cout<<max(abs(s.fs-t.fs),abs(s.sc-t.sc))<<'\n';
	while(s.fs != t.fs&&s.sc != t.sc){
		string ss;
		if(s.fs>t.fs)ss += 'L',s.fs--;
		else ss += 'R',s.fs++;
		if(s.sc>t.sc)ss += 'D',s.sc--;
		else ss += 'U',s.sc++;
		cout<<ss<<'\n';
	}
	while(s.fs != t.fs){
		if(s.fs>t.fs)cout<<"L\n",s.fs--;
		else cout<<"R\n",s.fs++;
	}
	while(s.sc != t.sc){
		if(s.sc > t.sc)cout<<"D\n",s.sc--;
		else cout<<"U\n",s.sc++;
	}
	return 0;
}
