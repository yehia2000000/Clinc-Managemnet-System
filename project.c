#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "struct_def.h"
#include "function_pro.h"

int main ()
{
	u32 type ; // the mode of entered person 
	u8 check ; // check number of trail of password 
	
	//head of the linked list 
    patient * head = NULL;
	
	// head of slots 
	slot * h_s =NULL;
	
	// position of the slots 
	u32 pos_slot ;
	
	
	// data of patient 
	u32 name [max_size]  ;
	u32 age ;
	u32 gender [max_size];
	u32 id ; 
	
	//checked data 
	u8 check_data;
	
	// position of patient 
	u32 position ;
	
	// feature of admin 
	u32 f_admin ; 
	// mode of user 
	u32 mode_user ;
	
	
slots (&h_s);
while (1)
{
	printf ("if you are admin enter <0>, if you are user enter <1> :");
	scanf ("%u",&type);
	switch (type)
	{
		// the admin mode 
		case 0 :
		check=password ();
		//stoping system 
		if (check == 3)
			return 0;
		//mode feature 
		else 
		{
			printf ("enter the function of the admin : add_patient <0>, edit_info <1>, reverse_paient<2>,cancel_reverse <3>");
			scanf ("%u",&f_admin);
			switch (f_admin)
			{
			// addition a new patient 
			case 0 :
			
			printf ("enter the data of node -> \n");
			enter_data (name , &age , gender, &id );
			check_data =check_id (head,id);
			if (check_data==1)
			{
			printf ("enter the position of the patient :");
			scanf ("%u",&position);
			
		    add_func (&head , position, name ,age ,gender,id);
			}
			else 
			{
				printf ("the entered id is exist .\n");
				continue;
			}
			break ;
			
			// edit information of patient 
			case 1 :
			printf ("enter the id :");
			scanf ("%u",&id);
			check_data =check_id (head,id);
			if (check_data ==0)
			{
			
			edit (&head , id);
			}
			else 
			{
				printf ("the id is not exist .\n");
				continue ;
			}
			break ;
			// reverse slot 
			case 2 :
			
			printf ("enter the id :");
			scanf ("%u",&id);
			check_data =check_id (head,id);
			if (check_data==0)
			{
				printf ("the available slots is 1:slot->( 2 to 2:30),2:slot->(2:30 to 3),3:slot->(3 to 3:30),4:slot->(4 to 4:30)"
				",5:slot->(4:30 to 5) :\n");
				
				display_slot (h_s);
				
				printf ("enter the location of the slots :");
				scanf ("%u",&pos_slot);
				
				reserve (&h_s,id,pos_slot);
				
				
				
			}
			else 
			{
				printf ("the id is not exist .\n");
				continue ;
				
				
			}
			break ;
			
			//delete  reversed slot 
			case 3 : 
			printf ("enter the positin of deleted slot :");
			scanf ("%u",&pos_slot);
			
			cancel_reserve (&h_s,pos_slot);
			
			
			break ; 
			
			
			default:
			printf ("your admin mode is not correct .\n");
			break ;
			
			}
		}
		
		break ;
		
		
		// the user mode 
		case 1 : 
		printf ("enter <0> if you want to view patient record , enter <1> if you want to view today reservation : ");
		scanf("%u",&mode_user);
		switch (mode_user)
		{
			
			case 0 :
			printf ("enter the id :");
			scanf ("%u",&id);
			view_patient(head,id);
			break ;
			case 1 : 
			display_reserv (h_s);
			
			break ;
			default :
			printf ("the user mode is not correct./n");
			continue ;
			break;
			
			
		}
		break ;
	
		
		default :
		printf ("please enter the correct mode of your configuration .");
		
		
	}
}
	
}