#include <bits/stdc++.h>
using namespace std;

void printa(multiset<string> &st){
		for(auto it = st.begin();it != st.end();it++){
			string k = *it;
			cout<<k[1];
		}
		cout<<'\n';
		for(auto it = st.begin();it != st.end();it++){
			string k = *it;
			cout<<k[0];
		}
		cout<<'\n';
}
void ins(multiset<string> &st){
	string c1,c2,buf;
	cin>>c1>>buf>>c2;
	reverse(c1.begin(),c1.end());
	reverse(c2.begin(),c2.end());
	st.insert(c1);
	st.erase(st.find(c2));
	return;
}
void solve(){
	multiset<string> st;
	for(int i = 0;i<13;i++){
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		st.insert(s);
	}
	int q;
	cin>>q;
	printa(st);
	for(int i = 0;i<q;i++){
		string task;
		cin>>task;
		if(task == "insert"){
			ins(st);
			printa(st);
		}
		else return;
	}
}

int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		solve();
	}
}
