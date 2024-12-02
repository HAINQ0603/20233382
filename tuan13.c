#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc hàng hóa
typedef struct {
    char tenHang[50];   // Tên hàng hóa
    int soLuong;        // Số lượng
    float donGia;       // Đơn giá
} HangHoa;

// Cấu trúc giỏ hàng (node trong hàng đợi)
typedef struct Node {
    HangHoa *danhSachHang; // Danh sách các mặt hàng
    int soMatHang;         // Số mặt hàng trong giỏ
    float tongTien;        // Tổng tiền thanh toán
    struct Node *next;     // Con trỏ đến node tiếp theo
} Node;

// Cấu trúc hàng đợi
typedef struct {
    Node *front;   // Đầu hàng đợi
    Node *rear;    // Cuối hàng đợi
} HangDoi;

// Khởi tạo hàng đợi
void khoiTaoHangDoi(HangDoi *hd) {
    hd->front = NULL;
    hd->rear = NULL;
}

// Thêm hàng vào hàng đợi
void themVaoHangDoi(HangDoi *hd, HangHoa *danhSach, int soMatHang) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->danhSachHang = danhSach;
    newNode->soMatHang = soMatHang;
    newNode->tongTien = 0;
    newNode->next = NULL;

    // Tính tổng tiền cho giỏ hàng
    for (int i = 0; i < soMatHang; i++) {
        newNode->tongTien += danhSach[i].soLuong * danhSach[i].donGia;
    }

    if (hd->rear == NULL) {
        hd->front = newNode;
        hd->rear = newNode;
    } else {
        hd->rear->next = newNode;
        hd->rear = newNode;
    }
}

// Xóa một giỏ hàng
Node *xoaKhoiHangDoi(HangDoi *hd) {
    if (hd->front == NULL) return NULL;

    Node *temp = hd->front;
    hd->front = hd->front->next;

    if (hd->front == NULL) {
        hd->rear = NULL;
    }

    return temp; // Trả về giỏ hàng đã xóa
}

// Tính tổng tiền
float tinhTien(HangDoi *hd) {
    float tongTien = 0;
    Node *current = hd->front;

    while (current != NULL) {
        tongTien += current->tongTien;
        current = current->next;
    }

    return tongTien;
}

// So sánh chuỗi
int Compare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0; 
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

// Đếm số sản phẩm A
int demSanPhamA(HangDoi *hd, const char *tenSanPham) {
    int count = 0;
    Node *current = hd->front;

    while (current != NULL) {
        for (int i = 0; i < current->soMatHang; i++) {
            if (Compare(current->danhSachHang[i].tenHang, tenSanPham) == 0) {
                count += current->danhSachHang[i].soLuong;
            }
        }
        current = current->next;
    }

    return count;
}

int main() {
    HangDoi hd;
    khoiTaoHangDoi(&hd);

    // Tạo giỏ hàng 1
    HangHoa gio1[] = {
        {"Táo", 2, 20000},
        {"Vở", 1, 15000}
    };
    themVaoHangDoi(&hd, gio1, 2);

    // Tạo giỏ hàng 2
    HangHoa gio2[] = {
        {"Cam", 3, 30000},
        {"Táo", 1, 20000}
    };
    themVaoHangDoi(&hd, gio2, 2);

    // Tính tổng tiền
    printf("Tong tien thu duoc: %.2f VND\n", tinhTien(&hd));

    // Đếm số lượng sản phẩm "Táo"
    printf("So luong San pham Tao: %d\n", demSanPhamA(&hd, "Táo"));

    return 0;
}