/*		_______
     |       |
		\      \
		 \      \
		  /     /
		 /     /
		/    /
	   /   / 
	  /  /
	  \/
 */
/*
	Name: ELECTRICITY BILLING SYSTEM
	Copyright: @ Copyright Protected | chaudharydesign | 2018
	Website: http://www.chaudharydesign.com
	Author: SANDIP CHAUDHARY
	Developers: SANDIP CHAUDHARY,ROSHAN LIMBU,NAMSANG NEMBANG
	Date: 10/12/18 06:47
	Description: It is a small powerful software that is visually and logically better for ELECTRICITY BILLING  that is written in C++ Programming Language.
*/

#include<iostream> //for input output stream regulation
#include<string.h> // for string manipulation
#include<fstream>
#include<stdlib.h> //using system color for theme
#include <windows.h>//Used in making gotoxy(int, int) function
#include <unistd.h> // for usleep function and loading function
#include <time.h>//To get system date and time
#include <math.h> //for mathematical operation (pow,sqrt)
#include <conio.h>//For getch(); getche() type of functions

#define APP "ELECTRICITY BILLING SYSTEM"
#define VERSION "1.0"
#define YEAR 2018
#define MAX 5

using namespace std;

//Global variable declaration
	FILE *fp,*fp1,*fp2,*fp3; //file defination
	char aa, date[13];
	char counterArr[5][12]={"Arjundhara","Anarmani","Shanischare","Budhabare","Dhulabari"};

//class initialiazation
class Bill{
	public:
	struct bill{
	int sc_no;
	int customer_id;
	char counter[30];
	int receipt_id;
	char customer_name[100];
	char payee_name[100];
	char bus_model[100];
	char departure_time[50];
	char arrival_time[50];
	char boarding_point[100];
	char drop_point[100];
	int total_seat;
	int available_seat;
	float fare;
}bill;

	struct customer{
	int sc_no;
	int customer_id;
	char counter[30];
	char customer_name[30];
	char customer_contact[30];
	char customer_address[50];
	char phase[20];
	int load;
	int initial_rdg;
	int due;
	char meter_no[30];
}customer;

};

class auth{
	private:
		string uname="admin", pass="admin";
	public:
	void _password(char buffer[],char key){
	     	char c;
         	int pos = 0;
           	do
            	{
           		 c = getch();
            		if( isprint(c) )
            		{
            			buffer[ pos++ ] = c;
            			cout<<key;
            		}
            		else if( c == 8 && pos )
            		{
            			buffer[ pos-- ] = '\0';
            			cout<<"\b \b";
           		}
            	}while( c != 13 );
	}
	
	bool attemptLogin(string user,string password){
		if(user.compare(uname)==0 && password.compare(pass)==0){
				return true;
			}
			return false;
	}
};

////////////Graphic class//////////////////////////////
class graphics{
	COORD coord = {0, 0};
	// gotoxy function////////////
	public:
	void gotoxy (int x, int y){
      coord.X = x;
      coord.Y = y; // X and Y coordinates
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   }
   // single rect function
	void single_rect(int x,int y,int l,int b){
    int i,m;
    gotoxy(x,y); printf("%c",218);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",196);
	}
    gotoxy(i,y); printf("%c",191);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",179);
            }
        }
    }
    gotoxy(x,m); printf("%c",192);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",196);
    }
    gotoxy(i,m); printf("%c",217);
}
//cls function//////////////
void cls(int x1,int y1,int x2, int y2){
    int i,j;
    for(i=y1;i<=y2;i++)
        for(j=x1;j<=x2;j++)
         {
            gotoxy(j,i); printf("%c",32);
         }
	}
	//bg function//////////////
void bg(int x1,int y1,int x2, int y2){
    int i,j;
    for(i=y1;i<=y2;i++)
        for(j=x1;j<=x2;j++)
         {
            gotoxy(j,i); printf("%c",177);
         }
	}
	//loader function/////////////////
	void loader(int x,int y){
	int i,j;
		for(j=0;j<5; j++){
			gotoxy(x,y);printf("o...");
			for(i=0; i<10; i++){		
    		usleep(i);
			}
			gotoxy(x,y);printf(".o..");
			for(i=0; i<10; i++){		
    		usleep(i);
			}
			gotoxy(x,y);printf("..o.");
			for(i=0; i<10; i++){		
    		usleep(i);
			}
			gotoxy(x,y);printf("...o");
			for(i=0; i<10; i++){		
    		usleep(i);
			}
		}
}
// date_output function///////////
void date_output(char date[]){ //mm/dd/yy ---> dd MMM, yyyy
    struct
    {
        int dd;
        char mm[4];
        int yyyy;
    }_date;

    char temp[15];
    int mm,c,i;
    _date.dd=(date[3]-48)*10+(date[4]-48);

    mm=(date[0]-48)*10+(date[1]-48);
    _date.yyyy=2000+(date[6]-48)*10+(date[7]-48);
switch(mm)
    {
        case 1: strcpy(_date.mm,"Jan"); break;
        case 2: strcpy(_date.mm,"Feb"); break;
        case 3: strcpy(_date.mm,"Mar"); break;
        case 4: strcpy(_date.mm,"Apr"); break;
        case 5: strcpy(_date.mm,"May"); break;
        case 6: strcpy(_date.mm,"Jun"); break;
        case 7: strcpy(_date.mm,"Jul"); break;
        case 8: strcpy(_date.mm,"Aug"); break;
        case 9: strcpy(_date.mm,"Sep"); break;
        case 10: strcpy(_date.mm,"Oct"); break;
        case 11: strcpy(_date.mm,"Nov"); break;
        case 12: strcpy(_date.mm,"Dec"); break;
    }

    temp[0]=(int)(_date.dd/10)+48;
    temp[1]=(int)(_date.dd%10)+48;
    temp[2]=32;
    temp[3]='\0';
    strcat(temp,_date.mm);
    temp[6]=',';
    c=0;
    temp[7]=32;
    for(i=3;i>=0;i--)
    {
        temp[8+c]=(int)(_date.yyyy/pow(10,i))+48;
        c++;
        _date.yyyy%=(int)pow(10,i);
    }
    temp[12]='\0';
    strcpy(date,temp);
    }

//initializing function
void initializing(){
		int i,j;
		system("cls");
		loader(35,13);
		for(i=0; i<5; i++){		
    	usleep(i);
		}
	}
};
////////////end of Graphics class//////////////////////////////

////////////Partial class//////////////////////////////
class partials : public graphics{
	
	//welcome function////////////
	public:
	 void splash(){
	 int i;
    system("cls");
    bg(0,0,79,24);
	 single_rect(20,8,57,12);
    gotoxy(25,10); cout<<APP;
	 		for(i=0; i<200; i++){		
    		usleep(i);
			}
	}
	
	void DashboardData(){
		
				single_rect(21,3,35,10);
				gotoxy(24,4);printf("Counter");
				gotoxy(24,6);cout<<"13"<<endl;
				
				single_rect(36,3,55,10);
				gotoxy(39,4);printf("Customers");
				gotoxy(39,6);cout<<"121"<<endl;
				
				gotoxy(59,6);printf("Phase");
				single_rect(56,3,79,10);
				
				gotoxy(23,12);cout<<"Welcome To "<<APP;
				single_rect(21,13,79,21);
				single_rect(21,11,79,21);

	}
	 void dashboard(){
	 int i,n;
			mainmenu:
				system("cls");
				menu(); //menu
				sidebar();//sidebar
				footer(); //footer
								
				DashboardData();
				gotoxy(2,22);scanf("%d",&n);
				if (n==27) exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key 
				switch(n){
					case 1:
						Billing(); //billing function
        				goto mainmenu;
        				break;
    				case 2:	
						Meter_reading(); //meter reading function
        				goto mainmenu;
        				break;
    				case 3:
						Customer(); //customer function
			        	goto mainmenu;
        				break;
    				case 4:
						Statistics(); //Statistics function
        				goto mainmenu;
        				break;
        			case 5:
						Setting(); //setting function
        				goto mainmenu;
        				break;
        			case 6:
						Theme(); //changing theme function
        				goto mainmenu;
        				break;
        			case 7:
        				exit(0); //exit function
        				goto mainmenu;
        				break;
        			default:
        				gotoxy(2,24);printf("Ohh ! What a scrap.");
        				printf("\a"); //a beep sound
        				goto mainmenu;
        				break;
    				}
	};

//login form
void login(){
	   char uname[100], pass[100]={0},pass1[100];
		system("cls");
		auth obj2;
		bg(10,5,25,10);
    	gotoxy(5,13); cout<<APP;
    	gotoxy(5,14); for(int i=0;i<27;i++) printf("%c",196);
    	gotoxy(6,15); cout<<"Developers:";
    	gotoxy(6,16); for(int i=0;i<25;i++) printf("%c",196);
    	gotoxy(6,17); cout<<"-> Sandip Chaudhary";
    	gotoxy(6,18); cout<<"-> Roshan Limbu";
    	gotoxy(6,19); cout<<"-> Namsang Nembang";
    	
		single_rect(37,4,75,6);
		single_rect(37,7,75,23);
    	gotoxy(53,5); cout<<"LOGIN";
    	
    	gotoxy(40,11); cout<<"Username";
		single_rect(50,10,70,12);
		
		gotoxy(40,15); cout<<"Password";
		single_rect(50,14,70,16); 
		
    	gotoxy(40,22); cout<<"Enter Your Username.";
    	gotoxy(51,11); gets(uname);
    	
		gotoxy(40,22); printf("Enter Password.      ");
    	gotoxy(51,15);
        obj2._password(pass,'*');
        strcpy(pass1,pass);
      bool isUser = obj2.attemptLogin(uname,pass1);
      if(isUser == 1){
      	initializing();
      	dashboard();
      }else{
      	cls(10,21,70,23);
   		single_rect(10,21,70,23);	
			gotoxy(12,22); printf("\a Sorry we cant find you.!! Please try again");
      	login();
      }
     }
	///menu function
void menu(){
	graphics obj;
	single_rect(21,0,79,2);
	gotoxy(25,1); cout<<APP;
	_strdate(date);
   date_output(date);
   gotoxy(60,1);printf("Date: %s",date); 
    _strdate(date);
}
//sidebar function////////////
void sidebar(){
	bg(2,3,5,4);
	gotoxy(7,3);printf("ADMIN");
	gotoxy(7,4);printf("(o) online");
	single_rect(0,0,20,6);
	single_rect(0,0,20,24);
	
	gotoxy(2,7);printf("1. Billing\n");
	gotoxy(2,9);printf("2. Meter Reading\n");
	gotoxy(2,11);printf("3. Customer\n");
	gotoxy(17,11);printf("%c",175);
	gotoxy(2,13);printf("4. Statistics\n");
	gotoxy(17,13);printf("%c",175);
	gotoxy(2,15);printf("5. Setting\n");
	gotoxy(17,15);printf("%c",175); 
	gotoxy(2,17);printf("6. Change Theme\n");
	gotoxy(2,19);printf("7. Exit\n");
	gotoxy(1,21);printf("---Your Choice----");
}
//footer function
void footer(){
		gotoxy(22,23);cout<<"version "<<VERSION;
		gotoxy(52,23);cout<<"Copyright protected | "<<YEAR;single_rect(21,22,79,24);
	
	}
	
void Billing(){
	Bill obj;
	fp=fopen("Database/billing.txt","a"); //file open
	system("cls");

	menu();
	sidebar();
	footer();
	
	gotoxy(0,7);printf("%c",219); 
	
	gotoxy(21,3);printf("-----Bill Entry Form---------------------------------------");                                                   
	gotoxy(21,5);printf("Bus no:");	single_rect(31,4,47,6);
	gotoxy(48,5);printf("Bus name:");single_rect(59,4,77,6);
	
	gotoxy(21,8);printf("Bus type:");single_rect(31,7,47,9);
	gotoxy(48,8);printf("Bus model:");single_rect(59,7,77,9);
	
	gotoxy(21,11);printf("Arrival :"); single_rect(31,10,47,12);
	gotoxy(48,11);printf("Departure:");single_rect(59,10,77,12);
	
	gotoxy(21,14);printf("Board p. :");single_rect(31,13,47,15);
	gotoxy(48,14);printf("Drop p.:");single_rect(59,13,77,15);
	
	gotoxy(21,17);printf("Total Seat:");single_rect(31,16,47,18);
	gotoxy(48,17);printf("Bus Fare:");single_rect(59,16,77,18);
	getch();
}

void Meter_reading(){
	
}

void Customer(){
	int choice;
	system("cls");
	menu();
	sidebar();
	footer();
	
	gotoxy(0,11);printf("%c",219);     
	
	DashboardData();
				
	bg(20,10,45,20);
	gotoxy(17,11);printf("%c",174); //>>
	gotoxy(19,11);printf("%c",177); 
	gotoxy(21,11);printf("1. Add Customer");   
	gotoxy(21,13);printf("2. Edit Customer");  
	gotoxy(21,15);printf("3. Delete Customer"); 
	gotoxy(21,17);printf("4. View Customer");           
	gotoxy(21,19);printf("5. Back");  


				gotoxy(2,22);scanf("%d",&choice);
				if (choice==27) exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key 
				switch(choice){
					case 1:
						AddCustomer();
        				break;
    				case 2:
    					EditCustomer();
        				break;
    				case 3:
    					DeleteCustomer();
        				break;
        			case 4:
        				ViewCustomer();
        				break;
        			case 5:
        				dashboard();
        				break;
        			default:
        				gotoxy(1,23);printf("Invalid Choice");
        				printf("\a"); //a beep sound
        				break;
    				}	
	getch();
}

void AddCustomer(){
	Bill obj;
	fp=fopen("Database/customer.txt","a"); //file open
	
	system("cls");
	menu();
	sidebar();
	footer();
		
	gotoxy(0,11);printf("%c",219); 
	
	gotoxy(21,3);printf("-----Customer Entry Form----------------------------------");                                                   
	gotoxy(21,5);printf("CustomerId:");	single_rect(31,4,47,6);
	gotoxy(48,5);printf("Meter No:");single_rect(59,4,77,6);
	
	gotoxy(21,8);printf("C. Name:");single_rect(31,7,47,9);
	gotoxy(48,8);printf("Address:");single_rect(59,7,77,9);
	
	gotoxy(21,11);printf("Contact :"); single_rect(31,10,47,12);
	gotoxy(48,11);printf("Branch:");single_rect(59,10,77,12);
	
	gotoxy(21,14);printf("Phase :");single_rect(31,13,47,15);
	gotoxy(48,14);printf("Load.:");single_rect(59,13,77,15);
	
	gotoxy(21,17);printf("Initial RDG:");single_rect(31,16,47,18);
	gotoxy(48,17);printf("Due Amt:");single_rect(59,16,77,18);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Customer Id.");
	customerForm:
	int c_id;
	fp1=fopen("Database/Customer.txt","r"); //file open
    gotoxy(32,5);scanf("%d",&c_id);
    int i=0;
	while(fread(&obj.customer,sizeof(obj.customer),1,fp1) == 1)
    {
        if(c_id==obj.customer.customer_id){
            i++;
		}
    }
	fclose(fp1);
	if(i==1){
	cls(21,19,79,21);
	gotoxy(21,20);printf("\a The Customer already Exists.");
	cls(31,4,47,6);single_rect(31,4,47,6);
	goto customerForm;
	}else{
		obj.customer.customer_id = c_id;
	}

   cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Meter No.");
	gotoxy(60,5);scanf("%s",&obj.customer.meter_no);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Customer Name.");
	gotoxy(32,8);scanf("%s",&obj.customer.customer_name);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Customer Address.");
	gotoxy(60,8);scanf("%s",&obj.customer.customer_address);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Contact Number.");
	gotoxy(32,11);scanf("%s",&obj.customer.customer_contact);
	
	branchName:
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Branch Name (Counter).");
	bg(59,13,75,20);
	//looping the branch
	for(int i=0; i<5; i++){
	gotoxy(60,i+14);cout<<i+1<<'.'<<counterArr[i];
	}
	//end of loop
	gotoxy(60,11);scanf("%s",&obj.customer.counter);
	
	cls(21,13,79,21);
	
	gotoxy(21,14);printf("Phase :");single_rect(31,13,47,15);
	gotoxy(48,14);printf("Load.:");single_rect(59,13,77,15);
	
	gotoxy(21,17);printf("Initial RDG:");single_rect(31,16,47,18);
	gotoxy(48,17);printf("Due Amt:");single_rect(59,16,77,18);
	
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Phase.");
	gotoxy(32,14);scanf("%s",&obj.customer.phase);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Load.");
	gotoxy(60,14);scanf("%d",&obj.customer.load);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Initial Meter RDG.");
	gotoxy(32,17);scanf("%d",&obj.customer.initial_rdg);
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Enter Previous Due");
	gotoxy(60,17);scanf("%d",&obj.customer.due);
	
	
	cls(21,19,79,21);
	gotoxy(21,20);printf("Are the informations above all correct? (Y/N)");	
   aa=getche();

    if (aa=='Y'||aa=='y' || aa==13)
    { 	
		fwrite(&obj.customer,sizeof(obj.customer), 1, fp);
        fclose(fp);
        cls(21,19,79,21);
		gotoxy(21,20);printf("Record Added Successfully!!");
        getch();
    }
    if(aa == 'n' || aa == 'N'){
    	AddCustomer();
	}
	if(aa ==27){
    	return;
	}
}
void EditCustomer(){
	
}
void DeleteCustomer(){
	
}
void ViewCustomer(){
	
}

void Statistics(){
		int choice;
	system("cls");
	menu();
	sidebar();
	footer();
	
	gotoxy(0,13);printf("%c",219);     
	
				
	DashboardData();
				
	bg(20,12,45,20);
	gotoxy(17,13);printf("%c",174); //>>
	gotoxy(19,13);printf("%c",177); 
	gotoxy(21,13);printf("1. Customer Detail");   
	gotoxy(21,15);printf("2. Meter Reading Detail");  
	gotoxy(21,17);printf("3. Billing Detail"); 
	gotoxy(21,19);printf("4. Back");           


				gotoxy(2,22);scanf("%d",&choice);
				if (choice==27) exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key 
				switch(choice){
					case 1:
						CustomerDetail();
        				break;
    				case 2:
    					MeterReadingDetail();
        				break;
    				case 3:
    					BillingDetail();
        				break;
        			case 4:
        				dashboard();
        				break;
        			default:
        				gotoxy(1,23);printf("Invalid Choice");
        				printf("\a"); //a beep sound
        				break;
    				}	
	getch();
}

void CustomerDetail(){
	
}
void MeterReadingDetail(){
	
}

void BillingDetail(){
	
}

void Theme(){
	int choice;
	system("cls");
	menu();
	sidebar();
	footer();
	
	gotoxy(21,3);cout<<"-----Change Theme----------------------------------------";
	gotoxy(0,17);printf("%c",219);
	
	single_rect(21,5,40,10);
	gotoxy(22,7);cout<<"1. LIGHT THEME";
	gotoxy(22,9);cout<<"2. DARK THEME";
	
	
	gotoxy(22,17);cout<<"Choice:";single_rect(31,16,47,18);
	cls(21,19,79,21);
	gotoxy(22,20);cout<<"Enter your choice.";
	single_rect(21,11,79,21);
	gotoxy(32,17);scanf("%d",&choice);
	switch (choice){
		case 1:{
			HANDLE  hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 241);
			return;
			break;
		}
		case 2:{
			HANDLE  hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 11);
			return;
			break;
		}
		default:{
			cls(21,19,79,21);
			gotoxy(22,20);printf("\a Sorry we haven\'t such choice.");
			single_rect(21,11,79,21);
			getch();
			return;
			break;
		}
	}	
	getch();
}

void Setting(){
	int choice;
	system("cls");
	menu();
	sidebar();
	footer();

	gotoxy(0,15);printf("%c",219);     
	
	DashboardData();
				
	bg(20,14,45,22);
	gotoxy(17,15);printf("%c",174); 
	gotoxy(19,15);printf("%c",177); 
	gotoxy(21,15);printf("1. Add Branch");   
	gotoxy(21,17);printf("2. Customer Type");  
	gotoxy(21,19);printf("3. Phase"); 
	gotoxy(21,21);printf("4. Back");           


				gotoxy(2,22);scanf("%d",&choice);
				if (choice==27) exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key 
				switch(choice){
					case 1:
						AddBranch();
        				break;
    				case 2:
    					CustomerType();
        				break;
    				case 3:
    					Phase();
        				break;
        			case 4:
        				dashboard();
        				break;
        			default:
        				gotoxy(1,23);printf("Invalid Choice");
        				printf("\a"); //a beep sound
        				break;
    				}	
	getch();
}

void AddBranch(){
	system("cls");
	menu();
	sidebar();
	footer();
	
		gotoxy(21,3);cout<<"-----Add Counter----------------------------------------";
		gotoxy(0,15);printf("%c",219); 
		for(int i=0; i<5; i++){
			gotoxy(21,i+5);cout<<counterArr[i];
		}
		getch();

}

void CustomerType(){

}

void Phase(){
	
}

};
////////////End of Partial class//////////////////////////////

int main(){
	
	SetConsoleTitle(APP);
	system("cls");
	partials obj;
	obj.AddCustomer();
//	obj.AddBranch();
//	obj.Billing();
//	obj.Customer();
//    obj.splash(); //splash sreen at beginning
    do
    {		obj.login(); //login form
		}while(1); //infinite loop incase any key other than Esc, A, or S is pressed.
} 

