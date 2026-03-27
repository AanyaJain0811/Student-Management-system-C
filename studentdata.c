#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int roll;
    char name[50];
    int age;
    char gender;
    char course[50];
    float marks;
    char email[50];
    struct student *next;
};
struct student *head=NULL;
void insert(){
    struct student *newnode=malloc(sizeof(struct student));
    printf("Enter roll number: ");
    scanf("%d",&newnode->roll);
     printf("Enter Name: ");
    scanf(" %[^\n]", newnode->name);
    printf("Enter Age: ");
    scanf("%d", &newnode->age);
    printf("Enter Gender (M/F): ");
    scanf(" %c", &newnode->gender);
    printf("Enter Course: ");
    scanf(" %[^\n]", newnode->course);
    printf("Enter Marks: ");
    scanf("%f", &newnode->marks);
    printf("Enter Email: ");
    scanf(" %[^\n]", newnode->email);
    newnode->next=head;
    head=newnode;
    printf("Record inserted successfully\n");
}
void searchroll(){
    int roll;
    printf("Enter roll number: ");
    scanf("%d",&roll);
    struct student *temp=head;
    while(temp){
        if(temp->roll == roll){
            printf("Student found:\n");
            printf("\nROLL NAME AGE GENDER COURSE MARKS EMAIL\n");
            printf("%d %s %d %c %s %.2f %s\n",temp->roll, temp->name, temp->age, temp->gender, temp->course, temp->marks, temp->email);
            return;
        }
        temp=temp->next;
    }
    printf("Student not found\n");
}
void searchname(){
    char name[50];
    printf("Enter name: ");
    scanf(" %[^\n]",name);
    struct student *temp=head;
    int found=0; 
    while(temp){
        if(strcmp(temp->name,name)==0){
            printf("\nROLL NAME AGE GENDER COURSE MARKS EMAIL\n");
            printf("%d %s %d %c %s %.2f %s\n",temp->roll, temp->name, temp->age, temp->gender, temp->course, temp->marks, temp->email);
            found=1;
        }
        temp=temp->next;
    }
    if(!found) 
        printf("No record found.\n");
}
void searchcourse(){
    char course[50];
    printf("Enter course: ");
    scanf(" %[^\n]",course);
    struct student *temp=head;
    int found=0;
    while(temp){
        if(strcmp(temp->course, course)==0){
            printf("\nROLL NAME AGE GENDER COURSE MARKS EMAIL\n");
             printf("%d %s %d %c %s %.2f %s\n",temp->roll, temp->name, temp->age, temp->gender, temp->course, temp->marks, temp->email);
             found=1;
        }
        temp=temp->next;
    }
    if(!found) printf("No record found.\n");
}
void searchmarks(){
    float low,high;
    printf("Enter minimum marks: ");
    scanf("%f",&low);
    printf("Enter maximum marks: ");
    scanf("%f",&high);
    struct student *temp=head;
    int found=0;
    while(temp){
        if(temp->marks>=low && temp->marks<=high){
            printf("\nROLL NAME AGE GENDER COURSE MARKS EMAIL\n");
             printf("%d %s %d %c %s %.2f %s\n",temp->roll, temp->name, temp->age, temp->gender, temp->course, temp->marks, temp->email);
             found=1;
        }
        temp=temp->next;
    }
    if(!found) printf("No record found.\n");
}
void display(){
    if(head==NULL){
        printf("No record found.\n");
        return;
    }
    struct student *temp=head;
    printf("Displaying all records:\n");
    printf("\nROLL NAME AGE GENDER COURSE MARKS EMAIL\n");
    while(temp){
         printf("%d %s %d %c %s %.2f %s\n",temp->roll, temp->name, temp->age, temp->gender, temp->course, temp->marks, temp->email);
         temp=temp->next;
    }
}
int main(){
    int choice;
    while(1){
         printf("\n--- Student Database Menu ---\n");
        printf("1.Insert Record\n");
        printf("2.Search by roll number\n");
        printf("3.Search by name\n");
        printf("4.Search by course\n");
        printf("5.Search by marks range\n");
        printf("6.Display all records\n");
        printf("7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert(); break;
            case 2: searchroll(); break;
            case 3: searchname(); break;
            case 4: searchcourse(); break;
            case 5: searchmarks(); break;
            case 6: display(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
