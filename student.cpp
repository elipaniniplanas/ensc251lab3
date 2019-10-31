//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

//ToeflScore constructor
ToeflScore::ToeflScore(int read, int write, int listen, int speak)
{
  //Error checking to make sure the values are in range, if not, set value to 0
  if(read <0 || read > 30)
  {
          cout << "Reading toeflScore is invalid, setting value to zero\n";
          reading = 0;
  }
  else
  {
          reading = read;
  }
  if(write <0 || write > 30)
  {
          cout << "Writing toeflScore is invalid, setting value to zero\n";
          writing = 0;
  }
  else
  {
          writing = write;
  }
  if(listen <0 || listen > 30)
  {
          cout << "Listening toeflScore is invalid, setting value to zero\n";
          listening = 0;
  }
  else
  {
          listening = listen;
  }
  if(speak <0 || speak > 30)
  {
          cout << "Speaking toeflScore is invalid, setting value to zero\n";
          speaking = 0;
  }
  else
  {
          speaking = speak;
  }
  totalscore = reading + writing + listening + speaking;
}
ToeflScore::ToeflScore()
{
        reading = 0;
        writing = 0;
        listening = 0;
        speaking = 0;
        totalscore = 0;
}
//Below are the mutator functions for the ToeflScore class
void ToeflScore::setreading(int read)
{
        if(read < 0 || read > 30)
        {
                cout << "Reading toeflScore is invalid, setting value to zero\n";
                reading = 0;
        }
        else
        {
                reading = read;
        }
}
void ToeflScore::setwriting(int write)
{
        if(write < 0 || write > 30)
        {
          cout << "Writing toeflScore is invalid, setting value to zero\n";
          writing = 0;
  }
  else
  {
          writing = write;
  }
}
void ToeflScore::setlistening(int listen)
{
  if(listen < 0 || listen > 30)
  {
          cout << "listening toeflScore is invalid, setting value to zero\n";
          listening = 0;
  }
  else
  {
          listening = listen;
  }
}
void ToeflScore::setspeaking(int speak)
{
  if(speak < 0 || speak > 30)
  {
          cout << "Speaking toeflScore is invalid, setting value to zero\n";
          speaking = 0;
  }
  else
  {
          speaking = speak;
  }
}
void ToeflScore::settotalscore()
{
        totalscore = reading + writing + listening + speaking;
}
//Below are the accessor functions for the ToeflScore class
int ToeflScore::getreading() const
{
        return(reading);
}
int ToeflScore::getwriting() const
{
        return(writing);
}
int ToeflScore::getlistening() const
{
        return(listening);
}
int ToeflScore::getspeaking() const
{
        return(speaking);
}
int ToeflScore::gettotalscore() const
{
        return(totalscore);
}


//Student constructors
student::student(string first, string last, float cgpa, int score, int id)
{
        //Error checking, making sure that the proper values are in range
        if(cgpa > 4.3 || cgpa < 0)
        {
                cout<<"CGPA value is invalid, setting value to zero";
                CGPA = 0.0;
        }
        else
        {
                CGPA = cgpa;
        }
        if(score < 0 || score > 100)
        {
                cout<<"Research score is invalid, setting value to zero";
                SCORE = 0;
        }
        else
        {
                SCORE = score;
        }
        fname = first;
        lname = last;
        ID = id;
}
student::student()
{
        fname = " ";
        lname = " ";
        CGPA = 0.0;
        SCORE = 0;
        ID = 0;
}
//Below are the mutator funtions for the Student class
void student::setfname(string first)
{
        fname = first;
}
void student::setlname(string last)
{
        lname = last;
}
void student::setCGPA(float cgpa)
{
        if(cgpa > 4.3 || cgpa < 0)
        {
                cout<<"CGPA value is invalid, setting value to zero";
                CGPA = 0.0;
        }
        else
        {
                CGPA = cgpa;
        }
}
void student::setscore(int score)
{
        if(score < 0 || score > 100)
        {
                cout<<"Research score is invalid, setting value to zero";
                SCORE = 0;
        }
        else
        {
                SCORE = score;
        }
}
void student::setID(int id)
{
        ID = id;
}
void student::setlink(student* chain)
{
	link = chain;
}
//Below are the accessor functions for the Student class
string student::getfname() const
{
        return(fname);
}
string student::getlname() const
{
        return(lname);
}
float student::getCGPA() const
{
        return(CGPA);
}
int student::getscore() const
{
        return(SCORE);
}
int student::getID() const
{
        return(ID);
}
student* student::getlink() const
{
	return(link);
}
	
/*void overall_sorting(studentprt& n, student temp)
{
        student* cur1 = head;
        student* cur2 = head;
	
	while(cur1 -> link != nullptr)
	{
		
	}
       for (int i = 0; i <  ; i++) 
       {
        for (int j = 0; j <  - 1; j++) 
	{
            if (cur1-> data < cur2->data)
	    {
                int temp = cur1->data;
                cur1->data = cur2->data;
                cur2->data = temp;
            }
            cur2 = cur2->next;
        }
         cur2 = head;
         cur1 = head->next;
         for (int k = 0; k < i; k++) 
	 {
                cur1 = cur1->next;
	 }
       }
}
*/
void add_node(studentprt& head, studentprt& tail, student temp)
{
	studentprt newstudent = new student;
	newstudent -> setlink(temp.getlink());
	newstudent -> setfname(temp.getfname());
	newstudent -> setlname(temp.getlname());
	newstudent -> setCGPA(temp.getCGPA());
	newstudent -> setscore(temp.getscore());
	newstudent -> setID(temp.getID());
	if(head == NULL)
	{
		head = newstudent;
		tail = newstudent;
	}
	else
	{
		tail -> setlink(newstudent);
		tail = tail -> getlink(); 
	}
}  


//Constructor for the DomesticStudent class
DomesticStudent::DomesticStudent(string first, string last, float cgpa, int score, int id, string pv):
        student(first, last, cgpa, score, id)
{
        province = pv;
}
DomesticStudent::DomesticStudent():student()
{
        province = " ";
}
//Mutator function for DomesticStudent, it inherits all of the mutator functions in its parent class Student
void DomesticStudent::setprovince(string pv)
{
        province = pv;
}
//Accessor function for DomesticStudent
string DomesticStudent::getprovince() const
{
        return(province);
}
//Constructor for the InternationalStudent class
InternationalStudent::InternationalStudent(string first, string last, float cgpa, int score, int id, string co, int read, int write , int listen, int speak):
        student(first, last, cgpa, score, id)
{
        country = co;
        //Since TOEFL is a seperate object of a different class, we will have to use the ToeflScore mutator functions
        TOEFL.setreading(read);
        TOEFL.setwriting(write);
        TOEFL.setlistening(listen);
        TOEFL.setspeaking(speak);
}
InternationalStudent::InternationalStudent():student(), country(""){ }
//Mutator functions for the InternationalStudent class
void InternationalStudent::setcountry(string co)
{
        country = co;
}
//This mutator function need call on the TOEFL private members, so ToeflScore's mutator functions are used
void InternationalStudent::settoefl(int read, int write, int listen, int speak)
{
        TOEFL.setreading(read);
        TOEFL.setwriting(write);
        TOEFL.setlistening(listen);
        TOEFL.setspeaking(speak);
        TOEFL.settotalscore();
}
//As the same situation as above, to access the values of the TOEFL object, ToeflScore's accessor functions are used in these accessor functions
int InternationalStudent::gettoeflread() const
{
        return TOEFL.getreading();
}
int InternationalStudent::gettoeflwrite() const
{
        return TOEFL.getwriting();
}
int InternationalStudent::gettoefllisten() const
{
        return TOEFL.getlistening();
}
int InternationalStudent::gettoeflspeak() const
{
        return TOEFL.getspeaking();
}
int InternationalStudent::gettotal() const
{
        return TOEFL.gettotalscore();
}
//Accessor Functions for the InternationalStudent class
string InternationalStudent::getcountry() const
{
        return(country);
}
//Overloaded << operator for Domesticstudents
ostream& operator<<(ostream& outs, const DomesticStudent& dstu)
{
	outs << "Domestic student" << " " << dstu.getfname() << " "
	 << dstu.getlname() << " from " << dstu.getprovince() << " province has cgpa of "
	 << dstu.getCGPA() << ", and research score of " << dstu.getscore()
	 << ", the assigned ID is " << dstu.getID() << endl;
   return(outs);
}
//Overloaded << operator for InternationalStudents
ostream& operator<<(ostream& outs, const InternationalStudent& istu)
{
	outs << "International student" << " " << istu.getfname() << " "
	 << istu.getlname() << " from " << istu.getcountry() << " country has cgpa of "
	 << istu.getCGPA() << ", and research score of " << istu.getscore()
	 << ", the assigned ID is " << istu.getID() <<".\n" <<"Their toefl scores are: reading "
	 << istu.gettoeflread() << ", writing "<< istu.gettoeflwrite() << ", listening "
	 << istu.gettoefllisten() << ", speaking " << istu.gettoeflspeak() << ", and their total toefl score is "
	 << istu.gettotal() <<endl;
   return(outs);
}
//Student's friend functions
/*string compareCGPA(student overallgpa1, student overallgpa2)
{
        student result1,result2;
        result1.CGPA = overallgpa1.CGPA;
        result2.CGPA = overallgpa2.CGPA;
        if (result1.CGPA < result2.CGPA)
        {
                return "less";
        }
        else if (result1.CGPA > result2.CGPA)
        {
                return "greater";
        }
        else
        {
                return "equal";
}
string compareResearchScore(student overallscore1, student overallscore2)
{
        student result1,result2;
        result1.SCORE = overallscore1.SCORE;
        result2.SCORE = overallscore2.SCORE;
        if (result1.SCORE < result2.SCORE)
        {
                return "less";
        }
        else if (result1.SCORE > result2.SCORE)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
string compareFirstName(student overallfname1, student overallfname2)
{
        student result1,result2;
        result1.fname = overallfname1.fname;
        result2.fname = overallfname2.fname;
        if (result1.fname < result2.fname)
        {
                return "less";
        }
        else if (result1.fname > result2.fname)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
string compareLastName(student overalllname1, student overalllname2)
{
        cout << "test comp";
        if (overalllname1.lname < overalllname2.lname)
        {
                return "less";//the first one's name is first in the alphabet
        }
        else if (overalllname1.lname > overalllname2.lname)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
//friend functions for DomesticStudents
string compareProvince(DomesticStudent overallProv1, DomesticStudent overallProv2)
{
        if (overallProv1.province < overallProv2.province)
        {
                return "less";
        }
        else if (overallProv1.province > overallProv2.province)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
void Dswap(DomesticStudent *xp, DomesticStudent *yp)
{
    DomesticStudent temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void Dbubblesort_CGPA(DomesticStudent *arr, int n)
{
  int i, j;
  bool disorganized;
  for (i = 0; i < n-1; i++)
  {
    disorganized = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (compareCGPA((arr[j]), (arr[j+1])) == "less")   //(arr[j] < arr[j+1]) //change this with the compare function
      {
        Dswap(&arr[j], &arr[j+1]);
        disorganized = true;
      }
    }
    if (!disorganized)
    {
      break;
    }
  }
}
void Dbubblesort_ResearchScore(DomesticStudent *arr, int n)
{
  int i, j;
  bool disorganized;
  for (i = 0; i < n-1; i++)
  {
    disorganized = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (compareResearchScore(arr[j], arr[j+1]) == "less")   //(arr[j] < arr[j+1]) //change this with the compare function
      {
        Dswap(&arr[j], &arr[j+1]);
        disorganized = true;
      }
    }
    if (!disorganized)
    {
      break;
    }
  }
}
void Dbubblesort_FirstName(DomesticStudent *arr, int n)
{
  int i, j;
  bool disorganized;
  for (i = 0; i < n-1; i++)
  {
    disorganized = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (compareFirstName(arr[j], arr[j+1]) == "greater")   //(arr[j] < arr[j+1]) //change this with the compare function
      {
        Dswap(&arr[j], &arr[j+1]);
        disorganized = true;
      }
    }
    if (!disorganized)
    {
      break;
    }
  }
}
void Dbubblesort_LastName(DomesticStudent *arr , int n)
{
  int i, j;
  bool disorganized;
  for (i = 0; i < n-1; i++)
  {
    disorganized = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (compareLastName(arr[j], arr[j+1]) == "greater")   //(arr[j] < arr[j+1]) //change this with the compare function
      {
        Dswap(&arr[j], &arr[j+1]);
        disorganized = true;
      }
    }
    if (!disorganized)
    {
      break;
    }
  }
}
void domesticOverallSort(DomesticStudent *arr, int n)
{
  int i, j, k;
  bool disorganized;
  for (i = 0; i < n-1; i++)
  {
    disorganized = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (compareResearchScore(arr[j], arr[j+1]) == "less")
      {
        Dswap(&arr[j], &arr[j+1]);
        disorganized = true;
      }
      else if (compareResearchScore(arr[j], arr[j+1]) == "equal")
      {
        if (compareCGPA(arr[j], arr[j+1]) == "less")
        {
          Dswap(&arr[j], &arr[j+1]);
          disorganized = true;
        }
        else if (compareCGPA(arr[j], arr[j+1]) == "equal")
        {
          if (compareProvince(arr[j], arr[j+1]) == "greater")
          {
            Dswap(&arr[j], &arr[j+1]);
            disorganized = true;
          }
        }
      }
    }
    if (!disorganized)
    {
      break;
    }
  }
}
//friend funcitons for InternationalStudents
string compareCountry(InternationalStudent overallCo1, InternationalStudent overallCo2)
{
        if (overallCo1.country < overallCo2.country)
        {
                return "less";
        }
        else if (overallCo1.country > overallCo2.country)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
void Iswap(InternationalStudent *xp, InternationalStudent *yp)
{
    InternationalStudent temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void deleteIelement(InternationalStudent *arr, int n, int del)
{
  int i, j;
  for(int j=del; j<(n-1); j++)
			{
				arr[j]=arr[j+1];
			}
}
void Ibubblesort_CGPA(InternationalStudent *arr, int n)
{
    int i, j;
    bool disorganized;
    for (i = 0; i < n-1; i++)
    {
      disorganized = false;
      for (j = 0; j < n-i-1; j++)
      {
        if (compareCGPA((arr[j]), (arr[j+1])) == "less")   //(arr[j] < arr[j+1]) //change this with the compare function
        {
          Iswap(&arr[j], &arr[j+1]);
          disorganized = true;
        }
      }
      if (!disorganized)
      {
        break;
      }
    }
}
void Ibubblesort_ResearchScore(InternationalStudent *arr, int n)
{
    int i, j;
    bool disorganized;
    for (i = 0; i < n-1; i++)
    {
      disorganized = false;
      for (j = 0; j < n-i-1; j++)
      {
        if (compareResearchScore(arr[j], arr[j+1]) == "less")   //(arr[j] < arr[j+1]) //change this with the compare function
        {
          Iswap(&arr[j], &arr[j+1]);
          disorganized = true;
        }
      }
      if (!disorganized)
      {
        break;
      }
    }
}
void Ibubblesort_FirstName(InternationalStudent *arr, int n)
{
    int i, j;
    bool disorganized;
    for (i = 0; i < n-1; i++)
    {
      disorganized = false;
      for (j = 0; j < n-i-1; j++)
      {
        if (compareFirstName(arr[j], arr[j+1]) == "greater")   //(arr[j] < arr[j+1]) //change this with the compare function
        {
          Iswap(&arr[j], &arr[j+1]);
          disorganized = true;
        }
      }
      if (!disorganized)
      {
        break;
      }
    }
}
void Ibubblesort_LastName(InternationalStudent *arr, int n)
{
    int i, j;
    bool disorganized;
    for (i = 0; i < n-1; i++)
    {
      disorganized = false;
      for (j = 0; j < n-i-1; j++)
      {
        if (compareLastName(arr[j], arr[j+1]) == "greater")   //(arr[j] < arr[j+1]) //change this with the compare function
        {
          Iswap(&arr[j], &arr[j+1]);
          disorganized = true;
        }
      }
      if (!disorganized)
      {
        break;
      }
    }
}
void internationalOverallSort(InternationalStudent *arr, int n)
{
  int i, j, k, counter;
  counter = 0;
  bool disorganized;
  for (i = 0; i < n-1; i++)
  {
    disorganized = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (compareResearchScore(arr[j], arr[j+1]) == "less")
      {
        Iswap(&arr[j], &arr[j+1]);
        disorganized = true;
      }
      else if (compareResearchScore(arr[j], arr[j+1]) == "equal")
      {
        if (compareCGPA(arr[j], arr[j+1]) == "less")
        {
          Iswap(&arr[j], &arr[j+1]);
          disorganized = true;
        }
        else if (compareCGPA(arr[j], arr[j+1]) == "equal")
        {
          if (compareCountry(arr[j], arr[j+1]) == "greater")
          {
            Iswap(&arr[j], &arr[j+1]);
            disorganized = true;
          }
        }
      }
    }
    if (!disorganized)
    {
      break;
    }
  }
  for (k = 0; k < n-1; k++)
  {
    redo:
    if((arr+k)->gettoeflread() < 20)
    {
      deleteIelement(arr, n, k);
      goto redo;
    }
    else if((arr+k)->gettoeflwrite() < 20)
    {
      deleteIelement(arr, n, k);
      goto redo;
    }
    else if((arr+k)->gettoefllisten() < 20)
    {
      deleteIelement(arr, n, k);
      goto redo;
    }
    else if((arr+k)->gettoeflspeak() < 20)
    {
      deleteIelement(arr, n, k);
      goto redo;
    }
    else if((arr+k)->gettotal() < 93)
    {
      deleteIelement(arr, n, k);
      goto redo;
    }
    else
    {
      counter++;
    }
  }
  InternationalStudent temp[counter];
  for (k = 0; k < counter; k++)
  {
    temp[k] = arr[k];
  }
  arr = temp;
}
*/
