#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct art{
char name[40];
char bp[90];
char sa[90];
int age;
char date[18];

}s;
struct node
{
    char paintingname[90];
    char artistname[90];
    char dollar[5000];
    char year[60];
   char contact[60];
    struct node *link;
};
struct node *head;

FILE *fp;
long sz = sizeof(s);
int main()
{
    int ch;
    while(1){
        system("cls");
        printf("<== ART MANAGEMENT==>\n");
        printf("1.Take information\n");
        printf("2.ART Information\n");
        printf("3.search Information\n");
        printf("4.delete Information\n");
        printf("5.customer information\n");
        printf("6.Art Catagory\n");
        printf("7.Painting Information insert\n");
        printf("8. Painting Information\n");
        printf("0.Exit\n\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            exit(0);
            case 1:
            input();
            break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
             case 4:
                del();
                break;

        case 5:
                info();
                break;
        case 6:
            arcat();
            break;
                   case 7:
            system("cls");
            artistinsert();
            break;
            case 8:
            system("cls");
            artistdisplay();
            break;


        }

        printf("\n\nPress any key to continue...");
        getch();
    }
    return 0;
}



    void input(){
        char myDate[12];
        time_t t= time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
        strcpy(s.date,myDate);
        fp = fopen("art.txt","ab");
        printf("Enter Artist name: ");
        fflush(stdin);
        gets(s.name);
        printf("Enter Birth Place: ");
        fflush(stdin);
        gets(s.bp);
        printf("Enter Style of art: ");
        fflush(stdin);
        gets(s.sa);
        printf("Enter Age: ");
       scanf("%d",&s.age);
       fwrite(&s, sz, 1, fp);
       printf("Record saved successfully...");
       fclose(fp);
    }
 void display(){
     system("cls");
      printf("<== ARTIST Information ==>\n");
      printf("%-30s %-20s %-20s %-10s %s\n", "name", "BirthPlace", "Style of art",  "Age", "Date");
      fp = fopen("art.txt","rb");
      while(fread(&s, sz, 1, fp) == 1){
            printf("%-30s %-15s %-25s %-5d %s\n", s.name, s.bp, s.sa, s.age, s.date);
      }
      fclose(fp);
 }
void search()
{
int ch;
while(1){
    system("cls");
    printf("<== Search==>\n");
    printf("1.search by name\n");
    printf("2.search by style of art\n");
     printf("0.Back To Main Menu\n");
    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 0:
        main();
        break;
    case 1:
        searchByName();
        break;
        case 2:
        searchByArt();
        break;
    default:
        printf("Invalid Choice");
    }
    getch();
}
}
void searchByName(){
    char na[50];
int f=0;
printf("Enter Artist Name To search:");
fflush(stdin);
gets(na);
printf("%-30s %-20s %-20s %-10s %s\n", "name", "BirthPlace", "Style of art",  "Age", "Date");
 fp = fopen("art.txt","rb");
while(fread(&s, sz, 1, fp) == 1){

        if(strcmpi(na, s.name) == 0){
            f=1;
               printf("%-30s %-15s %-25s %-5d %s\n", s.name, s.bp, s.sa, s.age, s.date);
            break;

        }

      }
      fclose(fp);
      if(f==0){
        printf("Record not found");
      }
      else{
         printf("Record found successfully");
      }

}
void searchByArt(){
    char ar[50];
int f=0;
printf("Enter Style Of Art To search:");
fflush(stdin);
gets(ar);
printf("%-30s %-20s %-20s %-10s %s\n", "name", "BirthPlace", "Style of art",  "Age", "Date");
 fp = fopen("art.txt","rb");
while(fread(&s, sz, 1, fp) == 1){

        if(strcmpi(ar, s.sa) == 0){
            f=1;
               printf("%-30s %-15s %-25s %-5d %s\n", s.name, s.bp, s.sa, s.age, s.date);
            break;

        }

      }
      fclose(fp);
      if(f==0){
        printf("Record not found");
      }
      else{
         printf("Record found successfully");
      }

}
void del(){
    char na[50];
int f=0;
printf("Enter  Name To delete:");
fflush(stdin);
gets(na);
FILE *ft;
fp = fopen("art.txt","rb");
 ft = fopen("temp.txt","ab");
while(fread(&s, sz, 1, fp) == 1){

        if(strcmpi(na, s.name) == 0){
            f=1;
        }
       else{
        fwrite(&s,sz,1,ft);
       }
      }
     fclose(fp);
     fclose(ft);
     remove("art.txt");
     rename("temp.txt","art.txt");
     if(f==0){
        printf("Record not found");
      }
      else{
         printf("Record deleted successfully");
      }

}
void info()
{

    char str[20][50], s1[50];
   int n, i,dollar, found=0;
 printf("Enter how many string (adress): ");
   scanf("%d", &n);
printf("Enter how many string (name): ");
   scanf("%d", &n);

printf("Enter how many string (dollar): ");
   scanf("%d", &n);
printf("Enter %d adress:\n", n);
   for(i=0; i<n; i++)
   {

        printf("Enter Customer Adress:");
       fflush(stdin);
        gets(str);

   }
   printf("Enter %d names:\n", n);
   for(i=0; i<n; i++)
   {
    printf("Enter Customer  Names:");
    fflush(stdin);
   gets(str[i]);

   }
   printf("Enter %d customers dollar :\n", n);
   for(i=0; i<n; i++)
  {



printf("Total amount of Dollar, they spent on Gallery: ");
       scanf("%d",&dollar);
   }
   printf("Enter a name to search: ");
   fflush(stdin);
      gets(s1);
 for(i=0; i<n; i++)
   {

     if(strcmp(str[i],s1) == 0)
     {
       found=1;
       break;
     }
   }
   if(found==1){
       printf(" Customer Found-%d\n", i+1);
     }

      else{
            printf(" Customer Not found");
      }


      found =0;
}
void arcat()
{
   printf("\n------------------------------------");
         printf("\n ");
          printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
         printf("  *                                                              *\n");
         printf("  |   WELCOME TO OUR NOSTALGIA'S ART WORK                          |\n");
         printf("   *-------------------------------------------------------------*\n");
          printf("  |   Enter 0: For exit                                           |\n");
          printf("  |   enter 1:FOR ABSTRACT                                        |\n");
          printf("  |   enter 2:FOR FANTASY                                         |\n");
          printf("  |   enter 3:FOR RELEGIOUS PAINTING                              |\n");
          printf("  |   enter 4:FOR 19TH CENTURY                                    |\n");
          printf("  |   enter 5:FOR LANDSCAPE                                       |\n");
          printf("  |   enter 6:FOR RENAISSANCE PERIOD:EXPRESSIONISM                |\n");
    printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
          int number;
         printf(" \n    Enter a number : ");
         scanf("%d",&number);

        switch(number)
        {
            case 0:
           exit(1);
            break;

 case 1:
            printf("    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
            printf("  *                                                             *\n");
            printf("  |                      ABSTRACT                              |\n");
            printf("   *-------------------------------------------------------------*\n");
            printf("  |   Enter 1: For Verte                                           |");
            printf("\n  |   Enter 2: For Filtres � caf�                                 |");
            printf("\n  |   Enter 3: For Management Abstract                            |");
            printf("\n  |   Enter 4: For Rhythm, Joy of Life                            |");
            printf("\n  |   Enter 5: For Purple                                         |");
            printf("\n  |   Enter 6: For  Group X, No. 1, Altarpiece                   |\n");
            printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
            int abstract;
                printf("\n Enter number you want to know the details of painting:   ");
        scanf("%d",abstract);
        switch(abstract)
        {
        case 1:
            printf(" Artist Name: Rie Kono\n");
            printf(" The year it was made: 2009\n");
            printf(" Price:400 $\n");
            break;
        case 2:
            printf(" Artist Name: Irvin Vega\n");
            printf(" The year it was made: 2004\n");
            printf(" Price:500 $\n");
            break;
             case 3:
            printf(" Artist Name: Oliver Jake\n");
            printf(" The year it was made: 2007\n");
            printf(" Price:260 $\n");
            break;
            case 4:
            printf(" Artist Name: Oliver Jake\n");
            printf(" The year it was made: 2007\n");
            printf(" Price:749 $\n");
            break;
            case 5:
            printf(" Artist Name: Jack Connor\n");
            printf(" The year it was made: 2000\n");
            printf(" Price:     350 $\n");
            break;
            case 6:
            printf(" Artist Name: Harry	Callum\n");
            printf(" The year it was made: 2006\n");
            printf(" Price:      50 $\n");
            break;
}
           break;
            case 2:
                 printf("    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
            printf("  *                                                             *\n");
            printf("  |                      FANTASY                              |    \n");
            printf("   *-------------------------------------------------------------*\n");
            printf("  |   Enter 1: For Pouvoir des filles                               |");
            printf("\n  |   Enter 2: For Breath of Mystery                               |");
            printf("\n  |   Enter 3: For Servant of Invention                            |");
            printf("\n  |   Enter 4: For la Folie Future                                 |");
            printf("\n  |   Enter 5: For Abstract Incident                               |");
            printf("\n  |   Enter 6: For l'Honneur Th��trale                             |\n");
            printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
            int fantasy;
                printf("\n Enter number you want to know the details of painting:   ");
        scanf("%d",&fantasy);
        switch(fantasy)
        {
        case 1:
            printf(" Artist Name: Yang Yang\n");
            printf(" The year it was made: 2004\n");
            printf(" Price:950 $\n");
            break;
             case 2:
            printf(" Artist Name: Zheng Shuang\n");
            printf(" The year it was made: 2005\n");
            printf(" Price:649 $\n");
            break;
            case 3:
            printf(" Artist Name: Suzzan Blac\n");
            printf(" The year it was made: 2010\n");
            printf(" Price:860 $\n");
            break;
            case 4:
            printf(" Artist Name:James Henry Govier\n");
            printf(" The year it was made: 2001\n");
            printf(" Price:360 $\n");
            break;
             case 5:
            printf(" Artist Name:Lisa Beznosiuk\n");
            printf(" The year it was made: 1999\n");
            printf(" Price:310 $\n");
            break;
          case 6:
            printf(" Artist Name:Nano Watson\n");
            printf(" The year it was made: 2016\n");
            printf(" Price:211 $\n");
            break;
        }
        break;
          case 3:
             printf("    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
            printf("  *                                                             *\n");
            printf("  |                     RELEGIOUS PAINTING                         \n");
            printf("   *-------------------------------------------------------------*\n");
            printf("  |   Enter 1: For La libre envol�e                                  |");
            printf("\n  |   Enter 2: For Light of the World                              |");
            printf("\n  |   Enter 3: For Lion of Judah                                   |");
            printf("\n  |   Enter 4: For manger scenes                                   |");
            printf("\n  |   Enter 5: For Angels                                          |");
            printf("\n  |   Enter 6:For Mary Joseph                                      |\n");
            printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
            int biblical;
                printf("\n Enter number you want to know the details of painting:   ");
        scanf("%d",&biblical);
        switch(biblical)
        {
     case 1:
        printf(" Artist Name:Katty jenar\n");
            printf(" The year it was made: 2011\n");
            printf(" Price:209 $\n");
            break;
             case 2:
        printf(" Artist Name:Jerry Rosine\n");
            printf(" The year it was made: 2011\n");
            printf(" Price:209 $\n");
            break;
             case 3:
        printf(" Artist Name:Jessi Wang\n");
            printf(" The year it was made: 2002\n");
            printf(" Price:302 $\n");
            break;
             case 4:
        printf(" Artist Name:Kyle William \n");
            printf(" The year it was made: 1999\n");
            printf(" Price:411 $\n");
            break;
             case 5:
        printf(" Artist Name:Thomas	Joe\n");
            printf(" The year it was made: 2008\n");
            printf(" Price:511 $\n");
            break;
             case 6:
        printf(" Artist Name:Alexander Joseph\n");
            printf(" The year it was made: 2018\n");
            printf(" Price:809 $\n");
            break;
        }
        break;
             case 4:
                printf("    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
            printf("  *                                                                *\n");
            printf("  |                      19TH CENTURY                                 |\n");
            printf("   *-------------------------------------------------------------*\n");
            printf("  |   Enter 1: For The Burial of the Count of Orgaz                  |");
            printf("\n  |   Enter 2: For Florinda                                        |");
            printf("\n  |   Enter 3: For Young man                                       |");
            printf("\n  |   Enter 4: For realism                                         |");
            printf("\n  |   Enter 5: For American Women                                  |");
            printf("\n  |   Enter 6: For German Romanticism                              |\n");
            printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
            int century;
                printf("\n Enter number you want to know the details of painting:   ");
        scanf("%d",&century);
        switch(century)
        {
     case 1:
        printf(" Artist Name:Mason Robert\n");
            printf(" The year it was made: 1971\n");
            printf(" Price:670 $\n");
            break;
             case 2:
        printf(" Artist Name:Noah Deshawn \n");
            printf(" The year it was made: 1965\n");
            printf(" Price:100 $\n");
            break;
             case 3:
        printf(" Artist Name:Liam Oliver\n");
            printf(" The year it was made: 1945\n");
            printf(" Price:207 $\n");
            break;
             case 4:
        printf(" Artist Name:Lucas Benjamin \n");
            printf(" The year it was made: 1994\n");
            printf(" Price:801 $\n");
            break;
             case 5:
        printf(" Artist Name:Elijah Pit\n");
            printf(" The year it was made: 1992\n");
            printf(" Price:411 $\n");
            break;
             case 6:
        printf(" Artist Name:SawyerJason\n");
            printf(" The year it was made: 1990\n");
            printf(" Price:609 $\n");
            break;
}
  break;
  case 5:
                printf("    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
            printf("  *                                                                *\n");
            printf("  |                      LANDSCAPE                                 |\n");
            printf("   *-------------------------------------------------------------*\n");
            printf("  |   Enter 1: For The Hunters in The Snow                           |");
            printf("\n  |   Enter 2: For View of Toledo                                  |");
            printf("\n  |   Enter 3: For Young man                                       |");
            printf("\n  |   Enter 4: For View across Streams and Mountains               |");
            printf("\n  |   Enter 5: For Wanderer Above the Sea of Fog                   |");
            printf("\n  |   Enter 6: For Mount Fuji in Clear Weather                     |\n");
            printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
            int landscape;
                printf("\n Enter number you want to know the details of painting:   ");
        scanf("%d",&landscape);
        switch(landscape)
        {
     case 1:
        printf(" Artist Name: Pieter Bruegel \n");
            printf(" The year it was made: 2009\n");
            printf(" Price:209 $\n");
            break;
             case 2:
        printf(" Artist Name:El Greco \n");
            printf(" The year it was made: 2011\n");
            printf(" Price:209 $\n");
            break;
             case 3:
        printf(" Artist Name: Wang Hui\n");
            printf(" The year it was made: 2002\n");
            printf(" Price:302 $\n");
            break;
             case 4:
        printf(" Artist Name:John Constable\n");
            printf(" The year it was made: 1999\n");
            printf(" Price:411 $\n");
            break;
             case 5:
        printf(" Artist Name:Katsushika Hokusai\n");
            printf(" The year it was made: 2008\n");
            printf(" Price:511 $\n");
            break;
             case 6:
        printf(" Artist Name:Caspar David Friedrich\n");
            printf(" The year it was made: 2018\n");
            printf(" Price:809 $\n");
            break;
        }
        break;

 case 6:
                 printf("    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
            printf("  *                                                             *\n");
            printf("  |                     RENAISSANCE PERIOD:EXPRESSIONISM        |\n");
            printf("   *-------------------------------------------------------------*\n");
            printf("  |   Enter 1: For The Sick Child                                    |");
            printf("\n  |   Enter 2: For DR rosa                                         |");
            printf("\n  |   Enter 3: For Suicide                                         |");
            printf("\n  |   Enter 4: For Girls Future                                    |");
            printf("\n  |   Enter 5: For Woman With Bag                                  |");
            printf("\n  |   Enter 6: For The Crab                                        |\n");
            printf("   *_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
            int renaissance;
                printf("\n Enter number you want to know the details of painting:   ");
        scanf("%d",&renaissance);
        switch(renaissance)
        {
        case 1:
            printf(" Artist Name: George Grosz\n");
            printf(" The year it was made: 2004\n");
            printf(" Price:950 $\n");
            break;
             case 2:
            printf(" Artist Name: Jack Butler Yeats\n");
            printf(" The year it was made: 2005\n");
            printf(" Price:649 $\n");
            break;
            case 3:
            printf(" Artist Name: Karl Schmidt-Rottluff\n");
            printf(" The year it was made: 2010\n");
            printf(" Price:860 $\n");
            break;
            case 4:
            printf(" Artist Name:James Henry Govier\n");
            printf(" The year it was made: 2001\n");
            printf(" Price:360 $\n");
            break;
             case 5:
            printf(" Artist Name:Oskar Kokoschka\n");
            printf(" The year it was made: 1999\n");
            printf(" Price:310 $\n");
            break;
          case 6:
            printf(" Artist Name:Edvard Munch\n");
            printf(" The year it was made: 2016\n");
            printf(" Price:211 $\n");
            break;
        }
        break;
}


}
void artistdisplay()
{
    struct node* temp = head;
    printf("<==NEW ARTIST INFO==>\n");
    while(temp!=NULL)
    {
        printf(" The Name of Painting : %s\n", temp->paintingname);
        printf("Name of the artist: %s\n", temp->artistname);
        printf("The price of the painting: %s\n", temp->dollar);
        printf("The year it was made: %s\n\n", temp->year);
        printf("Contact: %s\n\n", temp->contact);
        temp = temp->link;
    }
    return;
}
void artistinsert ()
{
    printf("||Insert Information||");
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Painting Info: \n");
    printf("Name of Painting: ");
    getchar();
    gets(temp->paintingname);
    printf("Artist Name: ");
    getchar();
    gets(temp->artistname);
    printf("The price of the painting: ");
    gets(temp->dollar);
    printf("The year it was made: ");
    gets(temp->year);
    printf("Artist Contact: ");
    gets(temp->contact);
    temp->link = NULL;
    if (head==NULL)
    {
        head = temp;
        system("cls");
        return;
    }
    else
    {
        temp->link = head;
        head = temp;
        return;
    }
}


