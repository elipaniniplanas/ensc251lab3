/*
	AUTHORS: ELI PLANAS AND CHENNY CAO
	THIS CODE WAS COMPLETED ON OCT. 13, 2019

*/
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp" //header file

int main(){
  //Declare the varibles used throughout the program
  string line; //Used to retrieve a line in the files
  string userInStu; // User input
  string userInComp; // User input
  student* Dhead; //Head pointer for the DomesticStudent linked list
  student* Dtail; //Tail pointer for the DomesticStudent linked list
  student* DtempPtr; //Temporary pointer for the DomesticStudent linked list
  student* Ihead; //Head pointer for the InternationalStudent linked list
  student* Itail; //Tail pointer for the InternationalStudent linked list
  student* ItempPtr; //Temporary pointer for the InternationalStudent linked list

  //Read the domestic-stu.txt file and exit if failed
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open())
  {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);//this skips the first line which is about the file format
  int Dstu_count = 1;
  int ID_count = 20200000;
  int counter1 = 0;
  int counter2 = 0;

  while( getline(domesticFile, line) )
  {
    //make the string from the line in the file into a istringstream to be able to parse the data
    istringstream ss(line);
    //Declare variables to hold the data parsed from the file/lines
    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, province, ',');
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    // Set all data to a DomesticStudent node


    counter1++;
    Dstu_count++;
    ID_count++;
  }
  domesticFile.close();

  //accessing the international-stu.txt
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open())
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  getline(internationalFile, line);//this skips the first line which is about the file format
  //This is used to keep track of which student is being printed out and keeps track of how many international students there are
  int Istu_count = 1;
  while( getline(internationalFile, line) )
  {
    istringstream ss(line);
    //Declare variables to hold the data parsed from the file/lines
    string firstName, lastName, s_cgpa, s_researchScore, country, s_read, s_listen, s_speak, s_write;
    float cgpa;
    int researchScore, read, listen, speak, write;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, country, ',');
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    getline(ss, s_read, ',');
    read = atoi(s_read.c_str());
    getline(ss, s_listen, ',');
    listen = atoi(s_listen.c_str());
    getline(ss, s_speak, ',');
    speak = atoi(s_speak.c_str());
    getline(ss, s_write, ',');
    write = atoi(s_write.c_str());
    // Set all data to the Istudent object with mutator functions
 
    //Generate a new ID and prepare to the next iteration of the loop
    counter2++;
    Istu_count++;
    ID_count++;
  }
  //close your file
  internationalFile.close();
	
	
  retry:
  cout << "What would you like to sort:\nDomestic students; type 'D' or 'd'\nInternational students; type 'I' or 'i'\nINPUT: "; // prompt for user input
  cin >> userInStu;
  cout << endl;
  //Sort domestic students
  if ((userInStu == "d")||(userInStu == "D"))
  {
    tryagain1: //gateway #1 of loop for user input 2nd error
    cout << "Sort by students by their:\nCGPA; type 'C' or 'c'\nResearch Score; type 'R' or 'r'\nFirst name; type 'F' or 'f'\nLast name; type 'L' or 'l'\nOverall; type 'O' or 'o'\nINPUT: "; // prompt for user input
    cin >> userInComp;
    cout << endl;
    //Sort by CGPA
    if ((userInComp == "c")||(userInComp == "C"))
    {

    }
    // Sort by research score
    else if ((userInComp == "r")||(userInComp == "R"))
    {
      
    }
    // Sort by first name
    else if ((userInComp == "f")||(userInComp == "F"))
    {
    }
    // Sort by last name
    else if ((userInComp == "l")||(userInComp == "L"))
    {
      
    }
    else if ((userInComp == "o")||(userInComp == "O"))
    {
      
    }
    else
    {
      cout << "INPUT ERROR\n";
      goto tryagain1; // gateway #1 of loop for user input 2nd error
    }
  }
  else if ((userInStu == "i")||(userInStu == "I"))
  {
    tryagain2: //gateway #2 of loop for user input 2nd error
    cout << "Sort by:\nCGPA; type 'C' or 'c'\nResearch Score; type 'R' or 'r'\nFirst name; type 'F' or 'f'\nLast name; type 'L' or 'l'\nOverall; type 'O' or 'o'\nINPUT: ";
    cin >> userInComp;
    cout << endl;
    // Sort by CGPA
    if ((userInComp == "c")||(userInComp == "C"))
    {
      
    }
    // Sort by reseach score
    else if ((userInComp == "r")||(userInComp == "R"))
    {
      
    }
    // Sort by first name
    else if ((userInComp == "f")||(userInComp == "F"))
    {
      
    }
    // Sort by last name
    else if ((userInComp == "l")||(userInComp == "L"))
    {
      
    }
    else if ((userInComp == "o")||(userInComp == "O"))
    {
      
    }
    else
    {
      cout << "INPUT ERROR\n";
      goto tryagain2; //gateway #2 of loop for user input 2nd error
    }
  }
  else
  {
    cout << "INPUT ERROR\n";
    goto retry; //gateway of loop for user input error
  }
  return 0;
}
