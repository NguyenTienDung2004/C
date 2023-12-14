#include"buoi6.h"
int main(){
	int n;
	printf("hay nhap so luong phan tu cho mang: "); scanf("%d", &n);
	int a[n];
	input(a, n);
	heap(a, n, n/2);
	printf("sau khi duoc vun dong: ");
	heap_sort(a, n);
	show(a, n);
}
