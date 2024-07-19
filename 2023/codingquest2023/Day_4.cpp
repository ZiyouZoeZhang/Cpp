#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void decode(string mes);
void print_solution(string line);
int double_cal(char val_1, char val_2);
string sender = "", sequence = "", check = "", combine="", message="";
int message_sum = 0;
vector<string> solution_vec(120);

void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            sender = "", sequence = "", check = "", combine="", message="";
            message_sum = 0;
            decode(line);
        }
        file.close();
    }
    for (int i = 0; i<solution_vec.size(); i++) print_solution(solution_vec[i]);
}

void decode(string mes) {
    for (int i =0; i<mes.size(); i++){
        if (i<12) sender.push_back(mes[i]);
        else if (i<14) sequence.push_back(mes[i]);
        else if (i<16) check.push_back(mes[i]);
        else message.push_back(mes[i]);
    }
    if (sender!="555500020164") return;
    for (int i=16; i<mes.size(); i=i+2) message_sum+=double_cal(mes[i], mes[i+1]);
    if (message_sum%256==stoi(check,0,16)) solution_vec[stoi(sequence)]=message;
}

void print_solution(string line){
    for (int i=0; i<line.size(); i=i+2) cout<<char(double_cal(line[i], line[i+1]));
}

int double_cal(char val_1, char val_2){
    string temp="";
    temp.push_back(val_1);
    temp.push_back(val_2);
    return stoi(temp,0,16);
}

int main() {
    readFile("Day_4.txt");
    return 0;
}