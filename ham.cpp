#include"Header.h"
#pragma warning(suppress : 4996)
void student::ccolor(int clr) {
    HANDLE  hConsole;//  xử lý 1 đối tượng
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// truy xuất đối tượng ra
    SetConsoleTextAttribute(hConsole, clr);// thay đôi màu background

    //the above code displays colorful background.
}
void student::loadingbar()
{
    for (int i = 15; i <= 100; i += 5)//increasing by  5 and start with 15
    {
        system("cls");
        ccolor(14);
        cout << "\n\n\n\n\n\n\n\t\t\t";
        cout << i << " %% Loading...\n\n\t\t";
        cout << " ";
        for (int j = 0; j < i; j += 2) {
            cout << " ";
        }
        Sleep(50);  //sleep for 50 mile second
        if (i == 90 || i == 50 || i == 96 || i == 83) {
            Sleep(50);
        }
    }
    system("cls");// clear the terminal
}
void student::intro()
{
    ccolor(433);
    cout << "*****************************************************************" << endl
        << "*****************************************************************" << endl
        << "*************      student MONITORING SYSTEM       **************" << endl
        << "*************             MADE BY Long                 **********" << endl
        << "*****************************************************************" << endl
        << "*****************************************************************" << endl
        << "_________________________________________________________________\n";
    //simple introduction
    getch();
}
void student::login()
{
    ccolor(14); // simple login with user_id and password
    char ui[] = "Long";
    char psw[] = "6789";
    char gui[10], gpsw[10];
    cout << "\n\t\t______________________________" << endl
        << "\t\t|ENTER USER ID:";
    cin >> gui;
    cout << "\n\t\t______________________________" << endl
        << "\t\t|ENTER PASSWORD:";
    cin >> gpsw;
    if (strcmp(ui, gui) != 0 && strcmp(psw, gpsw) == 0)
    {
        ccolor(12);
        cout << "\t\tINVALID UI AND PASSWORD:";
        getch();
        exit(0);
    }
    else
    {
        cout << "\t\tLOGIN SUCSESSFULLY:-\n";
    }
}
void student::getdata()
{

    fflush(stdin);// xoa bo nho dem khi nhap
    cout << "\t**************************************************" << endl;
    cout << "\tma so chuyen :"; cin >> Roll_no; fflush(stdin);
    cout << "\t**************************************************" << endl;

    cout << "\t* ten tai xe :"; 
    cin.clear();
    cin.ignore(32767, '\n');
    cin.getline(name, 28); fflush(stdin);
    cout << "\t**************************************************" << endl;
  
    cout << "\t so xe:"; cin >> busno; fflush(stdin);
    cout << "\t**************************************************" << endl;
    cout << "\t so cay di duoc"; cin >> age; fflush(stdin);
    cout << "\t**************************************************" << endl; fflush(stdin);
    cout << "\t doanh thu:";
    cin.clear();
    cin.ignore(32767, '\n');
    cin.getline(Pname, 29); fflush(stdin);
    cout << "\t**************************************************" << endl;
    cout << "\t* ENTER student STANDARD :"; 
    cin.clear();
    cin.ignore(32767, '\n');
    cin.getline(stdn, 9); fflush(stdin);
    cout << "\t**************************************************" << endl; fflush(stdin);

}
void student::showdata()
{
    cout << "\t***************************************************" << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t|ten tai xe      |->    " << name << "   " << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t|ma so chuyen  |->       " << Roll_no << "          " << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t|so xe    |->       " << busno << "         " << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t|so tuyen      |->        " << age << "         " << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t|so cay|->     " << Pname << "  " << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t|doanh thu      |->    " << stdn << "     " << endl;
    cout << "\t|                             |                   " << endl;
    cout << "\t***************************************************" << endl;
}
int student::storedata()
{
    if (age == 0 && Roll_no == 0)
    {
        cout << "\n student data not initialized : ";
        return(0);
    }
    else
    {
        ofstream fout; // xuất file
        fout.open("file.dat", ios::app | ios::binary);// thêm mới hoặc mở file ở dạng nhị phân
        fout.write((char*)this, sizeof(*this)); // ghi file
        fout.close();// đóng file
        return(1);

    }
}
void student::viewAlldata()
{
    ifstream fin; // VAO FILE
    fin.open("file.dat", ios::in | ios::binary);
    if (!fin)
        cout << "error file not found:";
    else {
        fin.read((char*)this, sizeof(*this));// đọc file
        while (!fin.eof()) {// trả về con trỏ cuối file
            showdata();
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
    }
}
void student::searchData(char* t)
{
    int count = 0;
    ifstream fin;
    fin.open("file.dat", ios::in | ios::binary);
    if (!fin)
        cout << "error file not found:";
    else {
        fin.read((char*)this, sizeof(*this));
        while (!fin.eof()) {
            if (!strcmp(t, name)) {
                showdata();
                count++;
            }
            fin.read((char*)this, sizeof(*this));
        }
        if (count == 0)
            cout << "\n record not found:";
        fin.close();
    }
}
void student::showsearch()
{
    cout << "\t\t*************************************" << "\n";
    cout << "\t\t*                                   *" << "\n";
    cout << "\t\t*      student SEARCH OPTION        *" << "\n";
    cout << "\t\t*                                   *" << "\n";
    cout << "\t\t*************************************" << "\n";
    char ser[30];
    cout << "\t\t Enter Name of the student:";
    fflush(stdin);
    cin.getline(ser, 29);
    searchData(ser);
}
void student::deleteData(char* t)
{
    ifstream fin;
    ofstream fout;
    fin.open("file.dat", ios::in | ios::binary);
    if (!fin)
    {
        ccolor(12);
        cout << "Error file not found:";
    }

    else {
        fout.open("temp.dat", ios::out | ios::binary);
        fin.read((char*)this, sizeof(*this));
        while (!fin.eof())
        {
            if (strcmp(name, t))
                fout.write((char*)this, sizeof(*this));
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("file.dat");
        rename("temp.dat", "file.dat");
    }
}
void student::updateData(char* t)
{
    fstream file;
    file.open("file.dat", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);// di chuyen con trỏ
    file.read((char*)this, sizeof(*this));
    while (!file.eof())
    {
        if (!strcmp(t, name)) {
            getdata();
            file.seekp(file.tellp(),sizeof(*this));
            file.write((char*)this, sizeof(*this));
        }
        file.read((char*)this, sizeof(*this));
    }
}