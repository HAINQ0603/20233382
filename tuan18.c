#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Cai dat luu tru ma tran ke
int graph_matrix[MAX_VERTICES][MAX_VERTICES];

void init_graph_matrix(int num_vertices) {
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph_matrix[i][j] = 0;
    }
  }
}

void add_edge_matrix(int u, int v) {
  graph_matrix[u][v] = 1;
  graph_matrix[v][u] = 1; // Do thi vo huong
}

// Cai dat luu tru danh sach ke
typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

Node *graph_list[MAX_VERTICES];

void init_graph_list(int num_vertices) {
  for (int i = 0; i < num_vertices; i++) {
    graph_list[i] = NULL;
  }
}

void add_edge_list(int u, int v) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = v;
  newNode->next = graph_list[u];
  graph_list[u] = newNode;

  newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = u;
  newNode->next = graph_list[v];
  graph_list[v] = newNode;
}

int main() {
  int num_vertices = 11;

  // Khoi tao ma tran ke
  init_graph_matrix(num_vertices);

  // Them cac canh vao ma tran ke
  add_edge_matrix(0, 5);  // Son Tay - Ha Noi
  add_edge_matrix(0, 10); // Son Tay - Hoa Binh
  add_edge_matrix(1, 5);  // Thai Nguyen - Ha Noi
  add_edge_matrix(2, 3);  // Bac Ninh - Bac Giang
  add_edge_matrix(2, 4);  // Bac Ninh - Uong Bi
  add_edge_matrix(2, 5);  // Bac Ninh - Ha Noi
  add_edge_matrix(3, 4);  // Bac Giang - Uong Bi
  add_edge_matrix(3, 5);  // Bac Giang - Ha Noi
  add_edge_matrix(4, 7);  // Uong Bi - Hai Phong
  add_edge_matrix(5, 6);  // Ha Noi - Hai Duong
  add_edge_matrix(5, 9);  // Ha Noi - Phu Ly
  add_edge_matrix(5, 10); // Ha Noi - Hoa Binh
  add_edge_matrix(6, 7);  // Hai Duong - Hai Phong
  add_edge_matrix(6, 8);  // Hai Duong - Hung Yen
  add_edge_matrix(8, 9);  // Hung Yen - Phu Ly

  // In ma tran ke
  printf("Ma tran ke:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      printf("%d ", graph_matrix[i][j]);
    }
    printf("\n");
  }

  // Khoi tao danh sach ke
  init_graph_list(num_vertices);

  // Them cac canh vao danh sach ke
  add_edge_list(0, 5);  // Son Tay - Ha Noi
  add_edge_list(0, 10); // Son Tay - Hoa Binh
  add_edge_list(1, 5);  // Thai Nguyen - Ha Noi
  add_edge_list(2, 3);  // Bac Ninh - Bac Giang
  add_edge_list(2, 4);  // Bac Ninh - Uong Bi
  add_edge_list(2, 5);  // Bac Ninh - Ha Noi
  add_edge_list(3, 4);  // Bac Giang - Uong Bi
  add_edge_list(3, 5);  // Bac Giang - Ha Noi
  add_edge_list(4, 7);  // Uong Bi - Hai Phong
  add_edge_list(5, 6);  // Ha Noi - Hai Duong
  add_edge_list(5, 9);  // Ha Noi - Phu Ly
  add_edge_list(5, 10); // Ha Noi - Hoa Binh
  add_edge_list(6, 7);  // Hai Duong - Hai Phong
  add_edge_list(6, 8);  // Hai Duong - Hung Yen
  add_edge_list(8, 9);  // Hung Yen - Phu Ly

  // In danh sach ke
  printf("\nDanh sach ke:\n");
  for (int i = 0; i < num_vertices; i++) {
    printf("%d: ", i);
    Node *current = graph_list[i];
    while (current != NULL) {
      printf("%d ", current->vertex);
      current = current->next;
    }
    printf("\n");
  }

  return 0;
}