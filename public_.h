#ifndef PUBLIC__H
#define PUBLIC__H
#include "ah.h"
#include "pass_.h"
#include "enc.h"

class public_ : public pass_
{
    public:
        long long int balance;
        long long int loan;
        long long int transection;

        char name[30];
        char phone[15];
        char Email[50];
        char acname[10];
        char adress[150];
        string pass;
        char temp[150];
        char pas[150];


        char path[30]="F:\\bank account\\";
        void built_id()
        {
                x:
                //system("cls");
                cout<<"\n\n\t\t\tEnter your Id: ";
                gets(acname);
                if(strlen(acname)!=7)
                    goto x;
                strcpy(temp,path);
                strcat(temp,acname);
                int p=mkdir(temp);
                if(!p)
                {
                    cout<<"\t\t\tYour Account name is: "<<acname<<"\n\n"<<endl;
                    //system("pause");
                    {
                        //system("cls");
                    cout<<"\n\t\t\tEnter your name: ";
                    gets(name);
                    Xp:
                        //system("cls");
                    cout<<"\n\t\t\tEnter your Phone Number: ";
                    gets(phone);
                    if(strlen(phone)!=11)
                        goto Xp;

                        //system("cls");
                    cout<<"\n\t\t\tEnter your Email: ";
                    gets(Email);
                        //system("cls");
                    cout<<"\n\t\t\tEnter your Address: ";
                    gets(pas);
                        //system("cls");
                    }
                    {
                   // system("cls");
                    strcat(temp,"\\name.txt");
                    FILE *f=fopen(temp,"w");
                    fputs(name,f);
                    fclose(f);
                    }

                    {
                        strcpy(temp,path);
                        strcat(temp,acname);
                        strcat(temp,"\\Phone Number.txt");
                        FILE *f=fopen(temp,"w");
                        fputs(phone,f);
                        fclose(f);

                    }
                    {
                        strcpy(temp,path);
                        strcat(temp,acname);
                        //system("cls");
                        strcat(temp,"\\Email.txt");
                        FILE *f=fopen(temp,"w");
                        fputs(Email,f);
                        fclose(f);
                    }
                    {

                        strcpy(temp,path);
                        strcat(temp,acname);
                        //system("cls");
                        strcat(temp,"\\Address.txt");
                        FILE *f=fopen(temp,"w");
                        fflush(stdin);
                        fputs(pas,f);
                        fclose(f);
                    }
                    enc to;
                    {
                        cout<<"\n";
                        pass=passs();
                        //cout<<pass;
                        pass=to.encrypt(pass,"Hitlar");
                        strcpy(temp,path);
                        strcat(temp,acname);
                        strcat(temp,"\\Password.txt");
                        ofstream p(temp,ios::app);
                        cout<<"\n";
                        p<<pass;
                        p.close();
                    }
                            {
                                strcpy(temp,path);
                                strcat(temp,acname);
                                strcat(temp,"\\amount.txt");
                                FILE *f=fopen(temp,"w");
                                fputs("0",f);
                                fclose(f);
                            }
                            cout<<"\n\n\t\t\tSuccessfully Opened Account!!!\n";
                    }
                     else
                    cout<<"\n\n\t\t\tNamed this an Account Exists!!\n\n\n";
                    system("pause");
                }

};

#endif // PUBLIC__H
