#include <iostream>
#include <cmath>
using namespace std;
int main()
{

   int operator1, operator2, result;
   char choice;

   // Get user input
   do {
      cout << "Enter first operand (0-9): ";
      cin >> operator1;

      if (operator1 < 0) {
         cout << "Error: Operator cannot be negative." << endl;
         continue;
      }

      cout << "Enter second operand (0-9): ";
      cin >> operator2;

      if (operator2 < 0) {
         cout << "Error: Operator cannot be negative." << endl;
         continue;
      }
   } while (cin.fail()); // Repeat loop until valid input is entered

   switch(operator1) {
   case 4: // Calculate square root of number
      result = sqrt(float(operator2));
      cout << "The  root of " << operator2 << " is " << result << endl;
      break;
   default: // Other operations
      cout << "Error: Invalid operation." << endl;
   }

   return 0;
}
