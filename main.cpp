/*
  Jonathon Irizarry
  COSC-1436-57001
  Repl.it
  This program is used to output the information of an employees net payment from a job based off if they are full-time or part-time. This includes deductions, and taxes. The program also adds color to the text and All Caps the Name as well as outputting two strings at the end that utilizes tolower and toupper functions.
*/

#include <iostream>
#include<string> //for string manipulation
#include <locale>
#include <iomanip> 

using namespace std;
locale loc;
string reset = "\x1b[0m";
string color = "\x1b[" + to_string(36) + ";4m"; //blue and underlined
string color2 = "\x1b[" + to_string(31) + ";1m"; //red and bold
double weeklyPay(double, double, string, int);//function prototype

int main() {
 
  string outro = "TCC-TR IS COOL";
  string outro2 = "i will succeed at c++!!!";

  cout << fixed << setprecision(2);
  cout << weeklyPay(47.00, 505.75, "Jonathon", 1) << endl;
  cout << weeklyPay(45, 55.25, "Melvin", 1) << endl;
  cout << weeklyPay(15, 65.25, "Susan", 2) << endl;
  cout << weeklyPay(41, 14.75, "Mika", 1) << endl;
  cout << weeklyPay(25, 15.0, "Eldrige", 2) << endl;
  cout << weeklyPay(55, 203.50, "Freedom", 1) << endl;
  cout << weeklyPay(32.5, 100.25, "Tyson", 1) << endl;

  cout << '\n';

  for(int i = 0; i < outro.length(); i++){
    cout << tolower(outro[i],loc);
  }

  cout << '\n';

  cout << color2 << endl;

  for(int i = 0; i < outro2.length(); i++){
    cout << toupper(outro2[i],loc);
  }

  cout << reset << endl; 

  return 0;
}

double weeklyPay(double hours, double rate, string name, int empType){// weeklyPay function
  double netPay = 0.0, FIT, SST, MT, grossPay, taxableWage; //variables
 
  

//display the name on screen CAP and in colore
  cout << color << endl; //format a new line before each name 
  for(int i = 0; i < name.length(); i++ )
  {
    cout << toupper(name[i],loc); 
  }
  cout << reset << endl; //a line after the name

  if(empType == 1){
    cout << "Status : Full time" << endl;
  } else {
    cout << "Status : Part time" << endl;
  }

  if(hours > 40){// if hours are more than 40
    grossPay = (40 * rate) + ((hours - 40) * (rate * 2));
  } else {
    grossPay = hours * rate;
  }

  cout << "Gross Pay: $" <<  grossPay << endl;

if(empType == 1){
  // deductions
  double dentalDed = 17.00;
  double retDed = 77.00;

  //print
  cout << "Dental Deduction (pre-tax FIT) : $" << dentalDed << endl;
  cout << "Retirement Deduction (pre=tax FIT) : $" << retDed << endl; 
  taxableWage = grossPay - (dentalDed + retDed);
} else {
  taxableWage = grossPay;
}

//print
cout << "taxable Wage: $" << taxableWage << endl;

//house less than 15, calculate, 12% Federal Income Tax of grossPay
if(hours < 15){
  FIT = taxableWage * 0.12;
} else {
  FIT = taxableWage * 0.15;
}

//print
cout << "Tederal Income Tax (FIT): $" << FIT << endl;

//calculate social security tax 6.2%
SST = grossPay * 0.062;

//calculate Medicare tax
MT = grossPay * 0.0145;

//print
cout << "Social Security Tax: $" << SST << endl;
cout << "Medicare Tax: $" << MT << endl;

//calculate netpay deduct tax from taxableWage
netPay = taxableWage - (FIT + SST + MT);
//return
cout << "Net Pay: $";

return netPay;
}