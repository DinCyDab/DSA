#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int studentID;
    char first_name[20];
    char last_name[20];
    char middle_name[20];
    int age;
    char gender[20];
}studentInfo;

typedef struct{
    int departmentID;
    char department_name[100];
}departmentInfo;

typedef struct{
    studentInfo student;
    departmentInfo department;
}studentList;

typedef struct{
    int count;
    studentList list[20];
}studentCount;

studentInfo addStudent(int studentID, char* first_name, char* last_name, char* middle_name, int age, char* gender);
departmentInfo addDepartment(int departmentID, char* department_name);
studentList addStudentListing(studentInfo student, departmentInfo department, studentCount* studentCountList);
void printStudentListing(studentCount* studentCountList);

int main(){
    studentCount studentCountList;
    studentCountList.count = 0;
    studentCountList.list[0] = addStudentListing(addStudent(0001, "Dino Cyrano", "Dabon", "Azucenas", 23, "Male"), addDepartment(0001, "Department of Computer and Information Sciences Mathematics"), &studentCountList);
    printStudentListing(&studentCountList);
    return 0;
}

void printStudentListing(studentCount* studentCountList){
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n\n", "Student ID", "First Name", "Middle Name", "Last Name", "Age", "Gender", "Department ID", "Department Name");
    for(int i = 0; i < studentCountList->count; i++){
        printf("%-20d", studentCountList->list[i].student.studentID);
        printf("%-20s", studentCountList->list[i].student.first_name);
        printf("%-20s", studentCountList->list[i].student.middle_name);
        printf("%-20s", studentCountList->list[i].student.last_name);
        printf("%-20d", studentCountList->list[i].student.age);
        printf("%-20s", studentCountList->list[i].student.gender);
        printf("%-20d", studentCountList->list[i].department.departmentID);
        printf("%-20s\n", studentCountList->list[i].department.department_name);
    }
}

studentList addStudentListing(studentInfo student, departmentInfo department, studentCount* studentCountList){
    studentList studentListing;
    studentListing.student = student;
    studentListing.department = department;
    studentCountList->count++;
    return studentListing;
}

studentInfo addStudent(int studentID, char* first_name, char* last_name, char* middle_name, int age, char* gender){
    studentInfo student;
    student.studentID = studentID;
    strcpy(student.first_name, first_name);
    strcpy(student.last_name, last_name);
    strcpy(student.middle_name, middle_name);
    strcpy(student.gender, gender);
    student.age = age;
    return student;
}

departmentInfo addDepartment(int departmentID, char* department_name){
    departmentInfo department;
    department.departmentID = departmentID;
    strcpy(department.department_name, department_name);
    return department;
}