#include <stdio.h>
#include <stdlib.h>

// Cau truc nut cua danh sach lien ket
struct Node {
    int data;
    struct Node* next;
};

// Ham tao nut moi
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Ham chen nut moi vao danh sach lien ket
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* tmp = head;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = newNode;
    return head;
}

// Ham kiem tra so nguyen to
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Ham in danh sach lien ket
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Ham kiem tra xem gia tri co ton tai trong danh sach lien ket khong
int isPresent(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) return 1;
        temp = temp->next;
    }
    return 0;
}

// Ham tim cac cap so Blum co tong cung la so Blum
void findBlumPairs(struct Node* head, int n) {
    struct Node* p1 = head;
    int count = 0;
    while (p1 != NULL) {
        struct Node* p2 = p1->next;
        while (p2 != NULL) {
            int sum = p1->data + p2->data;
            if (sum < n && isPresent(head, sum)) {
                printf("(%d, %d) ", p1->data, p2->data);
                count++;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    if (count == 0) {
        printf("Khong tim thay cap so hop le\n");
    }
    printf("\n");
}

int main() {
    struct Node* primeList = NULL;
    struct Node* productList = NULL;
    int n, m;
    
    // Gioi han cho so Blum
    printf("Nhap gioi han cho so Blum (N): ");
    scanf("%d", &n);
    printf("Kiem tra so (M): ");
    scanf("%d", &m);
    
    // Tao danh sach so Blum
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            struct Node* tmp = primeList;
            while (tmp != NULL) {
                int product = tmp->data * i;
                if (product >= n) break;
                productList = insert(productList, product);
                tmp = tmp->next;
            }
            int square = i * i;
            if (square < n) {
                productList = insert(productList, square);
            }
            primeList = insert(primeList, i);
        }
    }
    
    // In danh sach so Blum
    printf("Cac so Blum nho hon %d:\n", n);
    printList(productList);
    
    // Yeu cau 1: Tim cap so Blum co tong cung la so Blum
    printf("Cac cap so Blum co tong cung la so Blum:\n");
    findBlumPairs(productList, n);
    
    // Yeu cau 2: Kiem tra so Blum M co ton tai trong danh sach khong
    if (isPresent(productList, m)) {
        printf("%d la mot so Blum\n", m);
    } else {
        printf("%d khong phai la mot so Blum\n", m);
    }
    
    return 0;
}
