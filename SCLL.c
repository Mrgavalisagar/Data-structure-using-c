#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
   int info;
   node *next; 
}*list;

  struct node *create();
  void ins_beg(int);
  void ins_end(int);
  void ins_bet(int,int);
  int rem_beg();
  int rem_end();
  int rem_bet(int);
//   void search(int);
//   void count();
  void display();

void main()
{
    clrscr();
    int ch,z,x,af,n;
    
    do{
        printf("\n Enter your choice:");
        printf("\n1:insert begin \n 2: ins end \n3: ins bet \n 4: rem beg \n 5: rem end \n6: rem bet \n 7:search \n8:count \n9:display \n10:EXIT");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("\nEnter val to insert beg");
                    scanf("%d",&x);
                    ins_beg(x);
                    break;
            
            case 2:
                    printf("\nEnter val to insert end");
                    scanf("%d",&x);
                    ins_end(x);
                    break;
            
            case 3:
                    printf("\nAfter which node");
                    scanf("%d",&af);
                    printf("\nEnter val to insert bet");
                    scanf("%d",&x);
		            ins_bet(af,x);
                    break;
            
            case 4:
                    printf("\n rem beg");
                    z=rem_beg();
                    printf("\n%d",&z);
                    break;
            
            case 5:
                    printf("\n rem end");
                    z=rem_end();
                    printf("\n%d",&z);
                    break;
            case 6:
                     printf("\n rem bet");
                    z=rem_bet(af);
                    scanf("\n%d",&af);
                    break;
            
            // case 7:
            //        search(n);
            //         break;
            
            // case 8:
            //         count();
            //         break;

           case 9:
                   display();
                    break;
        }

    }while(ch!=10);
    getch();
}

struct node *create()
{
    node *z;
    z=new struct node;
    return(z);
}
void ins_beg(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=x;
        p->next=p;
        list=p;

    }
    else 
    {
    while(p->next!=list)
    {
        p=p->next;
    }
      q=create();
      q->info=x;
      q->next=p->next;
      p->next=q;
      list=q;
    }
}

void ins_end(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=x;
	    p->next=p;
        list=p;
    }
    else
    {
    while(p->next!=list)
    {
	p=p->next;
    }
      q=create();
      q->info=x;
      q->next=p->next;
      p->next=q;
    }
}
void ins_bet(int af,int x)
{
    node *p,*q;
    p=list;
    if(p==NULL||p->next==p)
    {
        printf("L L IS empty");
    }
    else
    {
	while(p->next!=list)
	{
	    if(p->info==af)
	    {
		q=create();
		q->info=x;
		p->next=q->next;
		p->next=q;
	    }
	    p=p->next;
	}
    }
}

int rem_beg()
{
    int z;
    node *p,*q;
    p=list;
    if(p==NULL)
    {
	printf("rem beg not possible");
    }
    else if(p->next==p)
    {
	z=p->info;
	free(p);
	list=NULL;
	return(z);
    }
    else
    {
        while(p->next!=list)
        {
          p=p->next;
        }
        q=p->next;
        z=q->info;
        p->next=q->next;
        free(q);
        list=q->next;
        return(z);
    }
 }

int rem_end()
{
    int z;
    node *p,*q;
    p=list;
    if(p==NULL)
    {
	printf("rem end not possible");
    }
    else if(p->next==p)
    {
	z=p->info;
	free(p);
	list=NULL;
	return(z);
    }
    else
    {
	while(p->next->next!=list)
	{
	  p=p->next;
	}
	 q=p->next;
	 z=q->info;
	 p->next=q->next;
	 free(q);
	 return(z);
    }
 }
 int rem_bet(int af)
 {
    int z;
    node *p,*q;
    p=list;
    if(p==NULL)

    {
        printf("\nnote possible");
    }
    else if(p->next==list&&p->next->next==list)

    {
	printf("\nremove not possible");
    }
    else{
        while(p->next!=list)
        {
            if(p->info==af)
            {
                q=p->next;
                z=q->info;
                p->next=q->next;
                free(q);
		return(z);
            }
            p=p->next;
	}
    }
 }
void display()
{
    node *p;
    p=list;
    do{
	printf("\t%d",p->info);
	p=p->next;
      }while(p!=list);
}