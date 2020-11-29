#ifndef PASS__H
#define PASS__H
#include "ah.h"
#include "enc.h"

class pass_
{

public:
    enc to;
    string passs()
    {
    while(1){
            //system("cls");
            fflush(stdin);
            pair <string ,char >p;
            p.first="000000000000000000000000000000";
            char q;
            cout<<"\n\n\t\t\tPress Password: ";
            for(int i = 0 ;i<30 ;)
            {
                q=getch();
                if(q==13)
                {
                    break;
                }
                if(q=='\b')
                {
                    p.first[i]='0';
                    i--;
                    p.first[i]='0';
                    system("cls");
                    cout<<"\n\n\t\t\tPress Password: ";
                    for(int j = 0 ;j<i;j++)
                    {
                        cout<<'*';
                    }
                }
                else
                {
                    cout<<'*';
                    p.first[i]=q;
                    i++;
                }
            }
            cout<<"\n";
            pair <string ,char >r;
            r.first="000000000000000000000000000000";
            cout<<"\n\n\t\t\tConfirm Password: ";
            fflush(stdin);
            for(int i = 0 ;i<30 ;)
            {
                q=getch();
                if(q==13)
                {
                    break;
                }
                if(q=='\b')
                {
                    p.first[i]='0';
                    i--;
                    r.first[i]='0';
                    system("cls");
                    cout<<"\n\n\t\t\tConfirm Password: ";
                    for(int j = 0 ;j<i;j++)
                    {
                        cout<<'*';
                    }
                }
                else
                {
                    cout<<'*';
                    r.first[i]=q;
                    i++;
                }
            }
            cout<<"\n";
            if(p.first==r.first)
                return p.first;
            else{
                cout<<"\n\t\t\tPassword Doesn't Match!!!\n\n\t\t\t\tTry Again.....\n";
                system("pause");}
        }
    }

int passs(char temp[])
{
    int io=0;
    while(io<=2)
    {
    pair <string ,char >p;
    p.first="000000000000000000000000000000";
    char q;
    cout<<"\n\n\t\t\tPress Password: ";
    for(int i = 0 ;i<30 ;)
    {
        q=getch();
        if(q==13)
        {
            break;
        }
        if(q=='\b')
        {
            p.first[i]='0';
            i--;
            p.first[i]='0';
            system("cls");
            cout<<"\n\n\t\t\tPress Password: ";
            for(int j = 0 ;j<i;j++)
            {
                cout<<'*';
            }
        }
        else{
            cout<<'*';
            p.first[i]=q;
            i++;
        }
    }
    ifstream ax (temp);
    string r;
    ax>>r;
    r=to.decrypt(r,"Hitlar");
    if(p.first==r)
        return 1;
    else
        cout<<"\n\n\t\t\t\tWrong Password!!\n";
    //return 0;
    io++;
    }
    return 0;
}
};

#endif // PASS__H
