#include <stdio.h>

// Hàm hoán đổi giá trị của hai biến
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    
    // Nhập số lượng đối tượng
    printf("nhap so doi tuong: ");
    scanf("%d", &n);
    
    int nums[n];
    
    // Nhập các giá trị màu (0 - đỏ, 1 - trắng, 2 - xanh)
    printf("nhap vao cac gia tri mau (0 - do, 1 - trang, 2 - xanh):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Sắp xếp các đối tượng bằng thuật toán Selection Sort
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                swap(&nums[i], &nums[j]);
            }
        }
    }
    
    // In kết quả sắp xếp
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            printf("do ");
        } else if (nums[i] == 1) {
            printf("trang ");
        } else if (nums[i] == 2) {
            printf("xanh ");
        }
    }
    
    return 0;
}