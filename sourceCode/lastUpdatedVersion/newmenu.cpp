#include<iostream.h>
#include<conio.h>

void main()
{
    int menuctr=0;
    char choice;
    
    mainmenu:
    cout<<"MENU";
    switch(menuctr)
    {
        case 0  :   {
                        cout<<endl<<"PLAY";
                    }
                    break;
        case 1  :   {
                        cout<<endl<<"EDIT PROFILE";
                    }
                    break;
        case 2  :   {
                        cout<<endl<<"HISCORES";
                    }
                    break;
        case 3  :   {
                        cout<<endl<<"LEVEL CREATOR";
                    }
                    break;
    }
    

        while((choice!='g')||(choice!='G'))
        {
            
            if((choice=='d')||(choice=='D'))
            {
                if(menuctr==8)
                    menuctr=0;
                menuctr++;
                break;
            }
            else if((choice=='a')||(choice=='A'))
            {
                if(menuctr==0)
                    menuctr=8;
                menuctr--;
                break;
            }
            cin>>choice;
            getch();
            
        }
        goto mainmenu;
    }
                
                    
                    