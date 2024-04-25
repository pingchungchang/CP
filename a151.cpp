#include <bits/stdc++.h>
using namespace std;
string s;

int a,b;
stack<int> q;

void g(){
	b = q.top();
	q.pop();
	a = q.top();
	q.pop();	
}
void solve(){
	for(char c:s){
		if(c>='0'&&'9'>=c){
			q.push(c-'0');
		}
		else if(c == '/'){
			g();
			q.push(a/b);
		}
		else if(c == '%'){
			g();
			q.push(a%b);
		}
		else if(c == '-'){
			g();
			q.push(a-b);
		}
		else if(c == '+'){
			g();
			q.push(a+b);
		}
		else{
			g();
			q.push(a*b);
		}
	}
	cout<<q.top()<<'\n';
	q.pop();
	return;
}

int main(){
	while(getline(cin,s))solve();
}
