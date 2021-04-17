#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<time.h>

int x,i,c,z;               //c:counter  i:just for loops  x:number of medicine   z:special counter
void both();               //clear screen + time
void waqt();               //current time
void nowhat();             //way to main menu or logout
void login();              //login page
void main_menu();          //main menu
void insert();             //for insert details
void display();            //for display details of all medicines
void search();             //for search by name or by code
void bill();               //billing purpose
//void sort();             //not working

    
void both()                //clear screen + time
     {
     	system("cls");
		waqt();
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tLive Life Well");
		printf("\n\t\t\t\tMEDi STORe");
	 }
FILE *file,*f;

void waqt()                //time
     {
        time_t rawtime;
        struct tm * timeinfo;
		time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        printf ( "\n\t\t\t\t\t\t\t\tCurrent local time and date: %s", asctime (timeinfo) );
     }


void nowhat()              //way to main menu or logout
    {
        int c=0;
         	printf("\n\n\n\t1.Main Menu\n\n\t2.Logout");
         	printf("\n\n\n\t\tChoice : ");
     	  	scanf("%d",&c);
     	  	if(c==1)
     	  	  main_menu();
     	  	else if(c==2)
			    { 
				 both();
			   	 printf("\n\n\n\t\tSuccessfully Logout\n\n\n");
			   	 getch();
				 exit(1);
				  }	
			else
			  {
			 	both();
			    printf("\n\n\n\t\tError\tLogging Out\n\n\n");
			    getch();
			    exit(1);
			  }
	}
	
struct insert              //struct having diff variables
    {
     int m_id;
     char m_name[10];      //first name
     char m_lname[10];     //last name
     char mfg_date[10];
     char exp_date[10];
     int conc;
     float m_price;
    }object[];
    

void login()               //login page
     { 
     both();
     c=0;
     char u[]="",p[]="",username[10],password[10];
     ps:
     printf("\n\n\t\t\tUsername : ");
     gets(username);
     printf("\n\t\t\tPassword : ");
     gets(password);
     if(!(strcmp(username,u)||strcmp(password,p)))
        {  
        	both();
	    	printf("\n\n\n\t\tLogin Successful\n\n\n\t\t");
			system("pause");
		}
	 else 
	    {   
			if(c==0)
        	   { 
        	    both();
        	    printf("\n\n\n\t\t\tWrong Username or Password \n\n\t\t\tEnter Again\n");
        	   	c++;
        	   	goto ps;
			   }
			else
			  { 
			   both();
			   printf("\n\n\n\t\tFailed to Login \n\n\t\tCalling 911\n\n\n");
			   exit(1);
			  }
	    }
   }
	 
void main_menu()           //main menu .. for different choice
     {      
            both();
	    	printf("\n\n\n\n\t1.Insert Details\n\n\t2.Display All Records\n\n\t");
			printf("3.Search of Some\n\n\t4.Update Some\n\n\t5.Billing\n\n\t6.Sorting The List\n\n\t7.Logout");
	    	printf("\n\n\n\tEnter your choice : ");
	        int choice;
	        c=0;
	        char rchoice;
	    	r:
	    	scanf("%d",&choice);
	    	switch(choice)
	    	  {
	    	  	case 1:insert();
	    	  	           break;
	    	  	case 2:z=1;
			       display();
	    	  	           break;
	    	  	case 3:search();
	    	  		   break;
	    	  	case 4:both();
				       printf("\n\n\n\tCode Not Written :P");
				       nowhat();
	    	  		   break;
	    	  	case 5:z=2;
				       bill();
	    	  		   break;
	    	    case 6://sort();
	    	           both();
	    	           printf("\n\n\n\tCode Not Written :P");
	    	           nowhat();
				   break;		   
	    	  	case 7:both();
				       printf("\n\n\n\t\tSuccessfully Logout\n\n\n");
	    	  	       getch();
	    	  	       exit(1);
	    	  	default:if(c==0)
	    	  	        { 
						  c++;
	      	              printf("\n\n\nInvalid selection\n\nWhat to Enter Again? \"YES\"(y) or \"NO\"(n) : ");
	      	              rchoice=getche();
	      	              if(rchoice=='y'||rchoice=='Y')
	      	              {
	      	              	printf("\n\n\tChoice : ");
	      	              	goto r;
							}
						  else if(rchoice=='n'||rchoice=='N')
						   { 
						    both();
						   	printf("\n\n\n\t\tSuccessfully Logout\n\n\n");
						   	getch();
						   	exit(1);
							   }	
						  else
						   {
						   	both();
						    printf("\n\n\n\t\tError\tLogging Out\n\n\n");
						    getch();
						    exit(1);
						   }
					   }
					else
					  { both();
					  	printf("\n\n\tLimit Exceeded\n\n\tLogging Out\n\n\n");
					  	getch();
					  	exit(1);
					  }  	   
	  	       }	
	  } 
	 
	 
	 
	 
void insert()              //input to file
     {  
     	both();
	    	  	       file=fopen("records.txt","a");
	    	  	       printf("\n\n\tInsertion Section");
	    	  	       printf("\n\n\n\tNumber of Medicine : ");
	    	  	       scanf("%d",&x);
	    	  	       for(i=0;i<x;i++)
	    	  	         {
						   printf("%d.",i+1);
	    	  	           printf("\n\tMedicine Code             : ");
	    	  	           scanf("%d",&object[i].m_id);
	    	  	           fflush(stdin);
	    	  	           printf("\tMedicine \n\t\t\t\tFirst Name_ ");
	    	  	           scanf("%s",object[i].m_name);
	    	  	           fflush(stdin);
	    	  	           printf("\t\t\t\tLast Name_ (if any) ");
	    	  	           scanf("%s",object[i].m_lname);
	    	  	           fflush(stdin);
	    	  	           printf("\tManufactured Date         : ");
	    	  	           scanf("%s",object[i].mfg_date);
	    	  	           fflush(stdin);
	    	  	           printf("\tExpiry Date               : ");
	    	  	           scanf("%s",object[i].exp_date);
	    	  	           fflush(stdin);
	    	  	           printf("\tConcentration per Gram(g) : ");
						   scanf("%d",&object[i].conc);
						   fflush(stdin);
						   printf("\tPrice Per Piece           : ");
	    	  	           scanf("%f",&object[i].m_price);
	    	  	           fflush(stdin);
	    	  	           fwrite(&object[i],sizeof(object[i]),4,file);
	    	  	         }
	    	  	         fclose(file);
	    	  	         both();
	    	  	         printf("\n\n\n\t\tData Saved");
	    	  	         nowhat();
	 }   
	 
	 
	 
void display()             //display details    
     {      
	        file=fopen("records.txt","r");
	        if(file==NULL)
	         {
	          both();	
	          printf("\n\n\t\tNothing To Display");
	          nowhat();
	         }
	        else
			  { 
		        both();
		        i=0;
		        printf("\n\n\n\tMedicine Code\tFirst Name\tLast Name\tMfg. Date\tExp. Date \tConc.(Grams) \tPrice(Rupees)\n");
		   	      while(fread(&object[i],sizeof(object[i]),4,file))
		   	       { 
		   	  	    printf("\n\t%d\t\t%s\t\t%s\t\t%s\t%s\t%d\t\t%.2f",object[i].m_id,object[i].m_name,object[i].m_lname,object[i].mfg_date,object[i].exp_date,object[i].conc,object[i].m_price);
				    i++;
				   }
				   
		      }
			 fclose(file);
			if(z==1)
			 nowhat();	 
	  }     


void search()              //search by name or by code
        {  
		    file=fopen("records.txt","r");
	        if(file==NULL)
	         {
	          both();	
	          printf("\n\n\t\tNo Records");
	          nowhat();
	         }
		    else
		      {
               int code,choice;
               char name[10],rchoice;
               search_again:
			   rewind(file);
			   both();  
         	   printf("\n\n\t1.Search by Code\n\n\t2.Search by Name");
         	   printf("\n\n\n\tChoice : ");
         	   scanf("%d",&choice);
         	switch(choice)
         	  {
         	  	case 1:both();
         	  	       printf("\n\n\tEnter Code : ");
         	  	       scanf("%d",&code);
         	  	       i=0,c=0;
         	  	       while(fread(&object[i],sizeof(object[i]),4,file))
         	  	          {
         	  	         	   
         	  	         	  if(object[i].m_id==code)
         	  	         	    {
         	  	         	    	c++;
									both();
		                            printf("\n\n\n\tMedicine Code\tFirst Name\tLast Name\tMfg. Date\tExp. Date\tConc.\tPrice\n");
		                            printf("\n\t%d\t\t%s\t\t%s\t\t%s\t%s\t%d\t%.2f",object[i].m_id,object[i].m_name,object[i].m_lname,object[i].mfg_date,object[i].exp_date,object[i].conc,object[i].m_price);
		                            fclose(file);
									nowhat();
								}
							  i++;
							  
							}
						if(c==0)
						  { 
						    fclose(file);
						   	printf("\n\n\tNo Medicine By Such Code");
						   	printf("\n\n\tWhat to Search Again? \"YES\"(y) or \"NO\"(n) : ");
						   	rchoice=getch();
						   	if(rchoice=='y'||rchoice=='Y')
							 goto search_again;   
							system("cls"); 
							both(); 
						   	nowhat();
						  }	
					   fclose(file);	
							
         	  		   break;
         	  		
         	  	case 2:both();
         	  		   c=0,i=0;
         	  		   printf("\n\n\tEnter Name : ");
         	  		   scanf("%s",name);
         	  		   while(fread(&object[i],sizeof(object[i]),4,file))
         	  		     {
         	  		      if(!(stricmp(name,object[i].m_name)))
         	  		       {
         	  		      	c++;
         	  		      	both();
		                    printf("\n\n\n\tMedicine Code\tFirst Name\tLast Name\tMfg. Date\tExp. Date\tConc.\tPrice\n");
		                    printf("\n\t%d\t\t%s\t\t%s\t\t%s\t%s\t%d\t%.2f",object[i].m_id,object[i].m_name,object[i].m_lname,object[i].mfg_date,object[i].exp_date,object[i].conc,object[i].m_price);
		                    fclose(file);
							nowhat();
         	  		   	  }
         	  		   	  i++;
         	  		    }
         	  		   if(c==0)
						   {
						   	close(file);
						   	printf("\n\n\tNo Medicine By Such Name");
						   	printf("\n\n\tWhat to Search Again? \"YES\"(y) or \"NO\"(n) : ");
						   	rchoice=getche();
						   	if(rchoice=='y'||rchoice=='Y')
						   	    goto search_again; 
						   	system("cls");
						   	both();
							nowhat();
							} 
						fclose(file);	
					    break;		
         	  		   
         	  	default:
				        c=0;
				        if(c==0)
	    	  	        { 
						  char rchoice;
						  c++;
	      	              printf("\n\n\n\tInvalid selection\n\n\tWhat to Enter Again? \"YES\"(y) or \"NO\"(n) : ");
	      	              scanf("%c",&rchoice);
	      	              if(rchoice=='y'||rchoice=='Y')
	      	              	goto search_again;
						  else if(rchoice=='n'||rchoice=='N')
						   { 
						    both();
						   	printf("\n\n\n\t\tSuccessfully Logout\n\n\n");
						   	getch();
						   	exit(1);
							   }	
						  else
						   {
						   	both();
						    printf("\n\n\n\t\tError\tLogging Out\n\n\n");
						    getch();
						    exit(1);
						   }
					   }
					else
					  { 
					    both();
					  	printf("\n\n\tLimit Exceeded\n\n\tLogging Out\n\n\n");
					  	getch();
					  	exit(1);
					  }  	   
			   }
		    }
		    fclose(file);
         }
         
     
	 	  
void bill()                //billing
    {    
    	display();
    	int bill,code[5],quan[5];
		float pay,c=0;
    	printf("\n\n\n\n\tNumber Of Medicine for Billing : ");
    	scanf("%d",&bill);
    	printf("\n\n\tEnter Their Code : ");
    	for(i=0;i<bill;i++)
          { 
            printf("\n\n\tCode : ");
    	   	scanf("%d",&code[i]);
            printf("\tQuantity : ");
            scanf("%d",&quan[i]);
          }	   
		file=fopen("records.txt","r");
		i=0;
		int j=0;
		while(!feof(file))
		  { 
		    fread(&object[i],sizeof(object[i]),4,file);
		    for(j=0;j<bill;j++)
		      {
		  	if(code[j]==object[i].m_id)
		  	  	pay=pay+(object[i].m_price)*quan[j];
		      }
		     i++;  
			}  
	     fclose(file);
	     printf("\n\tGrand Total : %.2f Rupees \t(Including all Taxes)",pay);
	     getch();
	     both();
	     nowhat();
	   }

  
/* void sort()                //not working
    {
      f=fopen("text.txt","w+");
      file=fopen("records.txt","r");
      x=0,i=0,c=0;
      int j=0,min;
      both();
      if(file==NULL)
	         {	
	          printf("\n\n\t\tNothing To Display");
	          nowhat();
	         }
	  else
	   {    
        printf("\n\n\tNumber of Medicine : ");
        scanf("%d",&x);
        while(fread(&object[i],sizeof(object[i]),4,file))
         { 
           
           for(i=0;i<x;i++)
             { 
			    fread(&object[i],sizeof(object[i]),4,file);
                min=object[0].m_id;
                for(c=0;c<x;c++)
                 { 
                    j=c;
             	if(min>object[c].m_id)
                   	j=c;
				   }
			  fwrite(&object[j],sizeof(object[j]),4,f);	   
 			 }
 			 
		 i++;
		 }

          fclose(file);
          printf("\n\n\n\tMedicine Code\tFirst Name\tLast Name\tMfg. Date\tExp. Date \tConc.(Grams) \tPrice(Rupees)\n");
		   	      while(!feof(f))
		   	       { 
		   	        fread(&object[i],sizeof(object[i]),4,f);
		   	  	    printf("\n\t%d\t\t%s\t\t%s\t\t%s\t%s\t%d\t\t%.2f",object[i].m_id,object[i].m_name,object[i].m_lname,object[i].mfg_date,object[i].exp_date,object[i].conc,object[i].m_price);
				    i++;
				   }			   
   	fclose(f);
     }
  }
  
   */  


         	
main()                     //main function
    {   
     system("COLOR F4");
     login();
     main_menu();
     getch();		
	 }	 
	  
	  
