#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int sid,d;
    int id,quantity;
    int bid,bquantity;
    char bname[150],bauther[150];
    char trackno[10000];
    double spri,price;
    char isu[100],sa[10000];
    char due[100],as[10000];
    char stname[150],h[10000];
    char name[100],r[10000];
    char auther[150],n[1000];
    char rackno[10000],p[100];
    struct node *next;
    struct node *prev;
}*head,*student,*teacher,*temp,*tail,*p,*q,*s;
void input();
void sinput();
void aviewadvis();
void st();
void ret();
void pas();
void ad();
void ret();
void issuerecord();
void issuebooks();
void retur();
void searchbooks();
void editbooks();
void addbooks();
void deletebooks();
void ssearchbooks();
void sviewbooks();
void stdnt();
void searchbooks()
{

    input();
    q=head;
    int s_id;
    printf("\nEnter search student id : ");
    scanf("%d",&s_id);
    FILE *fp;
    fp=fopen("Node.txt","r");
    while(head!=NULL)
    {
        if(head->id==s_id)
        {
            printf("\nID : ");
            printf("%d",head->id);
            printf("\nName : ");
            puts(head->name);
            printf("\nAuther : ");
            printf("%s",head->auther);
            printf("\nQuantity : ");
            printf("%d",head->quantity);
            printf("\nSingle Price : ");
            printf("%lf",head->spri);
            printf("\nTotal Price : ");
            printf("%lf",head->price);
            printf("\nRack No : ");
            printf("%s",head->rackno);
        }
        head=head->next;
    }
    printf("\n");
    printf ("Do You Search Another Book?(Y/N)" );
    if ( getch()== 'y' )
        searchbooks();
    else
        ad();
}
void ssearchbooks()
{

    input();
    q=head;
    int s_id;
    printf("\nEnter search student id : ");
    scanf("%d",&s_id);
    FILE *fp;
    fp=fopen("Node.txt","r");
    while(head!=NULL)
    {
        if(head->id==s_id)
        {
            printf("\nID : ");
            printf("%d",head->id);
            printf("\nName : ");
            puts(head->name);
            printf("\nAuther : ");
            printf("%s",head->auther);
            printf("\nQuantity : ");
            printf("%d",head->quantity);
            printf("\nSingle Price : ");
            printf("%lf",head->spri);
            printf("\nTotal Price : ");
            printf("%lf",head->price);
            printf("\nRack No : ");
            printf("%s",head->rackno);
        }
        head=head->next;
    }
    printf("\n");
    printf ("Do You Search Another Book?(Y/N)" );
    if ( getch()== 'y' )
        ssearchbooks();
    else
        retur();
}

void sinput()
{
    head=(struct node *)malloc(sizeof(struct node));
    tail = head;
    FILE *fp;
    fp=fopen("Issue.txt","r");
    int node_no = 1;
    while(1)
    {
        if( feof(fp) )
        {
            break ;
        }
        teacher=(struct node *)malloc(sizeof(struct node));
        fscanf(fp,"%d",&teacher->sid);
        fscanf(fp,"%s",&teacher->stname);
        fscanf(fp,"%d",&teacher->bid);
        fscanf(fp,"%s",&teacher->bname);
        fscanf(fp,"%s",&teacher->bauther);
        fscanf(fp,"%d",&teacher->bquantity);
        fscanf(fp,"%s",&teacher->trackno);
        fscanf(fp,"%s",&teacher->isu);
        fscanf(fp,"%s",&teacher->due);
        teacher->next=NULL;
        teacher->prev=tail;
        tail->next=teacher;
        tail=teacher;
        if(node_no ==1)
        {
            head=teacher;
        }
        node_no++;
    }
    if(tail==head)
    {
        tail=NULL;
    }
    else
    {
        tail=tail->prev;
        tail->next=NULL;
    }
    fclose(fp);
}
void input()
{
    head=(struct node *)malloc(sizeof(struct node));
    tail = head;
    FILE *fp;
    fp=fopen("Node.txt","r");
    int node_no = 1;
    while(1)
    {
        if( feof(fp) )
        {
            break ;
        }
        student=(struct node *)malloc(sizeof(struct node));
        fscanf(fp,"%d",&student->id);
        fscanf(fp,"%s",&student->name);
        fscanf(fp,"%s",&student->auther);
        fscanf(fp,"%d",&student->quantity);
        fscanf(fp,"%lf",&student->spri);
        fscanf(fp,"%lf",&student->price);
        fscanf(fp,"%s",&student->rackno);
        student->next=NULL;
        student->prev=tail;
        tail->next=student;
        tail=student;
        if(node_no ==1)
        {
            head=student;
        }
        node_no++;
    }
    if(tail==head)
    {
        tail=NULL;
    }
    else
    {
        tail=tail->prev;
        tail->next=NULL;
    }
    fclose(fp);
}
void editbooks()
{

    p=head;
    int s_id,i=0;
    printf("\nEnter search student id : ");
    scanf("%d",&s_id);
    FILE *fp;
    fp=fopen("Node.txt","w+");
    while(p!=NULL)
    {
        //char name[20];
        if(p->id==s_id)
        {
            char name[200],auther[150];
            char rackno[10000];
            double spri,price;
            int quantity;
            getchar();
            printf("\nEnter name(Single name) : ");
            gets(name);
            printf("\nEnter Auther name : ");
            gets(auther);
            printf("\ntEnter Quantity : ");
            scanf("%d",&quantity);
            printf("\nEnter Single Price : ");
            scanf("%lf",&spri);
            price=spri*quantity;
            printf("\nEnter Rackkno : ");
            scanf("%s",&rackno);
            fprintf(fp,"%d ",p->id);
            fprintf(fp,"%s ",name);
            fprintf(fp,"%s ",auther);
            fprintf(fp,"%d ",quantity);
            fprintf(fp,"%lf ",spri);
            fprintf(fp,"%lf ",price);
            fprintf(fp,"%s\n",p->rackno);
            printf("\n\t\tEdit successful");
            i++;
            getchar();
            getchar();
        }
        else
        {

            fprintf(fp,"%d ",p->id);
            fprintf(fp,"%s ",p->name);
            fprintf(fp,"%s ",p->auther);
            fprintf(fp,"%d ",p->quantity);
            fprintf(fp,"%lf ",p->spri);
            fprintf(fp,"%lf ",p->price);
            fprintf(fp,"%s\n",p->rackno);
        }
        p=p->next;
    }

    fclose(fp);
    if(i==0)
    {
        printf("\n\t\t\t\t\t\t\tNot found");
        getchar();
        getchar();
    }
    input();


    ret();
}

void viewbooks()
{

    input();
    q=head;
    printf("\n\n******************************************BOOK LIST*********************************************");
    printf("\n\nID \tNAME \tAUTHER   \tQUN.  \tSINGLEPRICE  \tPRICE  \t\tRACKNO: ");
    FILE *fp;
    fp=fopen("Node.txt","r");
    int i=0;
    while(q!=NULL)
    {
        fscanf(fp,"%d",&q->id);
        printf("\n%d",q->id);
        fscanf(fp,"%s",&q->name);
        printf("\t %s",q->name);
        fscanf(fp,"%s",&q->auther);
        printf("\t %s",q->auther);
        fscanf(fp,"%d",&q->quantity);
        printf("\t %d",q->quantity);
        fscanf(fp,"%lf",&q->spri);
        printf("\t %lf",q->spri);
        fscanf(fp,"%lf",&q->price);
        printf("\t%lf",q->price);
        fscanf(fp,"%s",&q->rackno);
        printf("\t%s\n",q->rackno);
        q=q->next;
        i++;

    }
    printf("\n\n******************************************BOOK LIST*********************************************");
    printf("\nTotal Book %d",i);

    ret();
}
void sviewbooks()
{
    input();
    q=head;
    printf("\n\n******************************************BOOK LIST*********************************************");
    printf("\n\nID \tNAME \tAUTHER   \tQUN.  \tSINGLEPRICE  \tPRICE  \t\tRACKNO: ");
    FILE *fp;
    fp=fopen("Node.txt","r");
    int i=0;
    while(q!=NULL)
    {
        fscanf(fp,"%d",&q->id);
        printf("\n%d",q->id);
        fscanf(fp,"%s",&q->name);
        printf("\t %s",q->name);
        fscanf(fp,"%s",&q->auther);
        printf("\t %s",q->auther);
        fscanf(fp,"%d",&q->quantity);
        printf("\t\t %d",q->quantity);
        fscanf(fp,"%lf",&q->spri);
        printf("\t  %lf",q->spri);
        fscanf(fp,"%lf",&q->price);
        printf("\t %lf",q->price);
        fscanf(fp,"%s",&q->rackno);
        printf("\t %s\n",q->rackno);
        q=q->next;
        i++;

    }
    printf("\n\n******************************************BOOK LIST*********************************************");
    printf("\nTotal Book %d",i);

    retur();
}
void ret( void )
{
    {
        printf ( " \n\nPress ENTER to return to main menu" );
    }
a:
    if ( getch()== 13 ) //allow only use of enter
        ad();
    else
        goto a;
}
void retur( void )
{
    {
        printf ( " Press ENTER to return to main menu" );
    }
a:
    if ( getch()== 13 ) //allow only use of enter
        stdnt();
    else
        goto a;
}
void rtn()
{
    s=head;

    sinput();
    int s_id,i=0;
    char n[100],p[150];
    char a[100];
    int si,id;
    printf("\n\t\t\t\t\t\tEnter search student id : ");
    scanf("%d",&s_id);
    printf("\n\t\t\t\t\t\tEnter search student Name : ");
    scanf("%s",&n);
    printf("\n\t\t\t\t\t\tEnter search Book id : ");
    scanf("%d",&si);
    printf("\n\t\t\t\t\t\tEnter search Book Name: ");
    scanf("%s",&p);
    printf("\n\t\t\t\t\t\tEnter search Author Name: ");
    scanf("%s",&a);
    FILE *fp;
    fp=fopen("Issue.txt","w+");
    while(s!=NULL)
    {

        if(s->sid == s_id && s->stname == n && s->bid == si && s->bname == p   && s->bauther == a)
        {
            printf("\n\tReturned successful");
            i++;


            getchar();
            getchar();
        }
        else
        {
            fprintf(fp,"%d ",s->sid);
            fprintf(fp,"%s ",s->stname);

            fprintf(fp,"%d ",s->bid);
               fprintf(fp,"%s ",s->bname);
            fprintf(fp,"%s ",s->bauther);
            fprintf(fp,"%d ",s->bquantity);
            fprintf(fp,"%s",s->trackno);
            fprintf(fp,"%s ",s->isu);
            fprintf(fp,"%s\n",s->due);
        }
        s=s->next;

    }
    fclose(fp);


    if(i==0)
    {
        printf("\n\t\t\tNot found");
        getchar();
        getchar();
    }
    sinput();
    printf ("\nReturned Another Book?(Y/N)" );
    if ( getch()== 'y' )
        rtn();
    else
        retur();
}
void issuerecord()
{
    char bname[100],stname[150];
    char bauther[100],trackno[10000];
    char isu[100],due[100];
    int sid,bid;
    int bquantity;
    printf("\nEnter Student ID : ");
    scanf("%d",&sid);
    printf("\nEnter Student name : ");
    scanf("%s",&stname);
    printf("\nEnter BOOK ID : ");
    scanf("%d",&bid);
    printf("\nEnter BOOK name : ");
    scanf("%s",&bname);
    printf("\nEnter Book Author Name : ");
    scanf("%s",&bauther);
    printf("\nQuantity:");
    scanf("%d",&bquantity);
    printf("\nRack No:");
    scanf("%s",&trackno);
    printf("\nIssue Date:");
    scanf("%s",&isu);
    printf("\nReturn Date:");
    scanf("%s",&due);
    FILE *fp;
    fp=fopen("Issue.txt","a+");
    fprintf(fp,"%d ",sid);
    fprintf(fp,"%s ",stname);

    fprintf(fp,"%d ",bid);
    fprintf(fp,"%s ",bname);
    fprintf(fp,"%s ",bauther);
    fprintf(fp,"%d ",bquantity);
    fprintf(fp,"%s\n",trackno);
    fprintf(fp,"%s ",isu);
    fprintf(fp,"%s\n",due);

    fclose(fp);
    system("cls");
    printf ("Add Another Book?(Y/N)" );
    if ( getch()== 'y' )
        issuerecord();
    else
        ret();
}
void is()
{
    sinput();
    q=head;
    printf("\n\n******************************************BOOK LIST*********************************************");
    printf("\n\nSTUDENTID STUDENTNAME BOOKID  BOOKNAME AUTHER    QUN   RACKNO   ISUDATE   RETDATE");
    FILE *fp;
    fp=fopen("Issue.txt","r");
    int i=0;
    while(q!=NULL)
    {
        fscanf(fp,"%d",&q->sid);
        printf("\n%d",q->sid);
        fscanf(fp,"%s",&q->stname);
        printf("\t  %s",q->stname);
        fscanf(fp,"%d",&q->bid);
        printf("\t   %d",q->bid);
        fscanf(fp,"%s",&q->bname);
        printf("\t     %s",q->bname);
        fscanf(fp,"%s",&q->bauther);
        printf("\t %s",q->bauther);
        fscanf(fp,"%d",&q->bquantity);
        printf("\t %d",q->bquantity);
        fscanf(fp,"%s",&q->trackno);
        printf("\t%s",q->trackno);
        fscanf(fp,"%s",&q->isu);
        printf("\t%s",q->isu);
        fscanf(fp,"%s",&q->due);
        printf("\t%s\n",q->due);
        q=q->next;
        i++;

    }
    printf("\n\n******************************************BOOK LIST*********************************************");
    printf("\nTotal Issue Book %d",i);
    printf ("Do You Want to View Issue Book?(Y/N)" );
    if ( getch()== 'y' )
        is();
    else
        ret();

}
void buy()
{
    input();
    q=head;
    char nam[150];
    printf("\nWhich Book You Want to Buy!(Enter BOOK NAME): ");
    scanf("%d",&nam);
    FILE *fp;
    fp=fopen("Node.txt","r");
    while(head!=NULL)
    {
        if(head->name==nam)
        {
            printf("\nID : ");
            printf("%d",head->id);
            printf("\nName : ");
            puts(head->name);
            printf("\nAuther : ");
            printf("%s",head->auther);
            printf("\nQuantity : ");
            printf("%d",head->quantity);
            printf("\nSingle Price : ");
            printf("%lf",head->spri);
            printf("\nTotal Price : ");
            printf("%lf",head->price);
            printf("\nRack No : ");
            printf("%s",head->rackno);
        }
        head=head->next;
    }
    printf("\nDo You Want to Buy This Book:(press 1)");
    if(getch()=='1')
    {
        int qn;
        double mot;
        printf("\nEnter Quantity:");
        scanf("%d",&q);
        FILE *fp;
        fp=fopen("Node.txt","w");
        int i=0;
        while(head!=NULL)
        {
            if(p->quantity>qn)
            {
                mot=qn*p->spri;
                p->quantity=p->quantity-qn;
                if(p->price>mot)
                {
                    p->price=p->price-mot;
                    fprintf(fp,"%d ",p->id);
                    fprintf(fp,"%s",p->name);
                    fprintf(fp,"%s",p->auther);
                    fprintf(fp,"%d",p->quantity);
                    fprintf(fp,"%lf ",p->spri);
                    fprintf(fp,"%lf",p->price);
                    fprintf(fp,"%s",p->rackno);
                }
            }
            fscanf(fp,"%d",&q->id);
            printf("\n%d",q->id);
            fscanf(fp,"%s",&q->name);
            printf("\t %s",q->name);
            fscanf(fp,"%s",&q->auther);
            printf("\t %s",q->auther);
            fscanf(fp,"%d",&q->quantity);
            printf("\t\t %d",q->quantity);
            fscanf(fp,"%lf",&q->spri);
            printf("\t  %lf",q->spri);
            fscanf(fp,"%lf",&q->price);
            printf("\t %lf",q->price);
            fscanf(fp,"%s",&q->rackno);
            printf("\t %s\n",q->rackno);
            q=q->next;
            i++;
            mot++;
        }
        printf("\nTotal Buy Book %d",i);
        printf("\nTotal Amount %.lf",mot);
        printf("\nPlease pay confirm:");
        printf ("Do You Want to Buy Any Book?(Y/N)" );
        if ( getch()== 'y' )
            buy();
        else
            retur();


    }

    else
    {

        printf("\n");
        printf("Not Found:");
    }

}
void issuebooks()
{

    system("cls");
    printf("****************************ISSUE SECTION******************************");
    printf ( "\n\n\xDB\xDB\xDB\xDB\xDB 1. Issue Book List\n" );
    printf ( "\n\n\xDB\xDB\xDB\xDB\xDB 2. Buy A Book\n" );
    printf ( "\n\n\xDB\xDB\xDB\xDb\xDB 3. Return A Book\n" );
    switch(getch())
    {
    case '1':
    {
        is();
        break;

    }


    case '2':
    {
        buy();
        break;
    }

    case '3':
    {
       // rtn();
        break;
    }
    }
}
void deletebooks()
{
    printf("\n\xDB\xDB\xDB\xDB\xB2 1.Whole Delete\n\t\t\xDB\xDB\xDB\xDB\xB2 2.Single Delete:");
    switch(getch())
    {
    case'1':
    {
        p=head;
        input();
        int s_id,i=0;
        printf("\n\t\t\t\t\t\tEnter search student id : ");
        scanf("%d",&s_id);
        FILE *fp;
        fp=fopen("Node.txt","w+");
        while(p!=NULL)
        {

            if(p->id==s_id)
            {
                printf("\n\t\t\t\t\t\t\tDelete successful");
                i++;
                getchar();
                getchar();
            }
            else
            {
                fprintf(fp,"%d ",p->id);
                fprintf(fp,"%s ",p->name);
                fprintf(fp,"%s ",p->auther);
                fprintf(fp,"%d ",p->quantity);
                fprintf(fp,"%lf ",p->spri);
                fprintf(fp,"%lf ",p->price);
                fprintf(fp,"%s\n",p->rackno);
            }
            p=p->next;
        }
        fclose(fp);


        if(i==0)
        {
            printf("\n\t\t\t\t\t\t\tNot found");
            getchar();
            getchar();
        }
        input();
        printf ("Delete Another Book?(Y/N)" );
        if ( getch()== 'y' )
            deletebooks();
        else
            ret();
    }
    case'2':
    {
        input();
        p=head;
        int s_id,i=1;
        printf("\nEnter search student id : ");
        scanf("%d",&s_id);
        FILE *fp;
        fp=fopen("Node.txt","w");
        while(p!=NULL)
        {
            //printf("%d %d",p->id,s_id);
            if(p->id==s_id)
            {
//       printf("%d",n);
                if(p->quantity>1)
                {
                    p->quantity--;
                    if(p->price>p->spri)
                    {
                        p->price=p->price - p->spri;
                        fprintf(fp,"%d ",p->id);
                        fprintf(fp,"%s ",p->name);
                        fprintf(fp,"%s ",p->auther);
                        fprintf(fp,"%d ",p->quantity);
                        fprintf(fp,"%lf ",p->spri);
                        fprintf(fp,"%lf ",p->price);
                        fprintf(fp,"%s \n",p->rackno);
                    }
                }
                else
                {
                    printf("\nDelete successful");
                    i++;
                    getchar();
                    getchar();
                }
            }
            else
            {
                fprintf(fp,"%d ",p->id);
                fprintf(fp,"%s ",p->name);
                fprintf(fp,"%s ",p->auther);
                fprintf(fp,"%d ",p->quantity);
                fprintf(fp,"%lf ",p->spri);
                fprintf(fp,"%lf ",p->price);
                fprintf(fp,"%s \n",p->rackno);
            }
            p=p->next;

        }
        fclose(fp);
        if(i==0)
        {
            printf("\nNot found");
            getchar();
            getchar();
        }
    }
    }
    input();
    printf ("Delete Another Book?(Y/N)" );
    if ( getch()== 'y' )
        deletebooks();
    else
        ret();

}
void isdel()
{
    p=head;

    int stid,i=0;
    printf("\n\t\t\t\t\t\tEnter search student id : ");
    scanf("%d",&stid);
    FILE *fp;
    fp=fopen("Issue.txt","w+");
    while(p!=NULL)
    {

        if(p->sid==stid)
        {
            printf("\n\tDelete successful");
            i++;
            getchar();
            getchar();
        }
        else
        {
            fprintf(fp,"%d ",p->sid);
            fprintf(fp,"%s ",p->stname);
            fprintf(fp,"%d ",p->name);
            fprintf(fp,"%d ",p->id);
            fprintf(fp,"%s ",p->auther);
            fprintf(fp,"%d ",p->quantity);
            fprintf(fp,"%s\n",p->rackno);
            fprintf(fp,"%lf ",p->isu);
            fprintf(fp,"%lf ",p->due);
        }
        p=p->next;
    }
    fclose(fp);


    if(i==0)
    {
        printf("\n\t\t\tLAST ONE IS DELETE:");
        getchar();
        getchar();
    }
    sinput();
    printf ("Delete Another Book?(Y/N)" );
    if ( getch()== 'y' )
        isdel();
    else
        ad();

}

void addbooks()
{
    char name[100],auther[150];
    char rackno[10000];
    int quantity;
    double spri,price;
    int id;
    printf("\nEnter your ID : ");
    scanf("%d",&id);
    printf("\nEnter BOOK name : ");
    scanf("%s",&name);
    printf("\nEnter your Auther Name : ");
    scanf("%s",&auther);
    printf("\nQuantity:");
    scanf("%d",&quantity);
    printf("\nSinglePrice:");
    scanf("%lf",&spri);
    printf("\nRack No:");
    scanf("%s",&rackno);
    price=spri*quantity;
    FILE *fp;
    fp=fopen("Node.txt","a+");
    fprintf(fp,"%d ",id);
    fprintf(fp,"%s ",name);
    fprintf(fp,"%s ",auther);
    fprintf(fp," \t%d ",quantity);
    fprintf(fp," %lf ",spri);
    fprintf(fp," %lf ",price);
    fprintf(fp," %s\n",rackno);

    fclose(fp);
    system("cls");
    printf ("Add Another Book?(Y/N)" );
    if ( getch()== 'y' )
        addbooks();
    else
        ret();
}
int t ( void ) //for time
{
    time_t t;
    time (&t);
    printf ( "\nDate and time: %s \n", ctime (&t));
    return 0 ;
}
void advis()
{
    char sa[10000],as[10000];
    char h[10000],di[10000];
    int d;
    printf("\n\n\tWhich Book:(ID)");
    scanf("%d",&d);
    printf("\nWhich Book:(Name)");
    scanf("%s",&sa);
    printf("\nComment:(What is Your Felling)");
    scanf("%s",&as);
    printf("\nGive Advising:");
    scanf("%s",&h);
    FILE *fp;
    fp=fopen("Advising.txt","a");
    fprintf(fp,"%d ",d);
    fprintf(fp,"%s ",sa);
    fprintf(fp,"%s ",as);
    fprintf(fp,"%s\n",h);

    fclose(fp);
    system("cls");
    printf ("Again This?(Y/N)" );
    if ( getch()== 'y' )
        advis();
    else
        retur();
}
void viewadvis()
{
    sinput();
    q=head;
    printf("\n******************************************ADVISING PORTAL*********************************************");
    printf("\n\nID    \tNAME    \tCOMMENT   \tADVISING ");
    FILE *fp;
    fp=fopen("Advising.txt","r");
    int i=0;
    while(q!=NULL)
    {
        fscanf(fp,"%d",&q->d);
        printf("\n%d",q->d);
        fscanf(fp,"%s",&q->sa);
        printf("\t %s",q->sa);
        fscanf(fp,"%s",&q->as);
        printf("\t %s",q->as);
        fscanf(fp,"%s",&q->h);
        printf("\t\t %s",q->h);
        q=q->next;
        i++;

    }
    printf("\nTotal Advising %d",i);

    retur();
}
void aviewadvis()
{
    sinput();
    q=head;
    printf("\n******************************************ADVISING PORTAL*********************************************");
    printf("\n\nID    \tNAME    \tCOMMENT   \tADVISING ");
    FILE *fp;
    fp=fopen("Advising.txt","r");
    int i=0;
    while(q!=NULL)
    {
        fscanf(fp,"%d",&q->d);
        printf("\n%d",q->d);
        fscanf(fp,"%s",&q->sa);
        printf("\t %s",q->sa);
        fscanf(fp,"%s",&q->as);
        printf("\t %s",q->as);
        fscanf(fp,"%s",&q->h);
        printf("\t\t %s",q->h);
        q=q->next;
        i++;

    }
    printf("\nTotal Advising %d",i);

    ret();
}
void ad()
{
    system ( "cls" );
    int i;
    printf ( "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB");
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 1. ADD BOOKS   " );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 2. DELETE BOOKS" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 3. EDIT BOOKS" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 4. SEARCH BOOKS" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 5. VIEW BOOK LIST" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 6. ISSUE BOOK" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 7. ADD ISSUE BOOK" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 8. REMOVE ISSUE BOOK" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 9. VIEW ADVISING" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 C. CLOSE APPLICATION" );
    printf ( "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB");
    t ();
    printf ( "Enter your choice" );
    switch ( getch())
    {
    case '1' :
        addbooks();
        break;
    case '2' :
        deletebooks();
        break;
    case '3' :
        editbooks();
        break ;
    case '4' :
        searchbooks();
        break ;

    case '5' :
        viewbooks();
        break;
    case '6' :
        issuebooks();
        break;
    case '7' :
        issuerecord();
        break;
    case '8' :
        isdel();
        break;
    case '9' :
        aviewadvis();
        break;
    case 'c' :
    {
        system ( "cls" );
        printf("\nProgrammers......\n\t\t:Tafsirul Ahsan\nContract:\n\t\tEmail:tafsirul15@diu.edu.bd\nphone:0010011\n\t\tWith the Unexplainable help:A S M Farhan al Haque sir,Bulbul vai,sayeed vai,shakkar vai,shihab\nExisting in 3 Second:......\n\n\t\tThank You All");

        exit (0 );
    }
    default:
    {
        printf ( "\aWrong Entry!!Please re-entered correct option" );
        if ( getch())
            ad();
    }
    }

}
int admin()
{
    int i,c=0,f=0;
    char uid[25],ps[25],suid[][25]= {"tafsirul","tafsirul","tafsirul"};
    char sps[][25]= {"tafsirul"},ch='a';
    printf("\nEnter user Name:");
    scanf("%s",uid);
    printf("Enter passowrd:");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
        else if(ch==8)
        {
            if(i!=0)
            {
                printf("\b");
                printf("%c",32);
                printf("\b");
                i--;
                ps[i]='\0';
            }
            else
                continue;
        }
        else
        {
            putchar('*');
            ps[i]=ch;
            i++;
        }
    }
    ps[i]='\0';
    for(i=0; i<=2; i++)
    {
        if((stricmp(uid,suid[i]))==0&&(strcmp(ps,sps[i]))==0)
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        printf("\n\n\t\tSuccessfully Login:(press any key)");

        getch();
        system ( "cls" );
        int i;
        printf ( "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB");
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 1. ADD BOOKS " );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 2. DELETE BOOKS" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 3. EDIT BOOKS" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 4. SEARCH BOOKS" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 5. VIEW BOOK LIST" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 6. VIEW ISSU BOOK" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 7. ADD ISSU BOOK" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 8. REMOVE ISSU BOOK" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 9. VIEW ADVISING" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 C. CLOSE APPLICATION" );
        printf ( "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB");
        t ();
        printf ( "Enter your choice" );
        switch ( getch())
        {
        case '1' :
            addbooks();
            break;
        case '2' :
            deletebooks();
            break;
        case '3' :
            editbooks();
            break ;
        case '4' :
            searchbooks();
            break ;

        case '5' :
            viewbooks();
            break;
        case '6' :
            issuebooks();
            break;
        case '7' :
            issuerecord();
            break;
        case '8' :
            isdel();
            break;
        case '9' :
            aviewadvis();
            break;
        case 'c' :
        {
            system ( "cls" );

            printf("\nProgrammers......\n\n\t\t:Tafsirul Ahsan\n\n\n\t\tEmail:tafsirul15@diu.edu.bd\n\t\tphone:0010011\n\n\nWith the Unexplainable help:A S M Farhan al Haque sir,Bulbul vai,\n\t\tsayeed vai,shakkar vai,shihab\n\nExisting in 3 Second:......\n\n\t\tThank You All\n\n");
            exit (0 );
        }
        default:
        {
            printf ( "\aWrong Entry!!Please re-entered correct option" );
            if ( getch())
                admin();
        }
        }
    }
    else
        printf("\nTry Again(wrong username or password):");
    getch();
    pas();
}
void stdnt()
{
    system ( "cls" );
    int i;
    printf ( "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 1. VIEW BOOK  " );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 2. ISSUE BOOK" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 3. SEARCH BOOK" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 4. ADD ADVISING" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 5. VIEW ADVISING" );
    printf ( "\n\xDB\xDB\xDB\xDB\xB2 6. CLOSE APPLICATION" );
    printf ( "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    // printf ( "Enter your choice" );
    switch ( getch())
    {
    case '1' :
        viewbooks();
        break;
    case '2' :
        issuebooks();
        break;
    case '3' :
        ssearchbooks();
        break;
    case '4' :
        advis();
        break;
    case '5' :
        viewadvis();
        break;
    case '6':
    {
        system ( "cls" );

        printf("\nProgrammers......\n\n\t\t:Tafsirul Ahsan\n\n\n\t\tEmail:tafsirul15@diu.edu.bd\n\t\tphone:0010011\n\n\nWith the Unexplainable help:A S M Farhan al Haque sir,Bulbul vai,\n\t\tsayeed vai,shakkar vai,shihab\n\nExisting in 3 Second:......\n\n\t\tThank You All\n\n");
        exit (0 );
    }
    default:
    {
        printf ( "\aWrong Entry!!Please re-entered correct option" );
        if ( getch())
            main();
    }
    }
}

void st()
{
    int i,c=0,f=0;
    char uid[25],ps[25],suid[][25]= {"tafsirul","tafsirul","tafsirul"};
    char sps[][25]= {"tafsirul"},ch='a';
    printf("\nEnter user Name:");
    scanf("%s",uid);
    printf("Enter passowrd:");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
        else if(ch==8)
        {
            if(i!=0)
            {
                printf("\b");
                printf("%c",32);
                printf("\b");
                i--;
                ps[i]='\0';
            }
            else
                continue;
        }
        else
        {
            putchar('*');
            ps[i]=ch;
            i++;
        }
    }
    ps[i]='\0';
    for(i=0; i<=2; i++)
    {
        if((stricmp(uid,suid[i]))==0&&(strcmp(ps,sps[i]))==0)
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        printf("\n\n\t\tLogin Successfully:");

        getch();
        system ( "cls" );
        int i;
        printf ( "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 1. VIEW BOOK   " );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 2. ISSUE BOOK" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 3. SEARCH BOOK" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 4. ADVISING" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 5. VIEW ADVISING" );
        printf ( "\n\xDB\xDB\xDB\xDB\xB2 6. CLOSE APPLICATION" );
        printf ( "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        // printf ( "Enter your choice" );
        switch ( getch())
        {
        case '1' :
            sviewbooks();
            break;
        case '2' :
            issuebooks();
            break;
        case '3' :
            ssearchbooks();
        case '4' :
            advis();
            break;
        case '5' :
            viewadvis();
            break;
        case '6':
        {

            system ( "cls" );
            printf("\nProgrammers......\n\t\t:Tafsirul Ahsan\nContract:\n\t\tEmail:tafsirul15@diu.edu.bd\nphone:0010011\n\t\tWith the Unexplainable help:A S M Farhan al Haque sir,Bulbul vai,sayeed vai,shakkar vai,shihab\nExisting in 3 Second:......\n\n\t\tThank You All");

            exit (0 );
        }
        default:
        {
            printf ( "\aWrong Entry!!Please re-entered correct option" );
            if ( getch())
                main();
        }
        }
    }
    else
        printf("\n\n\tTry Again(Wrong Username or Password):");
    getch();

    pas();


}
void pas()
{
    int i,c=0,f=0;
    char uid[25],ps[25],suid[][25]= {"tafsirul","tafsirul","tafsirul"};
    char sps[][25]= {"tafsirul"},ch='a';
    printf("\nEnter user Id:");
    scanf("%s",uid);
    printf("Enter passowrd:");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
        else if(ch==8)
        {
            if(i!=0)
            {
                printf("\b");
                printf("%c",32);
                printf("\b");
                i--;
                ps[i]='\0';
            }
            else
                continue;
        }
        else
        {
            putchar('*');
            ps[i]=ch;
            i++;
        }
    }
    ps[i]='\0';
    for(i=0; i<=2; i++)
    {
        if((stricmp(uid,suid[i]))==0&&(strcmp(ps,sps[i]))==0)
        {
            f=1;
            break;
        }
    }
    if(f)
        printf("\n\n\t\tSuccessfully Login");
    else
        printf("\n\n\t\tWrong Username or Password(Try Again):");
    getch();
}

int main()
{

    system("cls");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2WELLCOME TO LIBRARY MANAGEMENT SYSTEM\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    // printf ( "\n\n\xDB\xDB\xDB\xDB\xB2 1. Sign up " );
    printf ( "\n\n\xDB\xDB\xDB\xDB\xB2 1. STUDENT LOGIN  " );
    printf ( "\n\n\xDB\xDB\xDB\xDB\xB2 2. TEACHER LOGIN  " );
    printf ( "\n\n\xDB\xDB\xDB\xDB\xB2 3. ADMIN LOGIN  " );
    printf ( "\n\n\xDB\xDB\xDB\xDB\xB2 4. CLOSE APPLICATION \n" );
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    t();
    switch(getch())
    {


    case '1':
        st();
        break;
    case '2':
        st();
        break;
    case '3':
        admin();
        break;
    case '4':
    {
        system ( "cls" );

        printf("\nProgrammers......\n\n\t\t:Tafsirul Ahsan\n\n\n\t\tEmail:tafsirul15@diu.edu.bd\n\t\tphone:0010011\n\n\nWith the Unexplainable help:A S M Farhan al Haque sir,Bulbul vai,\n\t\tsayeed vai,shakkar vai,shihab\n\nExisting in 3 Second:......\n\n\t\tThank You All\n\n");
        exit (0 );
    }
    default:
    {
        printf ( "\aWrong Entry!!Please re-entered correct option" );
        if ( getch())
            main();
    }
    }
}

