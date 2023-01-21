#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class student
{
    char name[30];
    int Roll_no;// ma sinh vien
    int age;// tuoi
    char Pname[30];// ten bo
    char stdn[10];// lop sinh vien
    int busno;// so bus
    string convert(string s)// ham viet hoa
    {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = toupper(s[i]);
        }
        return s;
    }
public:
    void intro(void);   // introduction of project.
    void ccolor(int); //display colorful contain.
    void loadingbar(void);   //simple loading bar.
    void login(void); //simple login contain.
    void getdata(void);   //Get all data from user.
    void showdata(void);   //display all data .
    void viewAlldata();     //display all data from files.
    int storedata();        //store all data in a file
    void searchData(char*);    //search a perticuler data.
    void showsearch(void);      //display search.
    void deleteData(char*);    //delete a data.
    void updateData(char*);    //use to update a data.
    student()
    {
        Roll_no = 0;
        age = 0;
        busno = 0;
        strcpy(name, "no name");
        strcpy(Pname, "no name");
        strcpy(stdn, "not found");
    }

};