#include<stdio.h>
#include<math.h>
//dinh nghia node
struct NODE{
	int data;
	struct NODE *left, *right;
};
typedef struct NODE *node;

//tao node moi
node makenode(int data){
	node newnode = new NODE();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//tao cay rong
void create_empty_tree(node &tr){
	tr = NULL;
}

//kiem tra cay rong
bool isempty(node tr){
	return tr == NULL;
}

//chen them node vao cay nhi phan tim kiem
void insert_node(node &tr, int data){
	if(isempty(tr)){
		tr = makenode(data);
	}
	else{
		if(data > tr->data){
			insert_node(tr->right, data);
		}
		else if(data < tr->data){
			insert_node(tr->left, data);
		}
	}
}

//duyet cay
	//NLR
	void NLR(node tr){
		if(!isempty(tr)){
			printf("%d ", tr->data);
			NLR(tr->left);
			NLR(tr->right);
		}
	}
	//NRL
	void NRL(node tr){
		if(!isempty(tr)){
			printf("%d ", tr->data);
			NRL(tr->right);
			NRL(tr->left);
		}
	}
		
	//LNR
	void LNR(node tr){
		if(!isempty(tr)){
			LNR(tr->left);
			printf("%d ", tr->data);
			LNR(tr->right);
		}
	}
		
	//RNL
	void RNL(node tr){
		if(!isempty(tr)){
			RNL(tr->right);
			printf("%d ", tr->data);
			RNL(tr->left);
		}	
	}
		
	//LRN
	void LRN(node tr){
		if(!isempty(tr)){
			LRN(tr->left);
			LRN(tr->right);
			printf("%d ", tr->data);
		}
	}
		
	//RLN
	void RLN(node tr){
		if(!isempty(tr)){
			RLN(tr->right);
			RLN(tr->left);
			printf("%d ", tr->data);
		}
	}
		
	
//tim kiem trong cay nhi phan tim kiem
bool search_node(node tr, int data){
	if(!isempty(tr)){
		if(data > tr->data){
			return search_node(tr->right, data);
		}
		else if(data < tr->data){
			return search_node(tr->left, data);
		}
		else if(data == tr->data){
			return true;
		}
	}
	return false;
}

//in ra cac node la node la
void print_node_leaf(node tr){
	if(!isempty(tr)){
		if(tr->left == NULL && tr->right == NULL){
			printf("%d ", tr->data);
		}
		print_node_leaf(tr->left);
		print_node_leaf(tr->right);
	}
}

//in ra cac node la node co 1 con
void print_node_1_leaf(node tr){
	if(!isempty(tr)){
		if((tr->left == NULL && tr->right !=NULL) || (tr->left != NULL && tr->right ==NULL)){
			printf("%d ", tr->data);
		}
		print_node_1_leaf(tr->left);
		print_node_1_leaf(tr->right);
	}
}

//in ra cac node la node co 2 con
void print_node_2_leaf(node tr){
	if(!isempty(tr)){
		if(tr->left != NULL && tr->right !=NULL){
			printf("%d ", tr->data);
		}
		print_node_2_leaf(tr->left);
		print_node_2_leaf(tr->right); 
	}
}

//tim gia tri max, min trong cay nhi phan tim kiem

//TIM MAX
	//cach 1: toi uu nhat
int max_in_tree(node tr){
	if(tr->right == NULL){
		return tr->data;
	}
	else{
		return max_in_tree(tr->right);
	}
}
	//cach 2: su dung bien toan cuc
int mx = -1e9;
int max_in_tree_1(node tr){
	if(!isempty(tr)){
		max_in_tree_1(tr->left);
		max_in_tree_1(tr->right);
		if(tr->data>mx){
			mx = tr->data;
		}
	}
	return mx;
}
	//cach 3: 
int max_in_tree_2(node tr){
	int Max = tr->data;
	if(tr->right == NULL){
		return tr->data;
	}
	else{
		int maxRight = max_in_tree_2(tr->right);
		if(maxRight > Max){
			Max = maxRight;
		}
	}
	return Max;
}

//TIM MIN
	//cach1: toi uu nhat
int min_in_tree(node tr){
	if(tr->left == NULL){
		return tr->data;
	}
	else{
		return min_in_tree(tr->left);
	}
}

	//cach2: su dung bien toan cuc
int mn = 1e9;
int min_in_tree_1(node tr){
	if(!isempty(tr)){
		min_in_tree_1(tr->left);
		min_in_tree_1(tr->right);
		if(tr->data<mn){
			mn = tr->data;
		}
	}
	return mn;
}

	//cach 3: 
int min_in_tree_2(node tr){
	int Min = tr->data;
	if(tr->left == NULL){
		return tr->data;
	}
	else{
		int minLeft = min_in_tree_2(tr->left);
		if(minLeft < Min){
			Min = minLeft;
		}
	}
	return Min;
}

//dem so luong phan tu trong cay nhi phan
	//cach 1: don gian nhat, su dung bien toan cuc
int cnt = 0;
int count_node(node tr){
	if(!isempty(tr)){
		count_node(tr->left);
		count_node(tr->right);
		cnt++;
	}
	return cnt;
}

	//cach 2: phuc tap hon
int count_node_1(node tr){
	if(isempty(tr)){
		return 0;
	}
	else{
		return count_node_1(tr->left) + count_node_1(tr->right) + 1;
	}
}

//dem so luong node la trong cay nhi phan tim kiem
	//cach 1: 
int count_node_leaf(node tr){
	if(isempty(tr)) return 0;
	else if(tr->left  == NULL && tr->right == NULL){
		return 1;
	}
	return count_node_leaf(tr->left) + count_node_leaf(tr->right);
}
	//cach 2: 
int cnt_leaf = 0;
int count_node_leaf_1(node tr){
	if(!isempty(tr)){
		count_node_leaf_1(tr->left);
		count_node_leaf_1(tr->right);
		if(tr->left == NULL && tr->right == NULL){
			cnt_leaf++;
		}
		
	}
	return cnt_leaf;
}

//dem so luong node la node 1 con trong cay nhi phan tim kiem
int cnt_1_leaf = 0;
int count_node_1_leaf(node tr){
	if(!isempty(tr)){
		count_node_1_leaf(tr->left);
		count_node_1_leaf(tr->right);
		if((tr->left == NULL && tr->right !=NULL) || (tr->left != NULL && tr->right ==NULL)){
			cnt_1_leaf++;
		}
	}
	return cnt_1_leaf;
}

//dem so luong node la node 2 con torng cay nhi phan tim kiem
int cnt_2_leaf = 0;
int count_node_2_leaf(node tr){
	if(!isempty(tr)){
		count_node_2_leaf(tr->left);
		count_node_2_leaf(tr->right);
		if(tr->left!=NULL && tr->right!=NULL){
			cnt_2_leaf++;
		}
	}
	return cnt_2_leaf;
}

//dem so luong node la snt trong cay nhi phan
	// check snt
	bool check_snt(int n){
		if(n<2){
			return false;
		}
		else if(n == 2){
			return true;
		}
		else{
			for(int i = 2; i<=sqrt(n); i++){
				if(n%i == 0){
					return false;
				}
			}
		}
		return true;
	}

int cnt_snt = 0;
int count_snt(node tr){
	if(!isempty(tr)){
		count_snt(tr->left);
		count_snt(tr->right);
		if(check_snt(tr->data)){
			cnt_snt++;
		}
	}
	return cnt_snt;
}

//tinh tong cac node hien co trong cay nhi phan tim kiem
	//cach 1: su dung bien toan cuc
int sm = 0;
int sum_tree(node tr){
	if(!isempty(tr)){
		sum_tree(tr->left);
		sum_tree(tr->right);
		sm+=tr->data;
	}
	return sm;
}

	//cach 2: phuc tap hon chut
int sum_tree_1(node tr){
	if(isempty(tr)){
		return 0;
	}
	else{
		return sum_tree_1(tr->left) + sum_tree_1(tr->right) + tr->data;
	}
}


//tinh trung binh cong cac phan tu trong cay nhi phan tim kiem
int average_tree(node tr){
	if(!isempty(tr)){
		return sum_tree_1(tr)/count_node(tr);
	}
}


//tim do sau lon nhat cua cay tinh tu node goc
int maxDeepTree(node tr){
	if(tr ==  NULL) return -1;
	else{
		return (maxDeepTree(tr->left)>maxDeepTree(tr->right)?maxDeepTree(tr->left):maxDeepTree(tr->right))+1;
	}
}

//tim do sau nho nhat tinh tu node goc
int minDeepTree(node tr){
	if(tr == NULL) return -1;
	else{
		return (minDeepTree(tr->left) < minDeepTree(tr->right)?minDeepTree(tr->left):minDeepTree(tr->right)) + 1;
	}
}

//tim do sau lon nhat tinh tu node bat ky
int maxDeepTree_at_x(node tr, int x){
	if(!isempty(tr)){
		if(x > tr->data){
			maxDeepTree_at_x(tr->right, x);
		}
		else if(x < tr->data){
			maxDeepTree_at_x(tr->left, x);
		}
		else{
			maxDeepTree(tr);
		}
	}
}

//tim do sau nho nhat tinh tu node bat ky
int minDeepTree_at_x(node tr, int x){
	if(!isempty(tr)){
		if(x > tr->data){
			minDeepTree_at_x(tr->right, x);
		}
		else if(x < tr->data){
			minDeepTree_at_x(tr->left, x);
		}
		else{
			minDeepTree(tr);
		}
	}
}


//xoa node la node la trong cay nhi phan
	//cach 1: don gian nhat
void delete_node_leaf(node &tr){
	if(!isempty(tr)){
	if(tr->left == NULL && tr->right == NULL){
			tr = NULL;
		} 
	else{
	  	delete_node_leaf(tr->left);
	  	delete_node_leaf(tr->right);
	  }
		
	}
}

	//cach 2: su dung ham co gia tri tra ve
node delete_node_leaf_1(node &tr){
	if(!isempty(tr)){
		if(tr->left == NULL && tr->right == NULL){
			delete tr;
			return NULL;
		}
		else{
			tr->left = delete_node_leaf_1(tr->left);
			tr->right = delete_node_leaf_1(tr->right);
		}
	}
	return tr;
}

//xoa node la node co mot con trong cay nhi phan
void delete_node_1_leaf(node &tr){
	if(!isempty(tr)){
		delete_node_1_leaf(tr->left);
		delete_node_1_leaf(tr->right);
		if((tr->left == NULL && tr->right !=NULL) || (tr->left != NULL && tr->right ==NULL)){
			node xoa = tr;
			if(tr->left == NULL){
				tr = tr->right;
			}
			else if(tr->right == NULL){
				tr = tr->left;
			}
			delete xoa;
		}
	}
}

//xoa node la node co hai con trong cay nhi phan tim kiem
//B1: di tim node the mang
//node the mang co 2 cach tim
//cach 1: node the mang la node ben trai cung cua node con ben phai cua node bi xoa
void nodethemang_1(node &x, node &y){
	if(y->left!=NULL){
		nodethemang_1(x, y->left);
	}
	else{
		x->data = y->data;
		x = y;
		y = y->right;
	}
}
//cach 2: node the mang la node ben phai cung cua node ben trai cua node bi xoa
void nodethemang_2(node &x, node &y){
	if(y->right!=NULL){
		nodethemang_2(x, y->right);
	}
	else{
		x->data = y->data;
		x = y;
		y = y->left;
	}
}

//B2: xoa
void delete_node_2_leaf(node &tr){
	if(!isempty(tr)){
		delete_node_2_leaf(tr->left);
		delete_node_2_leaf(tr->right);
		if(tr->left!=NULL && tr->right!=NULL){
			node x = tr;
			nodethemang_1(x, tr->right);
			delete x;
		}
	}
}



//xoa node bat ky nhap tu ban phim
void delete_any_node(node &tr, int data){
	if(!isempty(tr)){
		if(data > tr->data){
			delete_any_node(tr->right, data);
		}
		else if(data < tr->data){
			delete_any_node(tr->left, data);
		}
		else{
			if(tr->left == NULL && tr->right == NULL){
				tr = NULL;
			}
			else if((tr->left == NULL && tr->right!=NULL) || (tr->left != NULL && tr->right==NULL)){
				node erase = tr;
				if(tr->left == NULL){
					tr = tr->right;
				}
				else if(tr->right == NULL){
					tr = tr->left;
				}
				delete erase;
			}
			else if(tr->left != NULL && tr->right!=NULL){
				node erase = tr;
				nodethemang_2(erase, tr->left);
				delete erase;
			}
		}
	}
}




//cay nhi phan tong quat

//them node vao cay nhi phan tong quat
//B1; tim node cha
node  search_node_father(node tr, int x){
	if(!isempty(tr)){
		if(x == tr->data){
			return tr;
		}
		else{
			node p = search_node_father(tr->left, x);
			if(isempty(p)){
				p = search_node_father(tr->right, x);
				}
				return p;
// search_node_father(tr->left, x);
// search_node_father(tr->right, x);
			
		}
	}
	return NULL;
}

//B2: chen node vao cay nhi phan tong quat
void insert_node_tree_basic(node &tr, node newnode){
	if(isempty(tr)){
		tr = newnode;
		printf("da them vao node goc!\n");
		}
	else{
		printf("hay nhap node cha: ");
		int father_node; scanf("%d", &father_node);
		printf("nhap 1 de them vao ben trai node cha\n");
		printf("nhap 2 de them vao ben phai node cha\n");
		int select; scanf("%d", &select);
		if(select == 1){
			search_node_father(tr, father_node)->left = newnode;
		}
		else if(select == 2){
			search_node_father(tr, father_node)->right = newnode;
		}
	}
}

//B3: tao cay nhi phan tong quat
void create_tree_basic(node &tr){
	tr=NULL;
	printf("hay nhap so luong node cho cay nhi phan tong quat: ");
	int quantity; scanf("%d", &quantity);
	while(quantity--){
		printf("hay nhap gia tri cho node moi: ");
		int newdata;
		scanf("%d", &newdata);
		node newnode = makenode(newdata);
		insert_node_tree_basic(tr, newnode);
		
	}
}

//tim kiem trong cay nhi phan tong quat
//dem so luong phan tu trong cay nhi phan tong quat
//vv

