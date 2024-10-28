#include <iostream>
#include <iomanip>
#include <vector>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)

// Function to display the system state
void displaySystem(const std::vector<std::vector<double>>& system, int year) {
    std::cout << "Year " << year + 1 << ":\n";
    std::cout << "n/k\t1\t2\t3\tSUM\n";

    double totalSystemSum = 0.0;
    for (int n = 0; n < system.size(); ++n) {
        double rowSum = 0.0;
        std::cout << n + 1 << "\t";
        for (int k = 0; k < system[n].size(); ++k) {
            std::cout << std::fixed << std::setprecision(3) << system[n][k] << "\t";
            rowSum += system[n][k];
        }
        totalSystemSum += rowSum;
        std::cout << rowSum << "\n";
    }

    // Print row-wise totals for validation
    std::cout << "SUM\t";
    for (int k = 0; k < system[0].size(); ++k) {
        double tierSum = 0.0;
        for (int n = 0; n < system.size(); ++n) {
            tierSum += system[n][k];
        }
        std::cout << std::fixed << std::setprecision(3) << tierSum << "\t";
    }
    std::cout << totalSystemSum << "\n\n";
}

// Function to simulate the Solera system over a given number of years
void simulateSoleraSystem(int rows, int years) { //n, k
    // Initialize system with empty barrels, top row starts with 1.5 barrels of new wine
    std::vector<std::vector<double>> system(10, std::vector<double>(rows, 0.0));


    int k = rows, n = years;


    //start setup
    system[0][0] = 1;
    system[0][1] = 0.5;
    system[1][1] = 1.5;
    system[2][2] = 1.5;
    system[3][2] = 1.5;

    for (int year = 0; year < years; ++year) {
        displaySystem(system, year);


        std::vector<std::vector<double>> nextSystem = system;

        for(int j = k; j>=0; j--){
            for(int i=0; i<9; i++){
                if (j==k-1){
                    nextSystem[i+1][j] = system[i][j]/2 + system[i][j-1]*(1.5/2);
                } else if (j!=0){
                    nextSystem[i+1][j] = system[i][j-1] + (system[i][j] - system[i][j]*(1.5/2));
                }
            }
        }

        nextSystem[0][0] = 1;
        nextSystem[0][1] = 0.5;

        system = nextSystem;
    }

    // Display final state
    displaySystem(system, years);
}

int main() {
    int rows = 3;   // Number of rows in the triangular Solera system
    int years = 4;  // Number of years to simulate

    simulateSoleraSystem(rows, years);

    return 0;
}