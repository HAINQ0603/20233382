#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Định nghĩa cấu trúc treeNode
typedef struct treeNode {
    char* word;                
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

// Hàm tạo một nút mới
treeNode* maketreenode(char* w) {
    treeNode* temp = (treeNode*)malloc(sizeof(treeNode));
    if (temp == NULL) return NULL;
    temp->word = strdup(w);  
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Hàm xây dựng cây biểu thức
treeNode* buildfunction() {
    // Tạo cây cho từng toán hạng và toán tử
    treeNode* a = maketreenode("a");
    treeNode* five = maketreenode("5");
    treeNode* multiply1 = maketreenode("*");
    multiply1->left = a;
    multiply1->right = five;

    treeNode* b = maketreenode("b");
    treeNode* c = maketreenode("c");
    treeNode* six = maketreenode("6");
    treeNode* power = maketreenode("^");
    power->left = c;
    power->right = six;

    treeNode* divide = maketreenode("/");
    divide->left = power;
    divide->right = b;

    treeNode* subtract = maketreenode("-");
    subtract->left = multiply1;
    subtract->right = divide;

    treeNode* h = maketreenode("h");
    treeNode* f = maketreenode("f");
    treeNode* subtract2 = maketreenode("-");
    subtract2->left = h;
    subtract2->right = f;

    treeNode* e = maketreenode("e");
    treeNode* oneHalf = maketreenode("1/2");  
    treeNode* power2 = maketreenode("^");
    power2->left = e;
    power2->right = oneHalf;

    treeNode* multiply2 = maketreenode("*");
    multiply2->left = subtract2;
    multiply2->right = power2;

    treeNode* add = maketreenode("+");
    add->left = subtract;
    add->right = multiply2;

    return add;
}

// Duyệt cây theo thứ tự trung tố 
void printOrder(treeNode* r) {
    if (r == NULL) return;
    if (r->left) printf("(");
    printOrder(r->left);
    printf("%s", r->word);  
    printOrder(r->right);
    if (r->right) printf(")");
}

// Duyệt cây theo thứ tự hậu tố 
void printPostOrder(treeNode* r) {
    if (r == NULL) return;
    printPostOrder(r->left);
    printPostOrder(r->right);
    printf("%s", r->word);
}

// Duyệt cây theo thứ tự tiền tố 
void printPreOrder(treeNode* r) {
    if (r == NULL) return;
    printf("%s", r->word);
    printPreOrder(r->left);
    printPreOrder(r->right);
}

// Hàm chính
int main() {
    treeNode* r = buildfunction();

    printf("Order: ");
    printOrder(r);
    printf("\n");

    printf("PostOrder: ");
    printPostOrder(r);
    printf("\n");

    printf("PreOrder: ");
    printPreOrder(r);
    printf("\n");

    return 0;
}