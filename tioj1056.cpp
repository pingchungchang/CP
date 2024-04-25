# include <iostream>
#include <vector>
#include<cstdio>
#include <string>
using namespace std;
int owin = 0;
int xwin = 0;
int find(vector<int> set1,vector<int> set2, int target){
    for (int i = 0; i < set1.size();i++){
        if(set1[i]==target) return 1;
    }
    for (int i = 0; i < set2.size();i++){
        if(set2[i]==target) return 2;
    }
    return 0;
}
void c(vector<int> set1, vector<int> set2, int target){
    int k = find(set1, set2, target);
    if(k==1){
        owin += 1;
    }
    else if(k==2){
        xwin += 1;
    }
}
int main(){
    vector<char> v;
    vector<int> o;
    vector<int> x;
    bool error = false;
    int special=1;
    for (int i = 0; i < 3;i++){
        string iput;    
        cin >> iput;
        for (int j = 0; j < 3;j++){
            if(iput[j] != '.'&&iput[j] != 'O'&&iput[j] != 'X') error = true;
            else if(iput[j]=='O') o.push_back(3 * i + j);
            else if(iput[j]=='X') x.push_back(3 * i + j);
            v.push_back(iput[j]);
        }
    }
    for (int i = 0; i < v.size();i++){
        if(v[i] != '.') special = 0;
    }
    if (!error&& special == 0)
    {
        for (int i = 0; i < 9; i += 3)
        {
            if (v[i] == v[i + 1] && v[i] == v[i + 2])
            {
                c(o, x, i);
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (v[i] == v[i + 3] && v[i] == v[i + 6])
            {
                c(o, x, i);
            }
        }
        if ((v[0] == v[4] && v[0] == v[8]) || (v[2] == v[4] && v[4] == v[6]))
        {
            c(o, x, 4);
        }
    }
    if(o.size()-x.size()>1)error = true;
    // cout << o.size() << x.size()<<special<<error;
    if(o.size()==5&&x.size()==4&&xwin==0) special = 1;
    if (!error){
        if(special == 1) error = false;
        else if (xwin + owin > 1)
            error = true;
        else if (owin == 1 && o.size() != x.size() + 1)
            error = true;
        else if (xwin == 1 && x.size() != o.size())
            error = true;
        else
            error = false;
    }
    else
        error = true;
    if(error) cout << "IMPOSSIBLE";
    else cout << "POSSIBLE";
}