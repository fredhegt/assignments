#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Z, ni, nj;
    char choice;
    
    do {
        // Ask the user for the atomic number and quantum numbers
        cout << "Enter the atomic number (Z): ";
        cin >> Z;
        
        cout << "Enter the initial quantum number (ni): ";
        cin >> ni;
        
        cout << "Enter the final quantum number (nj): ";
        cin >> nj;

        // Check for valid quantum numbers
        if (ni <= 0 || nj <= 0) {
            cout << "Quantum numbers must be positive integers.\n";
            continue;
        }

        // Calculate the energy using the Bohr model formula
        double energy = 13.6 * pow(Z, 2) * (1.0 / (nj * nj) - 1.0 / (ni * ni));

        // Ask user whether to print energy in eV or Joules
        cout << "Would you like to print the energy in eV or Joules? (e/J): ";
        char unit;
        cin >> unit;

        if (unit == 'e' || unit == 'E') {
            cout << "Energy of the transition: " << energy << " eV\n";
        } else if (unit == 'J' || unit == 'j') {
            // Convert eV to Joules (1 eV = 1.60218e-19 J)
            double energy_joules = energy * 1.60218e-19;
            cout << "Energy of the transition: " << energy_joules << " Joules\n";
        } else {
            cout << "Invalid unit entered. Please enter 'e' for eV or 'J' for Joules.\n";
            continue;
        }

        // Ask if the user wants to calculate another transition
        cout << "Do you want to calculate another energy? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
