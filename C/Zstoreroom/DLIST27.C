/*
   Q- what is the Live example of LinkedList ?
 Ans- any type of data store in system buffer, stored as LinkedList.
   Q- what is the Live example of Double LinkedList?
 Ans- Undo + redu in IDE & browser back + forward button, Image viewer � Previous and next images are the Live example
      of linked List, PlayList design in Media Player.
   Q- what is the Live example of Stack?
 Ans- function calling in C & C++, Recursive function calling & OS is the best example stack.
   Q- Live example for Queue ?
 Ans- Songs play in Player / database accept request from the client & process that, printer - spooling, file save + open
      + Internet browsing, audio & video recording & playing.

 Wel.c -> after Compile - 3 Files design - 1. Wel.exe (Executable) + Wel.obj - Object file - linking file - both file
			  design inside bin folder, + Wel.bak - Backup file contain the errors, if no error in ur source
			  code then design the backup of ur code.

*/
#include<stdio.h>
#include<string.h>
struct Student
{
   int roll;
   char name[20];
   int marks;
};
struct Node
{
  struct Student s; // for node value - now node value is composite type
  struct Node *next,*prev; // for hold the ref of next node of same type.
};
struct Node *fst = NULL, *curr, *tmp,*pptr;
void addFirst()
{
    tmp = (struct Node *) malloc(sizeof(struct Node));
    printf("\n\n\n Plz Enter Roll , Name & Marks :  ");
    scanf("%d %s %d",&tmp->s.roll,tmp->s.name,&tmp->s.marks); // enter value for node with runtime input
    tmp->prev = NULL;
    tmp->next = fst;
    if(fst!=NULL)
      fst->prev = tmp;
    fst = tmp;
    printf("\n\n Node Successfully Inserted...");
}
void addLast()
{
    tmp = (struct Node *) malloc(sizeof(struct Node));
    printf("\n\n\n Plz Enter Roll , Name & Marks :  ");
    scanf("%d %s %d",&tmp->s.roll,tmp->s.name,&tmp->s.marks); // enter value for node with runtime input
    tmp->next = NULL;
    if(fst==NULL)
    {
      tmp->prev = NULL;
      fst = tmp;
    }
    else
    {
      curr = fst;
      while(curr->next!=NULL) // loop for jump on last node
	curr = curr->next;
      curr->next = tmp;
      tmp->prev = curr;
    }
    printf("\n\n Node Successfully Inserted...");
}
void disp()
{
   if(fst==NULL)
     printf("\n\n\n Sorry ur List is Empty.");
   else
   {
     clrscr();
     printf("\n  Elements in List r (in forward)- ");
     curr = fst;
     while(curr->next!=NULL)
     {
	printf("\n   %04d |  %-10s | %04d ",curr->s.roll,curr->s.name,curr->s.marks);
	curr = curr->next;
     }
     printf("\n    %04d |  %-10s | %04d ",curr->s.roll,curr->s.name,curr->s.marks); // print last node value.
     printf("\n Element is List r (in Reverse) - ");
     while(curr!=NULL)
     {
       printf("\n    %04d |  %-10s | %04d ",curr->s.roll,curr->s.name,curr->s.marks);
       curr = curr->prev;
     }
   }

}
void del()
{
   int n,flag = 0;
   if(fst==NULL)
     printf("\n\n\n Sorry ur List is Empty... ");
   else
   {
     clrscr();
     disp();
     printf("\n\n\n Plz Enter RollNo for delete record : ");
     scanf("%d",&n);
     pptr = curr = fst;
     while(curr!=NULL) // while list is not empty.
     {
       if(n==curr->s.roll) // if node exist.
       {
	 if(fst==curr) // if selected node is the 1st Node
	 {
	    fst = curr->next;
	    fst->prev = NULL;
	 }
	 else if(curr->next == NULL) // if selected node is the last node
	    pptr->next = curr->next;
	 else // if selected node is the mid or last node.
	 {
	    pptr->next = curr->next;
	    curr->next->prev = pptr;
	 }
	 free(curr);
	 flag = 1;
	 break;
       }
       pptr = curr;
       curr = curr->next;
     }
     if(flag)
       printf("\n\n Node Successfully Deleted.");
     else
       printf("\n\n Sorry Node not found...");
   }
}
void addMid()
{
   int n;
   if(fst==NULL)
      printf("\n\n\n Sorry ur List is Empty... ");
   else
   {
     clrscr();
     disp();
     printf("\n\n Plz Enter Node Roll No for add new Node just after that particular Node : ");
     scanf("%d",&n);
     curr = fst;
     while(curr!=NULL) // while list is not empty.
     {
       if(n==curr->s.roll) // if node exist.
       {
	  tmp = (struct Node *)malloc(sizeof(tmp));
	  printf("\n\n\n Plz Enter Roll , Name & Marks :  ");
	  scanf("%d %s %d",&tmp->s.roll,tmp->s.name,&tmp->s.marks); // enter value for node with runtime input
	 // for right side link.
	  curr->next->prev = tmp;
	  tmp->next = curr->next;
	// for left side link
	  curr->next = tmp;
	  tmp->prev = curr;

	  printf("\n\nNode Successfully Inserted...");
	  break;
       }
       curr = curr->next;
    }
  }
}
// for sorting
void sort()
{
   struct Student x;
   for(pptr=fst;pptr->next!=NULL;pptr=pptr->next)
   {
      for(curr=pptr->next;curr!=NULL;curr=curr->next)
      {
	 if(pptr->s.roll > curr->s.roll)
	 {
	    x = pptr->s;
	    pptr->s = curr->s;
	    curr->s = x;
	 }
	 /*
	 if(strcmpi(pptr->s.name,curr->s.name)>0)
	 {
	    x = pptr->s;
	    pptr->s = curr->s;
	    curr->s = x;
	 }
	 */
      }
   }
   printf("\n\n\t Values successfully Sort.............");
}

void main()
{
   char c;
   while(1)
   {
     clrscr();
     printf("\n\n\t\t1. Add New Node in Beginning.\n\n\t\t2. Add New Node in Last\n\n\t\t3. Add New Node in Mid \n\n\t\t4. List of All Node Values. \n\n\t\t5. Delete Existing Node \n\n\t\t6. for Sort values\n\n\t\t0. Exit\n\n\t Plz Enter ur Choice : ");
     c = getche();
     if(c=='1')
	addFirst();
     if(c=='2')
	addLast();
     if(c=='3')
	addMid();
     if(c=='4')
	disp();
     if(c=='5')
	del();
     if(c=='6')
	sort();
     if(c=='0')
       break;
     getch();
   }
}



