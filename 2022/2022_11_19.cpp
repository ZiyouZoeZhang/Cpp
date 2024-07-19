#include <iostream>

//using namespace std;
int main()
{
    int lenList, sum=0, max=0, wish=0;
    float solution=0;
    int list[510];
    std::cout<<"please input what you would like to calculate\n1. sum, 2. product 3. max value, 4. min value 5. average"<<std::endl;
    std::cin>>wish;
    //ask the user what they wanna do... 1. sum, 2. product 3. max value, 4. min value 5. mean
    std::cout<<"how many numbers would you like to input?"<<std::endl;
    std::cin>>lenList;
    std::cout<<"please input the values"<<std::endl;
    for (int i=0;i<lenList;i++){
        std::cin>>list[i];
            switch(wish){
            case 1:
                solution += list[i];
                break;
                std::cout<<solution;
            case 2:
                if (i==0) solution=1;
                solution *= list[i];
                break;
            case 3:
                if (i==0)solution=list[0];
                else if (list[i] > solution) solution=list[i];
                break;
            case 4:
                if (i==0)solution=list[0];
                else if (list[i] < solution) solution=list[i];
                break;
            case 5:
                solution += list[i];
                if (i==lenList-1) solution/=lenList;
                break;
            default:
                std::cout<<"wrong input, try again";
                return 0;
        }   
    }
    std::cout<<"your solution is "<<solution<<std::endl;
    return 0;
}