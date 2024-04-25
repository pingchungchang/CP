#include <bits/stdc++.h>
using namespace std;


string f(string tmp,int pos){
	string a,b;
	int par = 0;
	for(int i = pos-1;i>=0;i--){
		if(tmp[i] == ')')par ++;
		else if(tmp[i] == '(')par--;
		a += tmp[i];
		if(par == 0)break;
	}
	reverse(a.begin(),a.end());
	for(int i = pos+1;i<tmp.size();i++){
		if(tmp[i] == ')')par--;
		else if(tmp[i] == '(')par++;
		b += tmp[i];
		if(par == 0)break;
	}
	string k = "!((!"+a + ")|(!"+ b + "))";
	string ans = tmp.substr(0,pos-a.size());
//	cout<<tmp.substr(0,pos-a.size()-1)<<endl<<endl;
	ans += k;
	ans += tmp.substr(pos+b.size()+1);
//	cout<<tmp.substr(pos+b.size()+2)<<endl<<endl;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	string in;
	getline(cin,in);
	getline(cin,in);
	string tmp;
	for(int i = 0;i<in.size();i++){
		if(in.substr(i,3) == "not"){
			tmp += '!';
		}
		else if(in.substr(i,3) == "and"){
			tmp += '&';
		}
		else if(in.substr(i,2) == "or"){
			tmp += '|';
		}
		else if(in[i] == ' ')continue;
		else if(in[i]>='a'&&in[i]<='z')continue;
		else tmp += in[i];
	}
	bool done = true;
	while(done){
		for(int i = 0;i<tmp.size();i++){
			if(tmp[i] == '&'){
				tmp = f(tmp,i);
				break;
			}
			if(i == tmp.size()-1){
				done = false;
				break;
			}
		}
	}
	int cnt = 0;
	for(int i  =0;i<tmp.size();i++){
		if(tmp[i] != ' ')cnt++;
	}
	cout<<cnt<<'\n';
	for(int i = 0;i<tmp.size();i++){
		if(tmp[i] == ' ')continue;
		if(tmp[i] == '|')cout<<"or";
		else if(tmp[i] == '!')cout<<"not";
		else cout<<tmp[i];
		if(i != tmp.size()-1)cout<<' ';
	}
}
//( not ( ( not ( not ( ( not ( 1 ) ) or ( not ( 2 ) ) ) ) ) or ( not ( 3 ) ) ) )
//( ( ( 1 ) and ( 2 ) ) and ( 3 ) )
//not ( ( not ( 3 ) ) and ( ( 2 ) or ( 1 ) ) )
