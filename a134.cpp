#include <bits/stdc++.h>
using namespace std;


map<string,vector<string>> mp;
bool cmp(string a,string b){
    if(a.size() != b.size())return a.size()<b.size();
    else return a<b;
}
int main(){
    for(int i = 1;i<=12;i++){
        for(int j = 1;j<=31;j++){
            if(j == 31){
                if(i != 1&&i != 3&&i != 5&&i != 7&&i != 10&&i != 12)continue;
            }
            if(i == 2&&j == 30)continue;
            string a = to_string(i);
            string b = to_string(j);
            vector<string> v;
            v.push_back(a+b);
            if(a.size() == 1){
                v.push_back("0"+a+b);
            }
            if(b.size() == 1){
                v.push_back(a+"0"+b);
            }
            if(a.size() == 1&&b.size() == 1)v.push_back("0"+a+"0"+b);
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            for(int k = 0;k<v.size();k++){
                string now = v[k];
                if(now[0] == 0)continue;
                reverse(now.begin(),now.end());
                if(now.size() == 4)mp[now].push_back(now+v[k]);
                else if(now.size() == 3){
                    for(char asd = '0';asd<='9';asd++){
                        string tmp = now+asd;
                        bool flag = true;
                        if(i == 2&&j == 29){
                            flag = false;
                            int x = stoi(tmp);
                            if(x%400 == 0)flag = true;
                            else if(x%100 != 0&&x%4 == 0)flag = true;
                        }
                        if(flag)mp[tmp].push_back(tmp+v[k]);
                    }
                }
                else{
                     for(char a1 = '0';a1<='9';a1++){
                        char a2 = a1;
                        string tmp = now+a1+a2;
                        bool flag = true;
                        if(i == 2&&j == 29){
                            flag = false;
                            int x = stoi(tmp);
                            if(x%400 == 0)flag = true;
                            else if(x%100 != 0&&x%4 == 0)flag = true;
                        }
                        if(flag)mp[tmp].push_back(tmp+v[k]);
                    }
                }
            }
        }
    }
    //for(auto it:mp)cout<<it.first<<endl;
    int t;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i = 0;i<t;i++){
        string s;
        cin>>s;
        if(!mp.count(s))cout<<0;
        else cout<<mp[s].size();
        if(mp.count(s) != 0){
            sort(mp[s].begin(),mp[s].end(),cmp);
            cout<<' ';
            for(auto now:mp[s])cout<<now<<' ';
        }
        cout<<'\n';
    }
}
