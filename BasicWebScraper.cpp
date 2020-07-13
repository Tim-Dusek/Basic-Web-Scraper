//Written by Timothy Dusek
//8/28/19
//MUST BE COMPILED WITH C++11 FLAG
//compile with this command: g++ -std=c++11 BasicWebScraper.cpp.cpp
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() 
{
	string STRING; //Variable Declarations
	string y;
	smatch m;
	int count = 1;
	regex a("http.*www.+gov\\/.+\"\\>"); //Regex used to determine what is a valid email address
	printf("Downloading File...\n");
	system ("wget http://www.senate.gov/general/contact_information/senators_cfm.cfm -q"); //runs wget in queit mode
	
	ifstream infile; //start of opening the file for reading
	infile.open("senators_cfm.cfm"); 
	while (!infile.eof()) { //while not at end of file

		getline(infile,STRING);
		regex_search(STRING,m,a);
		for (auto x : m){
			cout << count <<": ";
			count = count +1;
			y=x;
			y.pop_back();
			y.pop_back();
			cout << y << "\n";
		}
	 }
	
	cout << "Attempting to delete downloaded file...\n";
  	unlink("senators_cfm.cfm"); // Deletes the file
	cout << "Success!\n";
    return 0;
}
