///                    Project 1
///         Student Record Management System

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void gotoxy(int , int);
void menu();
void add();
void view();
void search();
void modify();
void delete_rec();

struct student{
    int ID;
    char name[30];
    char mobile[15];
    char department[30];
    int batch;
};
int main()
{
    gotoxy(20,3);
    printf("        Developed by Jakaria CSE-15 BRUR");
    gotoxy(15,8);
    printf("---Student Record Management System---");
    gotoxy(19,15);
    printf("Press Any Key to continue!");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("--------------------- Menu -------------------");
    gotoxy(10,5);
    printf("Enter appropriate number to select an option");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete Record.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Please Enter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            view();
            break;
        case 3:
            search();
            break;
        case 4:
            modify();
            break;
        case 5:
            delete_rec();
            break;
        case 6:
            exit(1);
            break;
        default:
            gotoxy(10,17);
            printf("Invalid Choice !\n\n");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another = 'y';
    system("cls");
    gotoxy(20,1);
    printf("        Developed by Jakaria CSE-15 BRUR");
    fp = fopen("record.txt","ab+");

    if(fp == NULL)
    {
        gotoxy(10,3);
        printf("Record File Dose not Exist!!");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("------------------- ADD RECORD: ----------------");
        gotoxy(10,5);
        printf(" Enter Details of Student. ");
        gotoxy(10,7);
        printf(" Enter Name of Student: ");
        gets(std.name);
        gotoxy(10,8);
        printf(" Enter ID Number: ");
        scanf("%d",&std.ID);
        fflush(stdin);
        gotoxy(10,9);
        printf(" Enter Department: ");
        gets(std.department);
        gotoxy(10,10);
        printf(" Enter Batch: ");
        scanf("%d",&std.batch);
        gotoxy(10,11);
        fflush(stdin);
        printf(" Enter Mobile Number ");
        gets(std.mobile);
        fflush(stdin);

        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("Record is Added Successfully!!");
        gotoxy(10,20);
        printf("Want to Add another Student Record? Then Press 'y' otherwise 'n'");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }

    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to Continue.");
    getch();
    menu();
}

void view()
{
    FILE *fp;
    int i = 1, j;
    struct student std;
    system("cls");
    gotoxy(20,1);
    printf("        Developed by Jakaria CSE-15 BRUR");
    gotoxy(10, 3);
    printf("--------------------------------------- VIEW RECORD ----------------------------------------");
    gotoxy(10,5);
    printf("S.NO\tName of Student\t\tID NO\t\tDepartment\tbatch\t\tMobile NO");
    gotoxy(10,6);
    printf("=============================================================================================");

    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Record File Dose not Exist!!");
        exit(1);
    }
    j = 8;
    while(fread(&std,sizeof(std),1,fp)==1)
    {
        gotoxy(10,j);
        printf("%-7d%-22s%-18d%-17s%-14d%-22s",i,std.name,std.ID,std.department,std.batch,std.mobile);
        i++;
        j += 2;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to Continue.");
    getch();
    menu();

}

void  search()
{
    FILE *fp;
    struct student std;
    char std_name[30];
    system("cls");
    gotoxy(20,1);
    printf("        Developed by Jakaria CSE-15 BRUR");
    gotoxy(10,3);
    printf("---------------------- SEARCH RECORD --------------------");
    gotoxy(10,5);
    printf("Enter Name of Student: ");
    fflush(stdin);
    gets(std_name);

    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Record File Does not Exist !!");
        exit(1);
    }

    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(std_name,std.name) == 0)
        {
            gotoxy(10,8);
            printf("Name:       %s",std.name);
            gotoxy(10,10);
            printf("ID:         %d",std.ID);
            gotoxy(10,12);
            printf("Department: %s",std.department);
            gotoxy(10,14);
            printf("Batch:      %d",std.batch);
            gotoxy(10,16);
            printf("Mobile NO:  %s",std.mobile);
        }
    }
    fclose(fp);
    gotoxy(10,20);
    printf("Press any key to continue.");
    getch();
    menu();
}

void modify()
{
    FILE *fp;
    struct student std;
    char std_name[30];
    system("cls");
    gotoxy(20,1);
    printf("        Developed by Jakaria CSE-15 BRUR");
    gotoxy(10,3);
    printf("-------- MODIFY RECORD ----------");
    gotoxy(10,6);
    printf("Enter Name of student to modify: ");
    fflush(stdin);
    gets(std_name);

    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Record File Does Not Exist!!");
        exit(1);
    }

    rewind(fp);
    fflush(stdin);

    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(std_name,std.name) == 0)
        {
            gotoxy(10,7);
            printf("Enter Name of Student: ");
            gets(std.name);
            gotoxy(10,8);
            printf("Enter Student ID: ");
            fflush(stdin);
            scanf("%d",&std.ID);
            gotoxy(10,9);
            printf("Enter Department: ");
            fflush(stdin);
            gets(std.department);
            gotoxy(10,10);
            printf("Enter Batch: ");
            fflush(stdin);
            scanf("%d",&std.batch);
            gotoxy(10,11);
            printf("Enter Student Mobile NO: ");
            fflush(stdin);
            gets(std.mobile);

            fseek(fp, -sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,15);
    printf("Record is Modified Successfully!!");
    gotoxy(10,20);
    printf("Press any key to Continue.");
    getch();
    menu();
}

void delete_rec()
{
    FILE *fp, *ft;
    struct student std;
    char std_name[30];
    system("cls");
    gotoxy(20,1);
    printf("        Developed by Jakaria CSE-15 BRUR");
    gotoxy(10,3);
    printf("-------------------- DELETE RECORD ----------------------");
    gotoxy(10,6);
    printf("Enter Student Name to delete record: ");
    fflush(stdin);
    gets(std_name);

    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Record File Does Not Exist!!");
        exit(1);
    }

    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        gotoxy(10,6);
        printf("Record File Does Not Exist!!");
        exit(1);
    }

    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(std_name,std.name) != 0)
        {
            fwrite(&std,sizeof(std),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,15);
    printf("Record is Deleted Successfully!!");
    gotoxy(10,20);
    printf("Press any key to Continue.");
    getch();
    menu();
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),c);
}


