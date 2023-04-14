#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct types
typedef struct  {
    char course_name[40];
    char course_id[6];
    float course_credit;
    char course_mark;
} courses_t;

typedef struct  {
    int id;
    char name[40];
    float GPA;
    int NumberOfCourse;
    courses_t* courses;
} Student_t;

Student_t student[100];
int TotalStudents = 0;

// Function to add a new student
void add_new_student() {
    // Prompt the user to enter the student's ID
    printf("Enter the student ID: ");
    scanf("%d", &student[TotalStudents].id);

    // Prompt the user to enter the student's name
    printf("Enter the student name: ");
    scanf("%39s", &student[TotalStudents].name);

    // Prompt the user to enter the student's GPA
    printf("Enter the student's GPA: ");
    scanf("%f", &student[TotalStudents].GPA);
    if (student[TotalStudents].GPA >4.0){
        printf("GPA should not be greater than 4.");
        printf("Enter the student's GPA (PROPER LESS THAN 4): ");
        scanf("%f", &student[TotalStudents].GPA);

    }

    // Prompt the user to enter the number of courses the student has taken
    printf("Enter the number of courses: ");
    scanf("%d", &student[TotalStudents].NumberOfCourse);
    // Allocate memory for the courses array
    student[TotalStudents].courses = malloc(student[TotalStudents].NumberOfCourse * sizeof(courses_t));
    printf("");
    if (student[TotalStudents].courses == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Loop to prompt the user to enter information for each course
    for (int i = 0; i < student[TotalStudents].NumberOfCourse; i++) {
        // Prompt the user to enter the course name
        printf("Enter course #%d name: ", i+1);
        scanf("%s", &student[TotalStudents].courses[i].course_name);


        // Prompt the user to enter the course ID
        printf("Enter course #%d ID: ", i+1);
        scanf("%s", &student[TotalStudents].courses[i].course_id);


        // Prompt the user to enter the course credit hours
        printf("Enter course #%d credit hours: ", i+1);
        scanf("%f", &student[TotalStudents].courses[i].course_credit);

        // Prompt the user to enter the course mark
        printf("Enter course #%d mark: ", i+1);
        scanf("%c", &student[TotalStudents].courses[i].course_mark); 
    }
    TotalStudents++;
}

int main() {
    int total_students = 0;

    // Add a new student
    add_new_student();
    printf("");
    // Print the student's information
    printf("\nStudent ID: %d\n", student[total_students].id);
    printf("Student name: %s\n", student[total_students].name);
    printf("Student GPA: %.2f\n", student[total_students].GPA);
    printf("Number of courses: %d\n", student[total_students].NumberOfCourse);
    for (int i = 0; i < student[total_students].NumberOfCourse; i++) {
        printf("Course #%s name: %s\n", i+1, student[total_students].courses[i].course_name);
        printf("Course #%d ID: %s\n", i+1, student[total_students].courses[i].course_id);
        printf("Course #%d Credit: %s\n", i+1, student[total_students].courses[i].course_credit);
        printf("Course #%c Marks: %s\n", i+1, student[total_students].courses[i].course_mark);
    }
    return 0;
    }