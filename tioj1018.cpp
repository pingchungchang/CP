#include <bits/stdc++.h>

using namespace std;
string det(vector<char> v){
    bool n = false,o = false,a = false;
    vector<string> statements;
    for(int i = 0;i<v.size();i++){
        if(v[i] == '!'){
            n = true;
        }
        else if(v[i] == '|'){
            o = true;
        }
        else if(v[i] == '&') a = true;
        else{
            if(n == false){
                string k ="not ";
                k+=v[i];
                statements.push_back(k);
            }
            else{
              string k;
              k+=v[i];
              statements.push_back(k);
            }
            n = false;
        }
    }
    string ans;
    ans += statements[0];
    if(statements.size()==1)return ans;
    ans += ' ';
    if(o == true){
        ans += "and ";
    }
    else ans += "or ";
    ans += statements[1];
    return ans;
}
void solve(){
    vector<vector<char>> v(2);
    string s = "";
    int now = 0;
    getline(cin,s);
//    cout<<s<<endl;
//    return;
    s += ' ';
    string tmp = "";
    for(int i = 0;i<s.size();i++){
    	if(s[i] == ' '){
    		if(tmp == "IF"){
    			tmp = "";
    			continue;
			}
    		if(tmp == "THEN"){
    			now = 1;
    			tmp = "";
    			continue;
			}
			if(tmp == "and"){
				v[now].push_back('&');
			}
			else if(tmp == "or")v[now].push_back('|');
			else if(tmp == "not")v[now].push_back('!');
			else v[now].push_back(tmp[0]);
			tmp = "";
		}
		else{
			tmp += s[i];
		}
	}
//	cout<<v[0].size()<<' '<<v[1].size()<<endl;
//	for(int i =0;i<v[0].size();i++)cout<<v[0][i]<<' ';
//	cout<<endl;
//	for(int i = 0;i<v[1].size();i++)cout<<v[1][i]<<' ';
//	cout<<endl;
    string s1 = det(v[0]);
    string s2 = det(v[1]);
    cout<<"IF "<<s2<<" THEN "<<s1;
}
/*
IF not B THEN not A
IF C THEN not B
IF not C THEN not A or not B
IF not C THEN not B and not A
IF P THEN Q
*/
int main(){ 
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int t;
    string w;
//    getline(cin,w);
    cin>>t;
    getline(cin,w);
    for(int i = 0;i<t;i++){
		solve();
        if(i != t-1)cout<<'\n';
    }
}

