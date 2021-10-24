typedef struct{
    int x;
    int y;
    int size;
}Pos;


int* createMat(int* mat, int n);
void displayMat(int *mat, int n);
Pos findPgcb(int *mat, int n);
void displayMatPgcb(int *mat, int n, Pos position);