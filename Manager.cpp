#include"Header.h"
#pragma warning(disable : 4996)
int main()
{
    student s1;
    s1.loadingbar();
    s1.intro();
    s1.login();
    s1.ccolor(929);
    int choice = 0;
    while (choice != 6)
    {
        s1.ccolor(929);
        system("cls");
        cout << "*****************************************************************" << "\n";
        cout << "***                                                           ***" << "\n";
        cout << "***              1. nhap vao du lieu.                    ***" << "\n";
        cout << "***              2. doc du lieu.                  ***" << "\n";
        cout << "***              3. tim du lieu.                    ***" << "\n";
        cout << "***              4. xoa du lieu.                    ***" << "\n";
        cout << "***              5. cap nhat du lieu.                    ***" << "\n";
        cout << "***              6. thoat chuong trinh.                     ***" << "\n";
        cout << "***                                                           ***" << "\n";
        cout << "*****************************************************************" << "\n";
        cout << "\n        nhap lua chon:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s1.getdata();
            s1.storedata();
            cout << "\n\t\t Data is Successfully Stored:";
            getch();
            break;
        case 2:
            s1.viewAlldata();
            getch();
            break;
        case 3:
            s1.showsearch();
            getch();
            break;
        case 4:
            cout << "\n\n Enter student Name to delete a record:";
            char name[30]; fflush(stdin);
            cin.getline(name, 29);
            s1.deleteData(name);
            cout << "\n\t\t Data is Successfully Deleted:";
            getch();
            break;
        case 5:
            cout << "\n\n Enter student Name to Update a record:"; fflush(stdin);
            cin.getline(name, 29);
            s1.updateData(name);
            cout << "\n\t\t Data is Successfully Updated:";
            getch();
            break;
        case 6:
            s1.ccolor(558);
            cout << "\n\t\t Thank You For using This Application:";
            cout << "\n\t\t Enter Any Key To Exit:-";
            getch();
            exit(0);
            break;
        default:
            s1.ccolor(12);
            cout << "Invalid Input Try Again:";
            getch();
        }
    }
    getch();
}