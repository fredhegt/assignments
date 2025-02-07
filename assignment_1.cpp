// Assignment 1: Calculate the energy of a transition using the Bohr model formula
// Student ID: 10628634
// Date: 07/02/2025

#include <iostream>

using std::cout;
using std::cin;

const double elementary_charge = 1.60218e-19;

int main() {
    int Z, ni, nj;
    char choice;
    
    do {
        // Ask the user for the atomic number
        cout<<"Enter the atomic number (Z): ";
        cin>>Z;
        // Check for valid atomic number
        while(cin.fail() || Z <= 0) {
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Atomic number must be a positive integer\n";
            cout<<"Enter the atomic number (Z): ";
            cin>>Z;
        }

        // Ask the user for the initial quantum number
        cout<<"Enter the initial quantum number (ni): ";
        cin>>ni;
        // Check for valid quantum number
        while(cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Quantum number must be a positive integer\n";
            cout<<"Enter the initial quantum number (ni): ";
            cin>>ni;
        }
        
        // Ask the user for the final quantum number
        cout<<"Enter the final quantum number (nj): ";
        cin>>nj;
        // Check for valid quantum number
        while(cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Quantum number must be a positive integer\n";
            cout<<"Enter the final quantum number (nj): ";
            cin>>nj;
        }

        // Calculate the energy using the Bohr model formula
        double energy = 13.6 * (Z * Z) * (1.0 / (nj * nj) - 1.0 / (ni * ni));

        // Ask user whether to print energy in eV or Joules
        cout<<"Would you like to print the energy in eV or Joules? (e/J): ";
        char unit;
        cin>>unit;

        if(unit == 'e' || unit == 'E') {
            cout<<"Energy of the transition: "<<energy<<" eV\n";
        } else if(unit == 'J' || unit == 'j') {
            // Convert eV to Joules (1 eV = 1.60218e-19 J)
            double energy_joules = energy * elementary_charge;
            cout<<"Energy of the transition: "<<energy_joules<<" Joules\n";
        } else{
            cout<<"Invalid unit entered. Please enter 'e' for eV or 'J' for Joules.\n";
            continue;
        }

        // Ask if the user wants to calculate another transition
        cout<<"Do you want to calculate another energy? (y/n): ";
        cin>>choice;

    } while(choice == 'y' || choice == 'Y');
    
    return 0;
}

// End of file
