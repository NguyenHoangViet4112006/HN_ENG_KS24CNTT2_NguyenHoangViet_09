//
// Created by Nguyen Hoang Viet on 7/31/2025.
//
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char name[100];
    int age;
    char homeTown[100];
    char division[100];
    char phone[15];
} Employee;

typedef struct Node {
    Employee data;
    struct Node *next;
} Node;

typedef struct DNode {
    Employee data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

Node *head = NULL;
DNode *headResign = NULL;
DNode *tailResign = NULL;

void addEmployee() {
    Employee employee;
    printf("ID nhan vien: ");
    scanf("%d", &employee.id);
    getchar();
    printf("Ten nhan vien: ");
    fgets(employee.name, sizeof(employee.name), stdin);
    printf("Tuoi nhan vien: ");
    scanf("%d", &employee.age);
    getchar();
    printf("Que quan nhan vien: ");
    fgets(employee.homeTown, sizeof(employee.homeTown), stdin);
    printf("Phong ban truc: ");
    fgets(employee.division, sizeof(employee.division), stdin);
    printf("SDT nhan vien: ");
    fgets(employee.phone, sizeof(employee.phone), stdin);
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = employee;
    newNode->next = head;
    head = newNode;
}


void displayEmployees() {
    Node *curr = head;
    printf("Danh sach nhan vien\n");
    while (curr) {
        printf("ID: %d | Ten: %sTuoi: %d | Que quan: %sPhong ban: %sSDT: %s\n", curr->data.id, curr->data.name,
               curr->data.age, curr->data.homeTown, curr->data.division, curr->data.phone);
        curr = curr->next;
    }
}

void deleteEmployee() {
    int id;
    printf("Nhap id: ");
    scanf("%d", &id);
    Node *curr = head, *prev = NULL;
    while (curr) {
        if (curr->data.id == id) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            printf("da xoa\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Khong tim thay nhan vien\n");
}

void updateEmployee() {
    int id;
    printf("Nhap id nhan vien muon cap nhat: ");
    scanf("%d", &id);
    getchar();
    Node *current = head;
    while (current) {
        if (current->data.id == id) {
            printf("Nhap id moi cua nhan vien: ");
            scanf("%d", &current->data.id);
            printf("Nhap ten nhan vien: ");
            fgets(current->data.name, sizeof(current->data.name), stdin);
            printf("Nhap tuoi cua nhan vien: ");
            scanf("%d", &current->data.age);
            printf("Nhap que quan cua nhan vien: ");
            fgets(current->data.homeTown, sizeof(current->data.homeTown), stdin);
            printf("Nhap phong ban cua nhan vien: ");
            fgets(current->data.division, sizeof(current->data.division), stdin);
            printf("Nhap so dien thoai cua nhan vien: ");
            fgets(current->data.phone, sizeof(current->data.phone), stdin);
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay nhan vien\n");
}

void nghiViec() {
    char name[100];
    getchar();
    printf("Nhap ten nhan vien nghi viec: ");
    fgets(name, sizeof(name), stdin);
    Node *curr = head, *prev = NULL;
    while (curr) {
        if (strstr(curr->data.name, name)) {
            DNode *newNode = (DNode *) malloc(sizeof(DNode));
            newNode->data = curr->data;
            newNode->next = NULL;
            newNode->prev = tailResign;
            if (tailResign) tailResign->next = newNode;
            else headResign = newNode;
            tailResign = newNode;
            printf("Da chuyen sang danh sach nhan vien nghi viec\n");
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Khong tim thay nhan vien\n");
}

void sortByDivision() {
    for (Node *i = head; i && i->next; i = i->next) {
        for (Node *j = i->next; j; j = j->next) {
            if (strcmp(i->data.division, j->data.division) > 0) {
                Employee temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("da sap xep theo phong ban\n");
}

void searchByName() {
    char name[100];
    getchar();
    printf("Nhap ten nhan vien can tim: ");
    fgets(name, sizeof(name), stdin);
    Node *current = head;
    int found = 0;
    while (current) {
        if (strstr(current->data.name, name)) {
            printf("Da tim thay nhan vien\n");
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Khong tim thay\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Them nhan vien\n");
        printf("2. Hien thi danh sach nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Cap nhat thong tin nhan vien\n");
        printf("5. Di chuyen nhan vien nghi viec\n");
        printf("6. Sap xep nhan vien (Theo phong ban)\n");
        printf("7. Tim kiem nhan vien (Theo ten)\n");
        printf("8. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                nghiViec();

                break;
            case 6:
                sortByDivision();
                break;
            case 7:
                searchByName();
                break;
            case 8:
                printf("thoat");
                break;
            default:
                printf("khong hop le\n");
        }
    } while (choice != 8);
    return 0;
}
