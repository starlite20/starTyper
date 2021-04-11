/*   *typer   */

#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<ctime.h>
#include<dos.h>

class user
{
	int age;
   char name[25];
	char username[14];
	char password[14];
   int score;

   public:
   	user()
	 	{
	   	age=0;
	      score=0;
   	   strcpy(password,"NULL");
         strcpy(name,"NULL");
         strcpy(username,"NULL");
   	}

      ~user()
	   {
	       cout<<endl
	           <<endl<<"Thanks for playing! Do spread the game! ;)";
	   }

   	void getdata()
   	{
         cout<<endl<<"Enter your Name = ";
   	   gets(name);
     		cout<<"Enter your age = ";
	      cin>>age;
   	   cout<<endl<<"--->> USERNAME RULES"<<
	      		endl<<"**Min. 8 characters & Max. 14 characters"<<
					endl<<"**No Space or Special Characters Allowed"<<
      		 	endl<<endl<<"Enter a username = ";
	      cin>>username;
   	   cout<<endl<<"--->> PASSWORD RULES"<<
	      		endl<<"**Min. 8 characters & Max. 14 characters"<<
					endl<<"**No Space or Special Characters Allowed"<<
      		 	endl<<endl<<"Enter a password = ";
	      cin>>password;
   	}

   	char* getusername()
	   {
   		return(username);
	   }

    	char* getname()
      {
      	return(name);
      }

   	char* getpassword()
   	{
	   	return(password);
   	}

      int getscore()
      {
      	return(score);
      }

  		void display()
	   {
   	    cout<<"Name        :    "<<name<<endl
      	     <<"Age         :    "<<age<<endl
              <<"Scores      :    "<<score<<endl
         	  <<"Username    :    "<<username<<endl
          	  <<"Password    :    "<<password<<endl<<endl;
   	}

      void editname()
      {
      	cout<<endl<<"Previous Name           :   "<<name;
         cout<<endl<<"Enter the new name      :   ";
         gets(name);
      }

      void editage()
      {
      	cout<<endl<<"Previous Age            :   "<<age;
         cout<<endl<<"Enter the new age       :   ";
         cin>>age;
      }

      void editusername()
      {
      	cout<<endl<<"Previous Username       :   "<<username;
         cout<<endl<<"Enter the new username  :   ";
         gets(username);
      }

      void editpassword()
      {
      	cout<<endl<<"Previous Password       :   "<<password;
         cout<<endl<<"Enter the new password  :   ";
         gets(password);
      }

      void editscore()
      {
      	cout<<endl<<"Previous Score         :    "<<score;
	      cout<<endl<<"Enter new score        :    ";
         cin>>score;
      }

      void setscore(int newscore)
      {
          score+=newscore;
      }

};

struct hiscore
{
	char name[25];
	int score;
   int l;

   void putdata()
   {
   	cout<<endl<<name<<"\t\t"<<score;
   }
};

fstream fin;
fstream fout;
user player;
user playerchecker;
int opt;
int logincounter, loginlocator, passchecker;
int opt2;
long position;
char usernames[14], passwords[14];

int currentscore;
int levelnum,errors,i;
int hour,mins,sec;
int starthour, startmins, startsec;
int timer;

hiscore h;
int scores[40];
int temp;
int no_of_players=0;
int checkvalid;

char level5text[1000];

char ch, input[500];

char ccode[10];

char username_del[14];
int flag;
int selfdeleted;

char adminpasscode[15];

int validity();
void login();
void putdata();
void editprofile();

void play();
void times();
void calctime();
void scorer();

void updatescore();

void levelcreator();

void hiscore();

void cheatzone();

void deleteuser();

int adminaccess();

void main()
{

	cout<<"DATA INSIDE\n";
   putdata();

  login:
   cout<<"\n\nWelcome to *typer!";
    
   cout<<endl<<endl<<"Are you a new user?"
   	 <<endl<<"1. Yes     2. No";
   cin>>opt;

   if(opt==1)
   {
      cout<<endl<<"*_**_CREATING A PROFILE_**_*";
      cout<<endl<<"****************************";
     usernameexists:
      playerchecker.getdata();
    checkvalid=validity();
           if (checkvalid==1)
      {
      	fout.open("players.dat",ios::app|ios::binary);
         fout.write((char*)&playerchecker, sizeof(playerchecker));
         fout.close();
          
         strcpy(usernames,playerchecker.getusername());
         strcpy(passwords,playerchecker.getpassword());     
          fin.open("players.dat",ios::in|ios::binary);

   loginlocator=32000;
   logincounter=0;
   passchecker=0;
   fin.seekg(0);

   while(fin.read((char*)&player,sizeof(player)))
   {
   	logincounter++;
      if((strcmp(usernames,player.getusername())==0))
      {
      	loginlocator=logincounter;
         if((strcmp(passwords,player.getpassword())==0))
			{
         	passchecker=1;
         }
         break;
      }
   }
   fin.close();
          
      }
      else
      {
      	cout<<" USERNAME EXISTS "<<endl;
         goto usernameexists;
      }
   }

   else if(opt==2)
   {
     relogin:
   	login();
      if(loginlocator!=32000)
  		{
      	if(passchecker==0)
	      {
         	cout<<endl<<"Wrong Password entered!"
            	 <<endl<<"Please enter the correct username & password!\n";
            goto relogin;
         }

         else
         	cout<<"\nwelcome\n";
      }

      else
      {
      	cout<<endl<<"Wrong Username entered!"
           	 <<endl<<"Please enter the correct username & password!\n";
         goto relogin;
      }
   }

   else
   {
   	cout<<"INVALID OPTION";
      goto login;
   }

  menu:
	cout<<endl<<"MENU"<<endl;
   cout<<endl<<" 	1 	-->  Play"
   	 <<endl<<" 	2 	-->  Edit Profile"
   	 <<endl<<" 	3 	-->  Hi-Scores"
   	 <<endl<<" 	4 	-->  Cheat Zone"
   	 <<endl<<" 	5 	-->  Level Creator"
       <<endl<<" 	6 	-->  Delete User"
   	 <<endl<<" 	7 	-->  Log Out"
       <<endl<<" 	8 	-->  Exit"
   	 <<endl;
   cin>>opt;

   switch(opt)
   {
   	case 1	:	{
      					play();
      				}
                  break;

   	case 2	:	{
                     editprofile();
      				}
                  break;

   	case 3	:	{
                  	hiscore();
      				}
                  break;

   	case 4	:	{
                    	cheatzone();
      				}
                  break;

   	case 5	:	{
                    	levelcreator();
      				}
                  break;

	   case 6	:	{
      					if(adminaccess())
                    	{
                    		deleteuser();
	                    	if(selfdeleted==1)
	                    	{
                        	cout<<endl<<"You have been logged out as you deleted your own account!";
	                        goto login;
		      				}
	        		      }

	                	else
	                  	cout<<"Delete failed!";
      				}
                  break;

   	case 7	:	{
      					goto login;
      				}
                  break;

   	case 8	:	{
      					exit(0);
      				}
                  break;

      default	:	cout<<endl<<"Invalid Choice Entered"
      					 <<endl<<"*Please choose an option that is valid"
                      <<endl;

	}

   goto menu;
}

/*########FUNCTIONS########*/

void login()
{
	cout<<endl<<"###########################"
   	 <<endl<<"*_**_***_*_LOGIN_*_***_**_*"
       <<endl<<"---------------------------";

   cout<<endl<<"Enter your Username    =   ";
   cin>>usernames;
   cout<<"Enter your Password    =   ";
   cin>>passwords;

   fin.open("players.dat",ios::in|ios::binary);

   loginlocator=32000;
   logincounter=0;
   passchecker=0;
   fin.seekg(0);

   while(fin.read((char*)&player,sizeof(player)))
   {
   	logincounter++;
      if((strcmp(usernames,player.getusername())==0))
      {
      	loginlocator=logincounter;
         if((strcmp(passwords,player.getpassword())==0))
			{
         	passchecker=1;
         }
         break;
      }
   }
   fin.close();
}

void putdata()
{
	fin.open("players.dat",ios::in|ios::binary);
   fin.seekg(0);
   while(fin.read((char*)&player,sizeof(player)))
   {
   	player.display();
   }
   fin.close();
}


void editprofile()
{
	cout<<endl<<"*******************************************"
       <<endl<<"Details of your Account"
       <<endl<<"*******************************************"
       <<endl;
    
   fin.open("players.dat",ios::in|ios::binary);
   

   while(fin.read((char*)&player,sizeof(player)))
   {
   	if((strcmp(usernames,player.getusername())==0))
      {
      	if((strcmp(passwords,player.getpassword())==0))
         {
         	player.display();
            position=fout.tellg();
         }
      }
   }

   fin.close();

   cout<<endl<<"What detail would you like to modify?"
   	 <<endl<<"  1  -->  Name"
       <<endl<<"  2  -->  Age"
       <<endl<<"  3  -->  Username"
       <<endl<<"  4  -->  Password"
       <<endl<<"  5  -->  Nah, Im not changing anything"
       <<endl;
   cin>>opt2;

   switch(opt2)
   {
   	case 1	:	{
      					fout.open("players.dat",ios::in|ios::out|ios::binary);
                     
                     fout.seekg(0);
                     while(fout.read((char*)&player,sizeof(player)))
							{
                     	if(strcmp(usernames,player.getusername())==0)
                     	{
                        	fout.seekg(position);
									player.editname();
									fout.write((char*)&player,sizeof(player));
                           break;
                       	}
								position=fout.tellg();
                     }
							fout.close();
        				}
                  break;

      case 2	:	{
      					fout.open("players.dat",ios::in|ios::out|ios::binary);
                     position=fout.tellg();
                     fout.seekg(0);
                     while(fout.read((char*)&player,sizeof(player)))
							{
                     	if(strcmp(usernames,player.getusername())==0)
                       	{
                        	fout.seekg(position);
									player.editage();
									fout.write((char*)&player,sizeof(player));
                           break;
                       	}
								position=fout.tellg();
                     }
							fout.close();
        				}
                  break;

		case 3	:	{
      					fout.open("players.dat",ios::in|ios::out|ios::binary);
                     position=fout.tellg();
                     fout.seekg(0);
                     while(fout.read((char*)&player,sizeof(player)))
							{
                     	if(strcmp(usernames,player.getusername())==0)
                        {
                        	fout.seekg(position);
									player.editusername();
									fout.write((char*)&player,sizeof(player));
                           break;
      	               }
								position=fout.tellg();
                     }
							fout.close();
        				}
                  break;

      case 4	:	{
                  	fout.open("players.dat",ios::in|ios::out|ios::binary);
                     position=fout.tellg();
                     fout.seekg(0);
                     while(fout.read((char*)&player,sizeof(player)))
							{
                     	if(strcmp(usernames,player.getusername())==0)
                       	{
                        	fout.seekg(position);
									player.editpassword();
									fout.write((char*)&player,sizeof(player));
	                        break;
   	                  }
								position=fout.tellg();
                     }
							fout.close();
        				}
                  break;

      default	:	cout<<endl<<"O.K., Lets get back to the game! :)";
   }

}

void play()
{
  levelchoice:
	cout<<endl<<" LEVEL CHOICES "
       <<endl<<" 1  -->  LEVEL  1   :  Dr. A.P.J. Abdul Kalam"
       <<endl<<" 2  -->  LEVEL  2   :  Abu Dhabi"
       <<endl<<" 3  -->  LEVEL  3   :  "
		 <<endl<<" 4  -->  LEVEL  4   :  "
       <<endl<<" 5  -->  LEVEL  5   :  Customized Level"
       <<endl<<" 6  -->  Randomize";

  	cout<<endl<<"Choose an option = ";
   cin>>levelnum;
    
    if(levelnum==6)
    {
        levelnum=rand()%5+1;
    }

   switch(levelnum)
   {
   	case 1	:	{
      					fin.open("level1.txt");
      				}
                  break;

   	case 2	:	{
                  	fin.open("level2.txt");
      				}
                  break;

   	case 3	:	{
                  	fin.open("level3.txt");
      				}
                  break;

   	case 4	:	{
                  	fin.open("level4.txt");
      				}
                  break;

   	case 5	:	{
                  	fin.open("level5.txt");
      				}
                  break;

      default	:	cout<<endl<<"Invalid Choice Entered"
      					 <<endl<<"*Please choose an option that is valid"
                      <<endl;
      				goto levelchoice;
	}

   if((levelnum>0)&&(levelnum<7))
   {
   	while(fin.get(ch))
      {
      	cout<<ch;
      }
      fin.close();

      cout<<endl<<" Type this paragraph and press enter in.... ";
      cout<<endl<<"3";
      sleep(1);
      cout<<"  2";
      sleep(1);
      cout<<"  1!";
      sleep(1);
      cout<<"  GOOOO!!";

      times();
      starthour=hour;
      startmins=mins;
      startsec=sec;
      cout<<endl;
      gets(input);

      times();
      calctime();

      switch(levelnum)
	  	{
      	case 1	:	{
   	   					fin.open("level1.txt");
      					}
         	         break;

	   	case 2	:	{
	                  	fin.open("level2.txt");
	      				}
	                  break;

	   	case 3	:	{
	                  	fin.open("level3.txt");
	      				}
	                  break;

	   	case 4	:	{
	                  	fin.open("level4.txt");
	      				}
	                  break;

	   	case 5	:	{
	                  	fin.open("level5.txt");
	      				}
	                  break;
		}

      errors=0;
      i=0;
      while(fin.get(ch))
      {
      	if(input[i]!=ch)
         {
         	errors++;
         }
         i++;
      }
      fin.close();

      if(errors!=0)
      {
            if(errors>100)
                cout<<endl<<"You made "<<errors<<" Mistakes while typing! xD";
            else                
                cout<<endl<<"You made "<<errors<<" Mistakes while typing!";
        }
      scorer();

      cout<<endl<<"The Time you took to type is "<<timer<<" seconds!!";
      cout<<endl
          <<endl<<"** Your SCORE = "<<currentscore;

      player.setscore(currentscore);
      updatescore();
   }
}

void times()
{
	time_t currentTime;
   struct tm *localTime;
   time(&currentTime);                   // Get the current time
   localTime = localtime(&currentTime);  // Convert the current time to the local time

   hour=localTime->tm_hour;
   mins=localTime->tm_min;
   sec=localTime->tm_sec;

   cout << endl<<"Time : " <<hour<<":"<<mins<< ":" << sec <<endl;
}

void calctime()
{
   timer=0;
   timer+=((hour-starthour)*60*60);
   timer+=((mins-startmins)*60);
   timer+=(sec-startsec);
}

void scorer()
{
	if((timer*10)<2000)
   	currentscore=2000-(timer*10);
   currentscore-(errors/10);
}

void levelcreator()
{
   fstream fout;
	cout<<endl<<"LEVEL CREATION"
		 <<endl<<"Type a level of 100 words"
       <<endl;
   gets(level5text);

   fout.open("level5.txt");
   fout<<level5text;
   fout.close();

   cout<<endl<<endl<<"Level created Successfully!! :D";
}

void updatescore()
{
	fin.open("players.dat",ios::in|ios::binary);
   fout.open("temp.dat",ios::out|ios::binary);

   fin.seekg(0);

   while(fin.read((char*)&player,sizeof(player)))
   {
   	if(strcmp(usernames,player.getusername())==0)
      {
      	player.setscore(currentscore);
         fout.write((char*)&player,sizeof(player));
      }

      else
      	fout.write((char*)&player,sizeof(player));
   }
   fin.close();
   fout.close();
   remove("players.dat");
   rename("temp.dat","players.dat");
}

void cheatzone()
{
  reccode:
   cout<<endl<<"\nEnter the cheat code = ";
   cin>>ccode;

   if((strcmpi(ccode,"ST1598"))==0)
   {
   	cout<<endl<<"Cheat Activated"
      	 <<endl<<"You can modify the scores of your friends!";

   	fin.open("players.dat",ios::in|ios::binary);
      fout.open("temp.dat",ios::out|ios::binary);

      fin.seekg(0);

      while(fin.read((char*)&player,sizeof(player)))
      {
			if(strcmp(usernames,player.getusername())!=0)
         {
         	cout<<endl<<"We are modifying "<<player.getname()<<"'s Score"<<endl;
         	player.editscore();
            fout.write((char*)&player,sizeof(player));
         }

      	else
	      	fout.write((char*)&player,sizeof(player));
      }

      fin.close();
      fout.close();

      remove("players.dat");
      rename("temp.dat","players.dat");
   }

   else
   {
   	cout<<endl<<"Invalid Cheat Code! Please Enter a Valid Cheat Code!";
      goto reccode;
   }
}

void hiscore()
{
	fin.open("players.dat",ios::in|ios::binary);
   fin.seekg(0);

   while(fin.read((char*)&player,sizeof(player)))
   {
   	no_of_players+=1;
      scores[i]=player.getscore();
      i++;
   }

   fin.close();

   for(i=0;i<no_of_players;i++)
   {
   	for(int j=0;j<(no_of_players-1-i);j++)
      {
      	if(scores[j]<scores[j+1])
         {
         	temp=scores[j];
            scores[j]=scores[j+1];
            scores[j+1]=temp;
         }
      }
   }

   /*
   int l;
   for(i=0;i<no_of_players;i++)
   {
      for(int j=i+1;j<no_of_players;j++)
      {
         if(scores[i]==scores[j])
         {
            for (int k = j + 1, l = j; k < no_of_players; k++, l++)
            {
               if (scores[k] != scores[i])
               {
                  scores[l] = scores[k];
               }
               else
               {
                  l--;
               }
            }
            no_of_players=l;
         }
      }
   }
  */

   for(i=0;i<no_of_players;i++)
   	cout<<scores[i]<<' ';
   cout<<endl;
    
   fout.open("hiscores.dat",ios::out|ios::binary);
   
   for(i=0;i<no_of_players;i++)
   {
   	fin.open("players.dat",ios::in|ios::binary);
      fin.seekg(0);

      while(fin.read((char*)&player,sizeof(player)))
      {
         if(scores[i]==player.getscore())
         {
            strcpy(h.name,player.getname());
            h.score=player.getscore();

            fout.write((char*)&h,sizeof(h));
         }
      }
      fin.close();
    }
    fout.close();

   cout<<endl<<"**SCORESS**"
   	 <<endl<<"Name\t\tScore";

   fin.open("hiscores.dat",ios::in|ios::binary);
   fin.seekg(0);

   while(fin.read((char*)&h, sizeof(h)))
   {
   	cout<<endl;
      h.putdata();
   }
   fin.close();
}

int validity()
{
	flag=0;

   fin.open("players.dat",ios::in|ios::out|ios::binary);

   while(fin.read((char*)&player,sizeof(player)))
   {
   	if((strcmp(usernames,playerchecker.getusername())==0))
      	flag=1;
   }

   if(flag==0)
   	return(1);

   else
   	return(0);

    fin.close();
}

void deleteuser()
{
    cout<<endl<<"Enter the username to be deleted = ";
    gets(username_del);

    if(strcmp(username_del,usernames)==0)
    	selfdeleted=1;

    fin.open("players.dat",ios::in|ios::binary);
    fout.open("temp.dat",ios::out|ios::binary);

    flag=0;

    while(fin.read((char*)&player,sizeof(player)))
    {
    	if(strcmp(username_del,player.getusername())!=0)
      {
    		fout.write((char*)&player,sizeof(player));

         flag=1;
      }
    }

    fin.close();
    fout.close();

    remove("players.dat");
    rename("temp.dat","players.dat");

    if(flag==0)
        cout<<endl<<"Username not found!";

    else
        cout<<endl<<"Delete successful!";

}

int adminaccess()
{
    cout<<endl<<"Acquire Admin rights Passcode from Admin --> ";
    gets(adminpasscode);

    if(strcmp(adminpasscode,"password")==0)
    {
    	cout<<'y';
      return(1);
    }

    else
    	return(0);
}

