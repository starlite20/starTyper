#include<fstream.h>
#include<conio.h> 
#include<dos.h>
#include<stdio.h>

char w;

void main() 
{ 
cout<<"TEST 1 GO"; 
char ch;
sleep(2); 

clrscr(); 
fstream titlelooper;

sleep(.5);
clrscr(); 
titlelooper.open("anim0.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();

sleep(1.5);
clrscr(); 
titlelooper.open("anim01.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();


    
sleep(2.5);
clrscr(); 
titlelooper.open("anim1.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();


sleep(.5);
clrscr(); 
titlelooper.open("anim2.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();


sleep(1);
clrscr(); 
titlelooper.open("anim3.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();


sleep(1);
clrscr(); 
titlelooper.open("anim4.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();


sleep(1);
clrscr(); 
titlelooper.open("anim5.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;
}
titlelooper.close();

sleep(1);
wrongbutton:
clrscr(); 
titlelooper.open("anim6.txt");
while(!titlelooper.eof())
{
    titlelooper.get(ch);
    cout<<ch;

}
if(!titlelooper)
  cout<<"Over";
titlelooper.close();
 cout<<"Over";

/*
w=cin.get();
cin.ignore();
*/
//getch();

if (kbhit()==0)
    w=_getch();

cout<<"Over";
cout<<endl<<endl<<w;

sleep(3);
if((w!='g'))
    goto wrongbutton;
else
    cout<<"ok";

getch();
} 