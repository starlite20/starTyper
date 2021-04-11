#include<fstream.h>
#include<conio.h> 
#include<dos.h>
#include<stdio.h>

char w;

void main() 
{ 

sleep(2); 

clrscr(); 

sleep(.5);
clrscr(); 
titlelooper.open("anim0.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();

sleep(1.5);
clrscr(); 
titlelooper.open("anim01.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();

sleep(2.5);
clrscr(); 
titlelooper.open("anim1.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();

sleep(.5);
clrscr(); 
titlelooper.open("anim2.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();

sleep(1);
clrscr(); 
titlelooper.open("anim3.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();

sleep(1);
clrscr(); 
titlelooper.open("anim4.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();


sleep(1);
clrscr(); 
titlelooper.open("anim5.txt");
while(!titlelooper.eof())
{
    titlelooper.get(th);
    cout<<th;
}
titlelooper.close();

sleep(3);

} 