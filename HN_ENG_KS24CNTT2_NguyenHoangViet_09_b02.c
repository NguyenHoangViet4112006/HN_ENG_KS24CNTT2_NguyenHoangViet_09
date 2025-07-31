//
// Created by Nguyen Hoang Viet on 7/31/2025.
//
#include<stdio.h>


int main() {
    int choice;
    do {
        printf("1.Tao thu muc goc(root)\n");
        printf("2. Them thi muc con\n");
        printf("3. In cau truc thu muc\n");
        printf("4. Timf kiem thu muc theo ten\n");
        printf("5. Tinh chieu cao he thong thu muc\n");
        printf("6. In duong dan tu thu muc goc -> thu mu con\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:

                break;
            case 7:
                printf("Thoat");
                break;
            default:
                printf("khong hop le\n");
        }
    } while (choice != 7);
    return 0;
}
