#ifndef LOGIN__H
#define LOGIN__H
#include "ah.h"
#include "public_.h"
#include "pass_.h"

class login_ : public public_
{
    public:
    void log_in()
    {

        system("cls");
    cout<<"\n\n\t\t\tEnter Your Account no:  ";
    gets(acname);
    strcpy(temp,path);
    strcat(temp,acname);
    strcat(temp,"\\Password.txt");
    FILE *f=fopen(temp,"r");
    if(f!=NULL)
    {
        int xy=passs(temp);
        system("cls");
        if(xy==1)
        {
            int pt;
            while(1)
            {
                time_t t=time(NULL);
                struct tm *p = localtime(&t);
                system("cls");
                cout<<"\n\n\t\t\t1->Balance Check.\n\t\t\t2->Withdraw Money.\n\t\t\t3->Transfer Money.\n\t\t\t4->Deposit Money\n\t\t\t5->Delete Account\n\t\t\t6->Log Out\n";
                pt=getch();
                pt=pt-48;
                if(pt==1)
                {
                    system("cls");
                    strcpy(temp,path);
                    strcat(temp,acname);
                    strcat(temp,"\\amount.txt");
                    FILE *f=fopen(temp,"r");
                    fscanf(f,"%lld",&balance);
                    cout<<"\n\n\t\t\tCurrent Balance:  "<<balance;
                    fclose(f);
                    cout<<endl<<"\n\n";
                }
                if(pt==2)
                {
                    system("cls");
                    long long int x;
                    cout<<"\n\n\t\t\tEnter the amount of Money to Withdraw:  ";
                    cin>>x;
                    strcpy(temp,path);
                    strcat(temp,acname);
                    strcat(temp,"\\amount.txt");
                    FILE *f=fopen(temp,"r");
                    fscanf(f,"%lld",&balance);
                    fclose(f);
                    if(x<=100000)
                    {
                    if(balance>=(x+500))
                    {
                    f=fopen(temp,"w");
                    balance=balance-x;
                    fprintf(f,"%lld",balance);
                    fclose(f);
                    strcpy(temp,path);
                    strcat(temp,acname);
                    strcat(temp,"\\history.txt");
                    {
                    FILE *f=fopen(temp,"a+");
                    fprintf(f,"%02d\\%02d\\%02d   %02d:%02d ------- %10lld tk -------   Withdraw     --- Total Money:%lld\n",p->tm_mday,p->tm_mon+1,p->tm_year+1900,p->tm_hour,p->tm_min,x,balance);
                    fclose(f);
                    }
                    }
                    else
                        cout<<"\n\n\t\t\tInsufficient Balance........\n";
                        cout<<"\n\n\n";
                }
                else  cout<<"\n\t\t\tYou Can't Withdraw More than \n\t\t\t\t100000 money per transaction.\n";
                }
                if(pt==3)
                {
                    system("cls");
                    long long int pal;
                    char acname1[10];
                    long long int x;
                    char temp2[150];
                    cout<<"\n\n\t\t\tEnter the account to Transfer:  ";
                    fflush(stdin);
                    gets(acname1);
                    {
                    strcpy(temp2,path);
                    strcat(temp2,acname1);
                    strcat(temp2,"\\password.txt");{
                    FILE *f=fopen(temp2,"r");
                    if(f==NULL)
                    {
                        fclose(f);
                        printf("\n\n\t\t\tThis Account Doesn't Exists..\n\t\t\t\tTry Again......\n");
                        cout<<"\n\n\n";
                        system("pause");
                        continue;
                    }
                    else
                        fclose(f);
                    }
                    }
                    {
                    strcpy(temp,path);
                    strcpy(temp2,path);
                    strcat(temp,acname);
                    strcat(temp2,acname1);
                    strcat(temp,"\\amount.txt");
                    strcat(temp2,"\\amount.txt");
                    fflush(stdin);
                    FILE *f=fopen(temp,"r");
                    fscanf(f,"%lld",&balance);
                    cout<<"\n\n\t\t\tEnter the amount of Money to Transfer:  ";
                    scanf("%lld",&x);
                    if(balance<(x+500))
                    {
                        printf("\n\n\t\t\tInsufficient Balance..\n\t\t\t\tTry Again......\n");
                        cout<<"\n\n\n";
                        system("pause");
                        continue;
                    }
                    balance=balance-x;
                    fflush(stdin);
                    fclose(f);
                    FILE *fp=fopen(temp2,"r");
                    fscanf(fp,"%lld",&pal);
                    pal=pal+x;
                    fclose(fp);
                    }
                    FILE *f=fopen(temp,"w");
                    FILE *fp=fopen(temp2,"w");
                    fprintf(fp,"%lld",pal);
                    fprintf(f,"%lld",balance);
                    fclose(f);
                    fclose(fp);
                    {
                    strcpy(temp,path);
                    strcat(temp,acname);
                    strcat(temp,"\\history.txt");
                    strcpy(temp2,path);
                    strcat(temp2,acname1);
                    strcat(temp2,"\\history.txt");
                    FILE *fp=fopen(temp,"a");
                    fprintf(fp,"%02d\\%02d\\%02d   %02d:02%d ------- %10lld tk -------   Transferred  --- Total Money:%lld\n",p->tm_mday,p->tm_mon+1,p->tm_year+1900,p->tm_hour,p->tm_min,x,balance);
                    fclose(fp);

                    FILE *f=fopen(temp2,"a+");
                    fprintf(f,"%02d\\%02d\\%02d   %02d:02%d ------- %10lld tk -------   Received     --- Total Money:%lld\n",p->tm_mday,p->tm_mon+1,p->tm_year+1900,p->tm_hour,p->tm_min,x,pal);
                    fclose(f);
                    }
                }
                if(pt==4)
                {
                    system("cls");
                    long long int x;
                    cout<<"\n\n\t\t\t\tEnter the amount of Money to Deposit:  ";
                    cin>>x;

                    strcpy(temp,path);
                    strcat(temp,acname);
                    strcat(temp,"\\amount.txt");

                    FILE *f=fopen(temp,"w+");
                    fscanf(f,"%lld",&balance);
                    balance=balance+x;
                    fprintf(f,"%lld",balance);
                    fclose(f);

                    strcpy(temp,path);
                    strcat(temp,acname);
                    strcat(temp,"\\history.txt");
                    {
                    FILE *f=fopen(temp,"a+");
                    fprintf(f,"%02d\\%02d\\%02d   %02d:%02d ------- %10lld tk -------   Deposit      --- Total Money:%lld\n",p->tm_mday,p->tm_mon+1,p->tm_year+1900,p->tm_hour,p->tm_min,x,balance);
                    fclose(f);
                    }
                }
                if(pt==5)
                {
                    strcpy(temp,path);
                    strcat(temp,acname);
                    if(!rmdir(temp)){
                        cout<<"Account Deleted!!!\n";
                    }
                    system("pause");
                    break;
                }
                if(pt==6)
                    break;

                system("pause");
            }
        }
        else{
            cout<<"\n\n\t\t\tYou have pressed Wrong Password For 3 times !\n\n\t\t\t\tSo we gonna kick You Out for this Time.......\n";
            system("pause");
        }
    }
    else{
        cout<<"\n\n\t\t\tNamed This no Account Exists!!!\n\t\t\t\tTry Again.........\n";
        system("pause");
    }
}
};

#endif // LOGIN__H
