#include<stdio.h>
//khai bao nut cay
struct NODE{
	int data;
	struct NODE *left, *right;
};
typedef struct NODE *node;

//ham tao node moi
node makenode(int x){
	node newnode = new NODE();
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//ham nhap day
void input(int a[], int n){
	printf("hay nhap gia tri cho tung phan tu trong mang: ");
	for(int i = 1 ; i<=n; i++){
		scanf("%d", &a[i]);
	}
}

//ham hien day
void show(int a[], int n){
	for(int i = 1 ; i<=n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b; 
	*b = tmp;
}
//vun dong
void heap(int a[], int n, int r){
for(int i = r; i>0; i--){
	int sign = i;
	if(i*2<=n){
		if(a[i] < a[i*2]){
			swap(&a[i], &a[i*2]);
			sign = i*2;
		}
	}
	if(i*2+1<=n){
		if(a[i] < a[i*2+1]){
			swap(&a[i], &a[i*2+1]);
			sign = i*2+1;
		}
	}
	if(sign != i){
		heap(a, n, sign);
	}
}
}

//sap xep vun dong
void heap_sort(int a[], int n){
	heap(a, n, n/2);
	for(int i = 1; i<=n; i++){
		swap(&a[1], &a[n-i+1]);
		heap(a, n-i, 1);
	}
}
