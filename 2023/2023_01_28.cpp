#include <iostream>
#include <vector>


#include <stack>
//using namespace std;
int main() {
    std::string input;
    std::cin >> input;
    int max_pairs = 0;
    int current_pairs = 0;
    std::stack<char> brackets;

    for (int c=0; c<input.length();c++) {
        if (input[c] == '(') {
            brackets.push(c);
            current_pairs++;
        } else if (input[c] == ')' && !brackets.empty()) {
            brackets.pop();
            current_pairs--;
            max_pairs++;
        }
    }

    std::cout << max_pairs << std::endl;
    return 0;
}



/*
int count, distance, rightD;
std::string brackets="";
int main() {
    std::cin>>brackets;
    for (int i = 0; i<brackets.size()-1; i+=distance+1+rightD){
        rightD=0;
        distance=0;
        while (brackets[i-distance]=='(' && brackets[i+distance+1+rightD]==')'){
            count++;
            while (brackets[i+rightD+2]=='(' && brackets[i+rightD+3]==')'){
                count++;
                rightD+=2;
            }
            distance+=1;
        }
    }
    std::cout<<"final solution: "<<count<<std::endl;
}
*/


//(((())())


/*
int main (){
    string input ="";
    cin>>input;
    string currentguess = "";
    for (int length=1; length<input.size(); length++){
        //先找长度为i的字符串， 如果没有，break loop， current guess = final answer
        //先写两个再说， 找个规律
        for (int i=0; i < input.size()-length; i++){//string 循环
            //每次要找与length相等的字符串

            for (int check=length/2; check>=1; check--){

            }

            //e.g length=2


            if (input[i]==input[i+1]){
                currentguess=input[i]+input[i+1];
                break;
            }
            
        }


        if (input[i-1]==input[i+1]){
            for (int j=2; j<input.size()/2; j++){
                if (input[i-j] != input[i+j]){
                    break;
                }
                else if (currentguess<)){
                
                }
            }
        }
        

    }
}
*/