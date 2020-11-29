#include "ah.h"
#include "public_.h"
#include "pass_.h"
#include "public_.h"
#include "login_.h"
//using namespace std;

int main()
{
    char p;
    public_ a;
    login_ as;
    while(1)
    {
        system("cls");
        cout<<"\n\n\n\t\t\t1->log in\n\t\t\t2->Create New Account\n";
        fflush(stdin);
        p=getch();
        if(p==50)
            a.built_id();
        else if(p==49)
        {
            as.log_in();
        }
        else if(p=='~')
            break;
        else
            ;
    }
    return 0;
}
