#include <stdio.h> 
struct Student{ 
    int rollno; 
    char name[50]; 
    int age; 
    float mark;
    };
    
    int main() { 
        struct Student s[10]; 
        int i; 
        for (i=0;i<10;i++){ 
            printf("\nEnter the details of %d student : \n Rollno,Name,Age,Mark : ",i+1);
            scanf("%d %s %d %f",&s[i].rollno,s[i].name,&s[i].age ,&s[i].mark );
            } 
        
        printf("\nThe details of the student are \n Rollno,Name,Age,Mark",i+1);
        for (i=0;i<10;i++) {
            printf("\n");
            printf("%d %s %d %.2f",s[i].rollno,s[i].name,s[i].age ,s[i].mark ); 
        }
        return 0; 
        
    }
