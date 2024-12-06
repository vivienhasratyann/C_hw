#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Student {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int id;
    float grade;
    struct Student *next;
} Student;

Student *head = NULL;

void addStudent(char *name, char *surname, int id, float grade) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (!newStudent){
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newStudent->name, name);
    strcpy(newStudent->surname, surname);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = head;
    head = newStudent;
    printf("Student added successfully!\n");
}

void removeStudent(int id){
    Student *current = head, *previous = NULL;
    while (current && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        printf("Student with ID %d not found!\n", id);
        return;
    }

    if (!previous) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Student removed successfully!\n");
}

void searchStudent(int id){
    Student *current = head;
    while (current) {
        if (current->id == id) {
            printf("Name: %s, Surname: %s, ID: %d, Grade: %.2f\n", current->name, current->surname, current->id, current->grade);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found!\n", id);
}

void displayStudents() {
    Student *current = head;
    if (!current) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Details:\n");
    while (current) {
        printf("Name: %s, Surname: %s, ID: %d, Grade: %.2f\n", current->name, current->surname, current->id, current->grade);
        current = current->next;
    }
}

void displayAverageGrade() {
    Student *current = head;
    if (!current) {
        printf("No students to calculate the average grade.\n");
        return;
    }

    int count = 0;
    float total = 0;
    while (current) {
        total += current->grade;
        count++;
        current = current->next;
    }

    printf("Average Grade: %.2f\n", total / count);
}

void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    Student *current = head;
    while (current) {
        fprintf(file, "%s,%s,%d,%.2f\n", current->name, current->surname, current->id, current->grade);
        current = current->next;
    }

    fclose(file);
    printf("Student details saved to %s succeessfully!\n", filename);
}

void loadFromFile(const char *filename){
    FILE *file = fopen(filename, "r");
    if (!file){
        printf("Error opening file for reading!\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH];
        int id;
        float grade;

        if (sscanf(line, "%49[^,],%49[^,],%d,%f", name, surname, &id, &grade) == 4) {
            addStudent(name, surname, id, grade);
        }
    }

    fclose(file);
    printf("Student details loaded form %s successfully!\n", filename);
}

void freeMemory() {
    Student *current = head;
    while (current) {
        Student *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH];
    float grade;
    const char *filename = "group_details.csv";

    do {
        printf("\nMenu:\n");
        printf("1. Add a new student\n");
        printf("2. Remove a student by ID\n");
        printf("3. Search a student by ID\n");
        printf("4. Display all student details\n");
        printf("5. Display average grade of all students\n");
        printf("6. Save student details to file\n");
        printf("7. Load student details from file\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter surname: ");
            scanf("%s", surname);
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter grade: ");
            scanf("%f", &grade);
            addStudent(name, surname, id, grade);
            break;
        case 2:
            printf("Enter ID to remove: ");
            scanf("%d", &id);
            removeStudent(id);
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(id);
            break;
        case 4:
            displayStudents();
            break;
        case 5:
            displayAverageGrade();
            break;
        case 6:
            saveToFile(filename);
            break;
        case 7:
            loadFromFile(filename);
            break;
        case 8:
            freeMemory();
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    
    return 0;
}