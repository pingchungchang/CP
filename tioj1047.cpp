#include <bits/stdc++.h>
using namespace std;

string s;
void solve(){
	string tmp = "";
	for(int i = s.size()-1;i>=0;i--){
		if(s[i] == '!'){
			if(tmp[0] == '0')tmp[0] = '1';
			else if(tmp[0] == '1')tmp[0] = '0';
		}
		else tmp =s[i]+tmp;
	}
	s = tmp;
	tmp = "";
//	for(int i = s.size()-1;i>=0;i--){
//		if(s[i] == '*'){
//			int a= tmp[0]='0';
//			int b= s[i-1]-'0';
//			if((a&b) == 1){
//				tmp[0] = '1';
//			}
//			else tmp[0] = '0';
//			i--;
//		}
//		else tmp = s[i]+tmp;
//	}
//	s = tmp;	
//	tmp = "";
//	for(int i = s.size()-1;i>=0;i--){
//		if(s[i] == '+'){
//			int a = tmp[0]-'0';
//			int b = s[i-1]-'0';
//			if((a|b) == 1){
//				tmp[0] = '1';
//			}
//			else{
//				tmp[0] = '0';
//			}
//			i--;
//		}
//		else{
//			tmp = s[i]+tmp;
//		}
//	}


	for(int i = 0;i<s.size();i++){
		if(s[i] == '*'){
			int a = tmp[tmp.size()-1]-'0';
			int b = s[i+1]-'0';
			tmp[tmp.size()-1] = (char)('0'+(a&b));
			i++;
		}
		else tmp += s[i];
	}
	s = tmp;	
	tmp = "";
	for(int i = 0;i<s.size();i++){
		if(s[i] == '+'){
			int a= tmp[tmp.size()-1]-'0';
			int b = s[i+1]-'0';
			i++;
			tmp[tmp.size()-1] = (char)('0'+(a|b));
		}
		else tmp += s[i];
	}
	if(tmp.size()!=1)cout<<"ERROR "<<tmp<<'\n';
	else cout<<tmp<<'\n';
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	while(getline(cin,s)){
		if(s == "END")return 0;
		solve();		
	}
}

/*


*/
/*
void solve(){
	int now = s[s.size()-1]-'0';
	for(int i = s.size()-2;i>=0;i--){
		if(s[i] == '!'){
			now = (1^now);
		}
		else if(s[i] == '+'){
			now = (now|(s[i-1]-'0'));
		}
		else if(s[i] == '*'){
			now = (now&(s[i-1]-'0'));
		}
	}
	cout<<now<<'\n';
	return;
}
*/

