#include <bits/stdc++.h>
using namespace std;
//?!!!!!!! °²¸Ñ¹L¤F?!!!! 
int lst = 0;
string solve(string s,int xxx){
	int now = xxx;
	if(now>=s.size())return"";
	string l,r,op;
	if(s[now] == '('){
		l = solve(s,now+1);
	}
	else{
		l = string(1,s[now]);
		lst = now+1;
	}
	
	if(s[lst] == ')'){
		lst++;
		return l;
	}
	else if(s[lst] == 'a'||s[lst] == 'm'||s[lst] == '#'||s[lst] == 'x'){
		op = string(1,s[lst]);
		lst++;
	}

	
	r = solve(s,lst);
	
	return l+r+op;
}
int main(){
	string s;
	cin>>s;
	int k = s.size();
	for(int i = 0;i<k;i++){
		for(int j = 0;j<s.size();j++){
			if(s[j] == '*'||s[j] == '/'){
				if(s[j] == '*')s[j] = 'x';
				else s[j] = '#';
				int p = j+1;
				int nm = (s[p] == '('?1:0);
				while(nm != 0){
					p++;
					if(s[p] == '(')nm++;
					else if(s[p] == ')')nm--;
				}
				s.insert(s.begin()+p+1,')');
				p = j-1;
				nm = (s[p] == ')'?1:0);
				while(nm != 0){
					p--;
					if(s[p] == ')')nm++;
					else if(s[p] == '(')nm--;
				}
				s.insert(s.begin()+p,'(');
			}
		}
	}
	for(int i = 0;i<k;i++){
		for(int j = 0;j<s.size();j++){
			if(s[j] == '+'||s[j] == '-'){
				if(s[j] == '+')s[j] = 'a';
				else s[j] = 'm';
				int p = j+1;
				int nm = (s[p] == '('?1:0);
				while(nm != 0){
					p++;
					if(s[p] == '(')nm++;
					else if(s[p] == ')')nm--;
				}
				s.insert(s.begin()+p+1,')');
				p = j-1;
				nm = (s[p] == ')'?1:0);
				while(nm != 0){
					p--;
					if(s[p] == ')')nm++;
					else if(s[p] == '(')nm--;
				}
				s.insert(s.begin()+p,'(');
			}
		}
	}
//	cout<<s<<endl;
	s = solve(s,0);
	for(char c:s){
		if(c == 'a')cout<<'+';
		else if(c == '#')cout<<'/';
		else if(c == 'x')cout<<'*';
		else if(c == 'm')cout<<'-';
		else cout<<c;
	}
}

//((A+(Bx(C-D))+E)x(((F+G)#((HxI)))+J))
