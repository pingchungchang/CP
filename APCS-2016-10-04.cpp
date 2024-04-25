#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, vector<string>> m;
    for (int i = 1; i < 10;i++){
        int a;
        cin >> a;
        for (int j = 0; j < a;j++){
            string s;
            cin >> s;
            m[i].push_back(s);
        }
    }
    int max;
    cin >> max;
    int turn[2];
    int nowout = 0;
    turn[0] = 1;
    turn[1] = 0;
    int out = 0;
    int points = 0;
    vector<int> bases;
    for (int i = 0; i < 3;i++) bases.push_back(0);
    // 初始化完成
    while(out<max){
        if(turn[0]>9){
            turn[1] += 1;
            turn[0] -= 9;
        }
        if(m[turn[0]][turn[1]] == "FO"||m[turn[0]][turn[1]] == "GO"||m[turn[0]][turn[1]] == "SO"){
            out += 1;
            nowout += 1;
        }
        else if(m[turn[0]][turn[1]] =="1B"){
            if(bases[2] == 1){
                bases[2] = 0;
                points += 1;
            }
            if(bases[1] == 1){
                bases[1] = 0;
                bases[2] = 1;
            }
            if(bases[0] == 1){
                bases[1] = 1;
                bases[0] = 0;
            }
            bases[0] = 1;
        }
        else if(m[turn[0]][turn[1]] =="2B"){
            if(bases[2] == 1){
                bases[2] = 0;
                points += 1;
            }
            if(bases[1] == 1){
                bases[1] = 0;
                points += 1;
            }
            if(bases[0] == 1){
                bases[2] = 1;
                bases[0] = 0;
            }
            bases[1] = 1;
        }
        else if(m[turn[0]][turn[1]] =="3B"){
            if(bases[2] == 1){
                bases[2] = 0;
                points += 1;
            }
            if(bases[1] == 1){
                bases[1] = 0;
                points += 1;
            }
            if(bases[0] == 1){
                bases[0] = 0;
                points +=1;
            }
            bases[2] = 1;
        }
        else if(m[turn[0]][turn[1]] =="HR"){
            for (int i = 0; i < 3;i++){
                if(bases[i] !=0)  points +=1;
                bases[i] = 0;
            }
            points += 1;
        }
        turn[0] += 1;
        if(out%3 == 0&&out !=0&&nowout == 3){
            for (int i = 0; i < 3;i++) bases[i] = 0;
            nowout = 0;
        }
    }
    cout << points;
}