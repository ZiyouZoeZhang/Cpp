/*
ID: zz415821
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

bool isLeapYear = false;
int monthList[510];
int solution[510];
void firstYearCalculation();
void everyYear(int NumOfYears);

int main(){
    std::ofstream fout ("friday.out");
    std::ifstream fin ("friday.in");
    int years;
    fin >> years;
    firstYearCalculation();
    everyYear(years);
    fout<<solution[6]<<" "<<solution[0]<<" "<<solution[1]<<" "<<solution[2]<<" "<<solution[3]<<" "<<solution[4]<<" "<<solution[5]<<"\n";
}

void leapYear(int year){
    if (year%100==0){
        if (year%400==0) isLeapYear = true;
        else isLeapYear=false;
    } else if (year%4 == 0) isLeapYear = true;
    else isLeapYear=false;
}

void firstYearCalculation(){
    int days = 0;
    int weekday = 0;
    for (int month=1; month<=12; month++){
        weekday = (weekday+13)%7;
        monthList[month-1]=(weekday)%7;
        if (month==4 || month==6 ||month==9 || month==11 ) days=30-13;
        else if (month == 2) days=28-13;
        else days=31-13;
        weekday=(weekday+days)%7;
        solution[monthList[month-1]]+=1; 
    } 
}

void everyYear(int NumOfYears){
    for (int currentYear=1901; currentYear<1900+NumOfYears; currentYear++){
        leapYear(currentYear);
        for (int i=0; i<12; i++){
            monthList[i]=(monthList[i]+1)%7;
            if (isLeapYear==true && i>1) monthList[i]=(monthList[i]+1)%7; solution[monthList[i]]+=1; 
        }
        if (isLeapYear==true && currentYear!=1900+NumOfYears-1){
            monthList[0]+=1;
            monthList[1]+=1;
        }
    }
}