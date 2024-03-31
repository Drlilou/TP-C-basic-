#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure for student
struct Student {
    int number;
    char name[50];
    char lastname[50];
    char department[50];
    float avg;
};

// Global array to store students
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void admittedStudents();
void editStudent(int number);
void searchByNumber(int number);
void deleteStudent(int number);
void displayMenu();
void readFile();
void saveToFile();

int main() {
    // Read students data from file
    readFile();

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                admittedStudents();
                break;
            case 4:
                printf("Enter student number to edit: ");
                int num;
                scanf("%d", &num);
                editStudent(num);
                break;
            case 5:
                printf("Enter student number to search: ");
                int searchNum;
                scanf("%d", &searchNum);
                searchByNumber(searchNum);
                break;
            case 6:
                printf("Enter student number to delete: ");
                int deleteNum;
                scanf("%d", &deleteNum);
                deleteStudent(deleteNum);
                break;
            case 7:
                saveToFile(); // Save data to file before exiting
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Student database full.\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student number: ");
    scanf("%d", &newStudent.number);

    printf("Enter student name: ");
    scanf("%s", newStudent.name);

    printf("Enter student last name: ");
    scanf("%s", newStudent.lastname);

    printf("Enter student department: ");
    scanf("%s", newStudent.department);

    printf("Enter student average: ");
    scanf("%f", &newStudent.avg);

    students[studentCount++] = newStudent;

    printf("Student added successfully.\n");
}

void displayStudents() {
    printf("List of students:\n");
    printf("Number\tName\tLast Name\tDepartment\tAverage\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t%s\t%s\t%.2f\n", students[i].number, students[i].name, students[i].lastname, students[i].department, students[i].avg);
    }
}

void admittedStudents() {
    printf("Admitted students:\n");
    printf("Number\tName\tLast Name\tDepartment\tAverage\n");
    for (int i = 0; i < studentCount; i++) {
        if (students[i].avg >= 10) {
            printf("%d\t%s\t%s\t%s\t%.2f\n", students[i].number, students[i].name, students[i].lastname, students[i].department, students[i].avg);
        }
    }
}

void editStudent(int number) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].number == number) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);

            printf("Enter new last name: ");
            scanf("%s", students[i].lastname);

            printf("Enter new department: ");
            scanf("%s", students[i].department);

            printf("Enter new average: ");
            scanf("%f", &students[i].avg);

            printf("Student information updated successfully.\n");
            return;
        }
    }
    printf("Student with number %d not found.\n", number);
}

void searchByNumber(int number) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].number == number) {
            printf("Student found:\n");
            printf("Number\tName\tLast Name\tDepartment\tAverage\n");
            printf("%d\t%s\t%s\t%s\t%.2f\n", students[i].number, students[i].name, students[i].lastname, students[i].department, students[i].avg);
            return;
        }
    }
    printf("Student with number %d not found.\n", number);
}

void deleteStudent(int number) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].number == number) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student with number %d not found.\n", number);
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Display Admitted Students\n");
    printf("4. Edit Student\n");
    printf("5. Search by Number\n");
    printf("6. Delete Student\n");
    printf("7. Exit\n");
}

void readFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return;
    }

    while (!feof(file) && studentCount < MAX_STUDENTS) {
        fscanf(file, "%d %s %s %s %f", &students[studentCount].number, students[studentCount].name, students[studentCount].lastname, students[studentCount].department, &students[studentCount].avg);
        studentCount++;
    }

    fclose(file);
}

void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Unable to create or open file for writing.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %s %s %.2f\n", students[i].number, students[i].name, students[i].lastname, students[i].department, students[i].avg);
    }

    fclose(file);
}
