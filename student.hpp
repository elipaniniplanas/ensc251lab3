//header file student.hpp to declare your classes

#ifndef STUDENT_HPP
#define STUDENT_HPP
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#pragma once

class ToeflScore
{
public:
        // Constructors
        ToeflScore(int read, int write, int listen, int speak);
        ToeflScore();
        // Mutator functions
        void setreading(int read);
        void setwriting(int write);
        void setlistening(int listen);
        void setspeaking(int speak);
        void settotalscore();
        // Accessor functions
        int getreading() const;
        int getwriting() const;
        int getlistening() const;
        int getspeaking() const;
        int gettotalscore() const;
private:
        int reading;
        int writing;
        int listening;
        int speaking;
        int totalscore;
};

class student// node
{
public:
  // Constructor
  student(string first, string last, float cgpa, int score, int id);
  student();
  // Mutator functions
  void setfname(string);
  void setlname(string);
  void setCGPA(float);
  void setscore(int);
  void setID(int);
  void setlink(student*);
  void add_node(student*, student*, student);
  void delete_headtail_node(student*, student*, student);
  //search node
  void search_CGPA(student*, student*, student*, float); //cgpa
  void search_ID(student*, student*, student*, int); //application id
  void search_SCORE(student*, student*, student*, int);// research score
  void search_fnln(student*, student*, student*, string, string); //first name & lastname
  void delete_fnln(student*, student*, student*, string, string);

  //Accessor functions
  string getfname() const;
  string getlname() const;
  float getCGPA() const;
  int getscore() const;
  int getID() const;
  student* getlink() const;



  //virtual functions
  virtual void swap(student*, student*);
  //friend funstions
  friend string compareCGPA(student, student);
  friend string compareResearchScore(student, student);
  friend string compareFirstName(student, student);
  friend string compareLastName(student, student);
  friend void insert(student*, student);



private:
        string fname;
        string lname;
        float CGPA;
        int SCORE;
        int ID;
        student* link;
};
typedef student* studentprt;

class DomesticStudent : public student
{
public:
        //Constructors
        DomesticStudent(string first, string last, float cgpa, int score, int id, string pv);
        DomesticStudent();
        //Mutator functions
        void setprovince(string pv);
        //Accessor functions
        string getprovince() const;
        friend ostream& operator<<(ostream& outs, const DomesticStudent& dstu);
        //overload the << (output) operator to allow a pre-set format of outputing the member variables of a DomesticStudent object to a ostream
private:
        string province;
};


class InternationalStudent : public student
{
public:
        //Constructors
        InternationalStudent(string first, string last, float cgpa, int score, int id, string co, int read, int write , int listen, int speak);
        InternationalStudent();
        //Mutator functions
        void setcountry(string co);
        void settoefl(int read, int write, int listen, int speak);
        //Accessor functions
        string getcountry() const;
        int gettoeflread() const;
        int gettoeflwrite() const;
        int gettoefllisten() const;
        int gettoeflspeak() const;
        int gettotal() const;

        friend ostream& operator<<(ostream& outs, const InternationalStudent& istu);
        //overload the << (output) operator to allow a pre-set format of outputing the member variables of a InternationalStudent object to a ostream
private:
        string country;
        ToeflScore TOEFL;
};
#endif
