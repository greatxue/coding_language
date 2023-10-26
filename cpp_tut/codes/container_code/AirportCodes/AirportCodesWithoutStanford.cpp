/*
 * File: AirportCodes.cpp
 * ----------------------
 * This program looks up a three-letter airport code in a Map object.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

/* Function prototypes */

string toUpperCase(string str);
void readCodeFile(string filename, map<string,string> & myMap);

/* Main program */

int main() {
   map<string,string> airportCodes;
   readCodeFile("AirportCodes.txt", airportCodes);
   while (true) {
      string line;
      cout << "Airport code: ";
      getline(cin, line);
      if (line == "") break;
      string code = toUpperCase(line);
      if (airportCodes.find(code) != airportCodes.end()) {
         cout << code << " is in " << airportCodes[code] << endl;
      } else {
         cout << "There is no such airport code" << endl;
      }
   }
   return 0;
}

/*
 * Function: readCodeFile
 * Usage: readCodeFile(filename, map);
 * -----------------------------------
 * Reads a data file representing airport codes and locations into the
 * map, which must be declared by the client.  Each line must consist of
 * a three-letter code, an equal sign, and the city name for that airport.
 */

string toUpperCase(string str) {
   for (int i = 0; i < str.length(); i++) {
      str[i] = toupper(str[i]);
   }
   return str;
}

void readCodeFile(string filename, map<string,string> & myMap) {
   ifstream infile;
   infile.open(filename.c_str());
   if (infile.fail()) {
        cout << "Can't read the data file";
        exit(0);
   }
   string line;
   while (getline(infile, line)) {
      if (line.length() < 4 || line[3] != '=') {
         cout << "Illegal data line: " + line;
         exit(0);
      }
      string code = toUpperCase(line.substr(0, 3));
      //myMap.insert(pair<string,string>(code, line.substr(4)));
      myMap.emplace(code, line.substr(4));
   }
   infile.close();
}
