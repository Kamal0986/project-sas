#include <stdio.h>
#include <string.h
typedef struct{
    char departements[40];
}classes;
classes n[4] =  {"Math","Physique","Informatique","BCG"};
typedef struct {
    int day;
    int month;
    int year;
}Birthday;
typedef struct {
    int numUnique;
    char firstName[30];
    char lastName[30];
    Birthday  dateOfBirth;
    char Departement [20];
    float noteGenerale;
}student;
student s[5];
int id = 1;
int counter = 0;
void Menu(){
    printf("1-Add a student\n");
    printf("2-Edit or delete a student\n");
    printf("3-View a student's details\n");
    printf("4-Calculate the GPA\n");
    printf("5-Statistiques\n");
    printf("6-Search for student by  Unique Numbre.\n");
    printf("7-Sort a student by\n");
    printf("8-Exite\n");
}
void addStudent(){
    printf("Enter your First  name: ");
    scanf("%s",s[counter].firstName);
    printf("Enter your Last name :");
    scanf("%s",s[counter].lastName);
    printf("enter your day OF birth: ");
    scanf("%d",&s[counter].dateOfBirth.day);
    while (s[counter].dateOfBirth.day>12 ){
        printf("enter your day OF birth: ");
        scanf("%d",&s[counter].dateOfBirth.day);
    }
    printf("enter your month OF birth: ");
    scanf("%d",&s[counter].dateOfBirth.month);
    while (s[counter].dateOfBirth.month>30){
         printf("enter your month OF birth: ");
        scanf("%d",&s[counter].dateOfBirth.month);
    }
    printf("enter your year  OF birth: ");
    scanf("%d",&s[counter].dateOfBirth.year);
    while (scanf("%d",&s[counter].dateOfBirth.year)>2024){
        printf("enter your year  OF birth: ");
    scanf("%d",&s[counter].dateOfBirth.year);
    }
    printf("1-Math 2-Physique 3-Informatique 4-BCG \n");
    int ask ;
    printf("enter your choice: ");
    scanf("%d",&ask);
    switch (ask)
    {
    case 1:strcpy(s[counter].Departement,"Math");
        break;
    case 2 :strcpy(s[counter].Departement,"Physique");
        break;
    case 3 : strcpy(s[counter].Departement,"Informatique");
        break;
    case 4 :  strcpy(s[counter].Departement,"Bcg");break;
    default:  printf("departement not found\n");
        break;
    }
    printf("enter your note generale: ");
    scanf("%f",&s[counter].noteGenerale);
    printf("your Uni: %d\n",s[counter].numUnique);
    printf("Add Successfully\n");
}
void Display (){
    for (int  i = 0; i < counter; i++)
    {
    printf("number Uique : %d\n",s[i].numUnique);
    printf("Full name    : %s %s\n",s[i].firstName,s[i].lastName);
    printf("born in      : %d/%d/%d\n",s[i].dateOfBirth.day,s[i].dateOfBirth.day,s[i].dateOfBirth.year);
    printf("Not Generale : %.2f\n",s[i].noteGenerale);
    }
}
int checkoutID(int nuchecker){
    int check  = 0 ;
    for(int i=0;i<counter;i++){
        if (nuchecker==s[i].numUnique) check = i;
    }
        check = 1 ;
        
}
void EditeStudent(){
    int choice;
    int idchecker; 
    printf("enter your id : \n");
    scanf("%d",&idchecker);
    for (int i = 0 ; i<counter ; i++){
        if(s[i].numUnique==idchecker){
    printf("1-firstName 2-lastName 3-Dateofbirth 4-Departement 5-Note Genrale\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("enter you new firsr name: ");
     scanf("%s",s[i].firstName);
        break;
    case 2:printf("enter you new last name: ");
           char new_last_name [50];
           scanf("%s",new_last_name);
           strcpy(s[i].lastName,new_last_name);
    break;
    case 3:printf("update your date of Birth: ");
           scanf("%d%d%d",&s[i].dateOfBirth.day,&s[i].dateOfBirth.month,&s[i].dateOfBirth.year);
    break;
    case 4:     printf("1-Math 2-Physique 3-Informatique 4-BCG \n");
    int ask ;
    printf("enter your choice: ");
    scanf("%d",&ask);
    switch (ask)
    {
    case 1:strcpy(s[counter].Departement,"Math");
        break;
    case 2 :strcpy(s[counter].Departement,"Physique");
        break;
    case 3 : strcpy(s[counter].Departement,"Informatique");
        break;
    case 4 :  strcpy(s[counter].Departement,"Bcg");break;
    default:  printf("departement not found\n");
        break;
    }
    case 5: printf("enter your new  Note Generale : ");
    float  nw_genrale;
    scanf("%f",&nw_genrale);
    s[i].noteGenerale=nw_genrale;
    default: printf("choice Not found.");
        break;
    }
    }
    
}
}
void  viewDetails(){
        int check ; 
    printf("enter your id : ");
    scanf("%d",&check);
    for(int i=0;i<counter;i++){
        if(check == s[i].numUnique){
    printf("Number Unique : %d\n",s[i].numUnique);
    printf("First name    : %s\n",s[i].firstName);
    printf("Last name     : %s\n",s[i].lastName);
    printf("Date of birth : %d/%d/%d\n",s[i].dateOfBirth.day,s[i].dateOfBirth.month,s[i].dateOfBirth.year);
    printf("Departement   : %s\n",s[i].Departement);
    printf("Note Generale : %.2f\n",s[i].noteGenerale);
        }
    }
}
void DeletStudent(){
    int check ; 
    printf("enter your id : ");
    scanf("%d",&check);
    for (int i = 0; i < counter; i++)
    {
        if (check==s[i].numUnique){
            s[i]=s[i+1];
        }
    }
    counter--;
}
int   moyenne_generale(int ask){
     int moyenne = 0;
     int somme = 0; 
     for (int i = 0; i < counter   ; i++)
     {
        if(n[ask].departements==s[i].Departement){
                somme += s[i].noteGenerale;
                moyenne++;
                
        }
     }
     return somme /moyenne ; 
     
}
int main(){
    int ask;
    Menu();
    printf("Enter your choice: ");
    scanf("%d",&ask);
    do{
        switch(ask){    
        case 1:
            s[counter].numUnique = id;
            id++;
            addStudent();
            counter++;
            break;
        case 2:
            int Question;
            printf("what do you wan't :\n");
            printf("1-Edite \n2-Delet");
            scanf("%d",&Question);
           if(Question==1) 
               EditeStudent();
           else if (Question==2) 
                DeletStudent();
            else printf("choice Not found.");
        
        break;
        case 3:
        viewDetails();break;
           printf("1-Math 2-Physique 3-Informatique 4-BCG \n");
           int ask ; 
           scanf("%d",&ask);
        case 4:
        printf("%d",moyenne_generale(ask));
        }
         Menu();
    printf("Enter your choice: ");
    scanf("%d",&ask);
    }while(ask!=8);
}   