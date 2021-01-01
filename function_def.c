#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "struct_def.h"


u8 password ()
{
	u8 count =0 ;
	u32 pass ;
	
	while (count < 3)
	{
		
		if (count ==0 )
		{
			printf ("enter the password :");
			scanf ("%u",&pass);
		}
		else 
		{
			
			printf ("please enter the correct password :");
			scanf ("%u",&pass);
		}
		if (pass == 1234)
		{
			break;
		}
		count++;
		
	}
	return count ;
	
}
void add_func (patient ** head_ref , u32 pos, u32 na [] ,u32 ag ,u32 ge [],u32 id_p )
{
	u8 count =0; // calculate the number of nodes in patientt records 
	u8 i =0 ; // parameter that uses to find  he location of new patient 
	u8 j =0 ; // parameter that uses to acess the array 
	patient *new = (patient *) malloc (sizeof (patient));
	patient * last  = *(head_ref);
	patient * check = *(head_ref);
	
	// enter the data of the new data 
	
	for (j=0;na[j]!=0;j++)
	{
		new->name[j]= na[j] ;
	}
	j=0;
	for (j=0;ge[j]!=0;j++)
	{
		new->gender[j]= ge[j] ;
	}
	new-> age = ag ;
	
	new-> id= id_p ;
	
	if (pos ==0)
	{
		new->next=*(head_ref) ;
		*(head_ref)=new ;
		return ;
	}
	while (check!=NULL)
	{
		count++;
		check=check->next ;
		
	}
	if (pos > count)
	{
		printf ("your location is not correct .\n");
		return ;
	}
	else 
	{
		
		while (i<pos-1)
		{
			last = last -> next ;
			i++;
			
		}
		new ->next = last ->next;
		last->next =new ;
		
		
	}
	
	
}
void print (patient * head_ref)
{
	if (head_ref == NULL)
	{
		printf ("the list is empty.\n");
		return ;
	
	}
	while (head_ref != NULL)
	{
		printf ("%s\n",head_ref ->gender);
		head_ref = head_ref->next ; 
		
	}
	
}
void enter_data (u32 name [] , u32 * age , u32 gender[], u32 * id )
{
	printf ("enter the patient name : ");
	scanf ("%s",name);
	printf ("enter the age of patient :");
	scanf ("%u",age);
	printf ("enter the gender of the patient :");
	scanf (" %s",gender);
	printf ("enter the id of the patient :");
	scanf ("%u",id);
	
	
}
u8 check_id (patient *head_ref ,u32 id)
{
	
	while ((head_ref)!=NULL)
	{
		if (head_ref->id == id)
		{
			return 0 ;
		}
		head_ref= head_ref->next;
		
	}
	return 1 ;
	
}

void edit (patient ** head_ref , u32 id)
{
	u32 str [max_size]; //save the string in variable
	u8 num ; //save the integer number in variable
	u8 mode ;
	u8 j;
	patient * index = *(head_ref);
	if ((*head_ref)->id ==id)
	{
		printf ("enter the mode of editon : name_edition <0>,age_edition <1>,gender_edition <2>,id_edition <3>:");
		scanf ("%u",&mode);
		switch (mode)
		{
			case 0 :
			printf ("the edition of the name  :");
			scanf ("%s",(*head_ref)->name);
			
			return ;
			
			case 1 :
			printf ("the edition of the age  :");
			scanf ("%u",&(*head_ref)->age);
			
			return ;
			
			case 2 :
			printf ("the edition of the gender  :");
			scanf ("%s",(*head_ref)->gender);
			
			return;
			
			case 3 :
			printf ("the edition of the id  :");
			scanf ("%u",&(*head_ref)->id);
			
			return;
			
			default :
			printf ("your adition mode is not corrrect . \n");
		}	
		
	}
	
	while ((index->next)!=NULL)
	{
	if ((index->next)->id ==id)
	{
		printf ("enter the mode of editon : name_edition <0>,age_edition <1>,gender_edition <2>,id_edition <3>:");
		scanf ("%u",&mode);
		switch (mode)
		{
			case 0 :
			printf ("the edition of the name  :");
			scanf ("%s",str);
			for (j=0;str[j]!=0;j++)
			{
				(index->next)->name[j] = str[j] ;
			}
			
			return;
			
			case 1 :
			printf ("the edition of the age  :");
			scanf ("%u",&num);
			(index->next)->age = num;
			return;
			
			case 2 :
			printf ("the edition of the gender  :");
			
			scanf ("%s",str);
			
			for (j=0;str[j]!=0;j++)
			{
				(index->next)->gender[j] =  str[j] ;
			}
			
			return;
			
			case 3 :
			printf ("the edition of the id  :");
			scanf ("%u",&num);
			(index->next)->id= num;
			return;
			
			default :
			printf ("your adition mode is not corrrect . \n");
			
			continue ;
			
		}
		
	}
	index=index->next ;
	
	}
	
	printf ("your id is not correct .\n ");

}


void slots (slot ** head_ref)
{
	slot * first = (slot *) malloc (sizeof (slot));// 2 to 2:30
	slot * second=(slot *) malloc (sizeof (slot));// 2:30 to 3
	slot * third =(slot *) malloc (sizeof (slot));// 3 to 3:30
	slot * forth=(slot *) malloc (sizeof (slot));//4 to 4:30
	slot * fifth =(slot *) malloc (sizeof (slot));// 4:30 to 5
	
	//if id is become zero the slots is available 
	first->data_id =0 ;
	second->data_id =0 ;
	third->data_id =0 ;
	forth ->data_id =0 ;
	fifth ->data_id =0 ;
	
	//connection between the lists
    *(head_ref) = first ;
	first->next =second ;
	second -> next = third ;
	third -> next = forth ;
	forth -> next = fifth ;
	fifth ->next =NULL;
	

}
void reserve (slot ** head_ref,u32 id , u32 pos_slot)
{
	slot * index = *head_ref ;
	u32 i =1 ;
	if ((pos_slot>5)||(pos_slot<=0))
	{
		printf ("enter the correct position ");
		return;
		
	}
	else if (pos_slot ==1)
	{
		(*head_ref) -> data_id = id ;
		return;
	}
	while (i<pos_slot-1)
	{
		index = index ->next ;
		i++;
	}
	index -> next ->data_id =id ;
	return;
}
//available slots
void display_slot (slot * head_ref )
{
	u32 i =0 ;
	
	while (i< 5)
	{
		if ((head_ref -> data_id)==0)
		{
			printf ("the %u:slot is avaliable \n",i+1);
			
			
		}
		i++;
		head_ref=head_ref->next;
	}
	
}

void cancel_reserve (slot ** head_ref,u32 pos_slot )
{
	slot * index = *head_ref ;
	u32 i =1 ;
	if ((pos_slot>5)||(pos_slot<=0))
	{
		printf ("enter the correct position ");
		return;
		
	}
	else if (pos_slot ==1)
	{
		(*head_ref) -> data_id = 0 ;
		return;
	}
	while (i<pos_slot-1)
	{
		index = index ->next ;
		i++;
	}
	index -> next ->data_id =0 ;
	return;
	
}


void view_patient(patient * head_ref,u32 id)
{
	patient * index = (head_ref);
	u8 check_data ;
	check_data =check_id (head_ref , id);
	if (check_data ==0)
	{
	while (index -> id !=id)
	{
		
		index = index ->next; 
		
	}
	}
	else 
	{
		printf ("the id is not exist . \n ");
		return;

	}
	printf ("the data of patient ->\n");
	printf ("patient name is %s \n",index->name);
	printf ("patient age is %u \n",index->age);
	printf ("patient gender is %s \n",index->gender);
	printf ("patient id is %u \n\n",index->id);
	
}
void display_reserv (slot * head_ref )
{
	u32 i =0 ;
	
	while (i< 5)
	{
		if ((head_ref -> data_id)!=0)
		{
			printf ("the %u:slot is reservation \n",i+1);
			
			
		}
		i++;
		head_ref=head_ref->next;
	}
	
}



