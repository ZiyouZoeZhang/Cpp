//things to consider
/*
Goal: how often does the 13th land on each day of the month?
1. get ready with how many days in the month
   (4, 6, 9, 11 have 30 days, 1, 3, 5, 7, 8, 10, 12 have 31 days. Feburary has 28, unless year%4 ==0)
2. what day does the month start with?

one function figuring out what day the 13th will land on, how many days it has and the weekday of last day+1, given the weekday this month starts with
*/

//we could have a program that saves the weekday as friday + x. If the year is a long feburary year, just have the rest of the weekdays + 1
// variables
#include <iostream>
//#nclude <map>
//#include <string>

int firstDay = 1;
bool isLeapYear = false;
int monthList[510];
int solution[510];
void firstYearCalculation();
void showSolution(int counter);
void everyYear(int NumOfYears);

int main()
{
    //std::cout<<"i ran\n";
    firstYearCalculation();
    everyYear(20);

    std::cout<<"\n";
    //last time show solution
    std::cout<<solution[6]<<" ";
    for (int i=0; i<6; i++){
        std::cout<<solution[i]<<" ";
    }
    std::cout<<"\n";
}

void leapYear(int year){
    if (year%100==0){
        if (year%400==0){ 
            isLeapYear = true;
            
        } else {
            isLeapYear=false;
        }
    } else if (year%4 == 0){
        isLeapYear = true;
        //std::cout<<"huh? \n";
    } else isLeapYear=false;
}

//get ready with how many days in the month
   //(4, 6, 9, 11 have 30 days, 1, 3, 5, 7, 8, 10, 12 have 31 days. Feburary has 28, unless year%4 ==0)
void firstYearCalculation(){
    int days = 0;
    int weekday = 0;
    for (int month=1; month<=12; month++){
        //calculating how many days in a month
        weekday = (weekday+13)%7;
        monthList[month-1]=(weekday)%7;
        if (month==4 || month==6 ||month==9 || month==11 ){
            days=30-13;
        } else if (month == 2){
            days=28-13;
        } else {
            days=31-13;
        }
        weekday=(weekday+days)%7;
        showSolution(month-1);
    } 
}

void everyYear(int NumOfYears){
    //year cycle
    for (int currentYear=1901; currentYear<1900+NumOfYears; currentYear++){
        //std::cout<<"count\n";
        leapYear(currentYear);
        //month cycle
        for (int i=0; i<12; i++){
            monthList[i]=(monthList[i]+1)%7;
            if (isLeapYear==true && i>1){
                //std::cout<<"i better ran"<<monthList[i]<<"\n";
                monthList[i]=(monthList[i]+1)%7;
                //monthList[0]+=1;
                //monthList[1]+=1;
                //std::cout<<monthList[i]<<"\n";
            }
            showSolution(i);
            /*
            if (isLeapYear == false || i<=2){
                TBD[i] = (monthList[i]+firstDay-1)%7;
                
                //std::cout<<"this means I - 1了\n";
            } else {
                TBD[i] = (monthList[i]+firstDay)%7;
            }  
            std::cout<<i<<" "<<monthList[i]<<"; ";
            monthList[i]+=0;
            //std::cout<<i<<"after "<<monthList[i]<<"; ";
            */
        }
        
        //std::cout<<"\n";
        /*
        for (int i=0; i<7; i++){
            std::cout<<solution[i]<<" ";
        */
        

        if (isLeapYear==true && currentYear!=1900+NumOfYears-1){
            monthList[0]+=1;
            monthList[1]+=1;
        }
    }
    //std::cout<<"\n";

        //firstDay=(monthList[6]+18)%7;
        //showSolution();
        //break;
        
//new one = (old one on the same place + startday-1)%7. if leap year, days after the second month gets +1. After every cycle don't ferget to calculate the new startday.

}




void showSolution(int counter){

    //std::cout<<monthList[counter]<<" ";
    solution[monthList[counter]]+=1;

    /*
    for (int i=0; i<12; i++){
        std::cout<<monthList[i]<<" ";
        solution[monthList[i]]+=1;
    }
    */
    /*
    std::cout<<"\n";
    for (int i=0; i<7; i++){
        std::cout<<solution[i]<<" ";
    }*/
    
}