#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *year;
    int *number;
} Population;

int main() {
    Population a;
    int n = 3;
    int number;
    int found = 0; // Biến kiểm tra nếu tìm thấy năm thỏa mãn
    a.year = (int*)malloc(sizeof(int) * n); // Cấp phát động cho mảng năm
    a.number = (int*)malloc(sizeof(int) * n); // Cấp phát động cho mảng số lượng

    printf("Nhap so luong nguoi: ");
    scanf("%d", &number);

    printf("Nhap cac nam:\n");
    for (int i = 0; i < n; i++) {
        printf("Nam thu %d: ", i + 1);
        scanf("%d", &a.year[i]);
    }

    printf("Nhap so luong nguoi sinh ra trong cac nam:\n");
    for (int i = 0; i < n; i++) {
        printf("So luong nguoi sinh nam %d: ", a.year[i]);
        scanf("%d", &a.number[i]);
    }

    printf("\nCac nam co so luong nguoi sinh bang %d:\n", number);
    for (int i = 0; i < n; i++) {
        if (a.number[i] == number) {
            printf("%d ", a.year[i]);
            found = 1; // Đánh dấu là đã tìm thấy ít nhất một năm
        }
    }

    if (!found) {
        printf("Khong co nam nao thoa man");
    }
    printf("\n");

    // Tìm năm có số lượng người sinh nhiều nhất và ít nhất
    int max_value = a.number[0];
    int min_value = a.number[0];

    // Xác định giá trị lớn nhất và nhỏ nhất
    for (int i = 1; i < n; i++) {
        if (a.number[i] > max_value) {
            max_value = a.number[i];
        }
        if (a.number[i] < min_value) {
            min_value = a.number[i];
        }
    }

    // In ra các năm có số lượng người sinh nhiều nhất
    printf("Cac nam co so luong nguoi sinh nhieu nhat (%d): ", max_value);
    for (int i = 0; i < n; i++) {
        if (a.number[i] == max_value) {
            printf("%d ", a.year[i]);
        }
    }
    printf("\n");

    // In ra các năm có số lượng người sinh ít nhất
    printf("Cac nam co so luong nguoi sinh it nhat (%d): ", min_value);
    for (int i = 0; i < n; i++) {
        if (a.number[i] == min_value) {
            printf("%d ", a.year[i]);
        }
    }
    printf("\n");

    // Giải phóng bộ nhớ đã cấp phát
    free(a.year);
    free(a.number);

    return 0;
}