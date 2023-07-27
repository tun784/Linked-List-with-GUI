#include<iostream>
#include<cstdlib>
#include"MyLib.h"

//Macro
typedef int Data;

//=====================================
//Struct and Constant
//Single List
struct NODE
{
	Data info;
	NODE* next; //Tro den node tiep theo
};
struct SList
{
	NODE* head;
	NODE* tail;
};
//Stack
struct Stack
{
	NODE* top;
};

//=====================================
//Prototype
void thucHienChuongTrinh();
NODE* createNode(Data x);
void deleteNode(NODE*& p);
//Single List
void initList(SList& l);
bool isEmptyList(SList l);
void checkMemory(NODE* p);
void createSList_Manual(SList& l, int n);
void createSList_Random(SList& l, int n);
void showSList(SList l);
void _nhapXuatDSLK(SList& l, int& n);
NODE* searchSList(SList l, int x);
void addHeadSList(SList& l, NODE* p);
void addTailSList(SList& l, NODE* p);
void addAfterNodeSList(SList& l, NODE* q, NODE* p);
void nhapx(int& x);
void _themNodePsauNodeQ(SList& l, NODE*& q, NODE*& p, int& n);
void deleteHeadSList(SList& l);
void deleteTailSList(SList& l);
void interchangeSortSList_Ascending(SList& l);
void interchangeSortSList_Descending(SList& l);
void deleteAfterNodeSList(SList& l, NODE* q, NODE* p);
void _xoaNodePsauNodeQ(SList& l, NODE*& p, NODE*& q, int& n);
int countSList(SList l);
int sumOfSList(SList l);
void xuatCacPTChan(SList l);
void xuatCacPTLe(SList l);
void _XuatCacPTChan_Le(SList l);
void xuatCacPTVTChan(SList l);
void xuatCacPTVTLe(SList l);
void _XuatCacPTVTChan_Le(SList l);
int countXInSList(SList l, int x);
int timPTMaxSList(SList l);
int timPTMinSList(SList l);
int isEmptyEvenSList(SList l);
int isEmptyOddSList(SList l);
int timPTChanMinSList(SList l);
int timPTLeMaxSList(SList l);
int timPTChanMaxSlist(SList l);
int timPTLeMinSList(SList l);
void xoaPTMaxDSLK(SList& l, int n);
void xoaPTMinDSLK(SList& l, int n);
void _XoaCacPTMax_Min(SList l, int n);
void themPTXCucDai(SList& l);
int isAscendingSList(SList l);
int isDescendingSList(SList l);
void _KiemTraDSLKTang_Giam(SList& l, int& n);
//Stack
void createStack_Random(Stack& s, int& n);
void showStack(Stack& s);
void _nhapXuatStack(Stack& s, int& n);
void checkTopStack(Stack s);
void _ThemVaoDinh(Stack& s);
int checkPriority(char x);
void convertInfixToPostfix(Stack& s, char* P, char* Q);
int calc(char op, int x, int y);
int calculateInfix(Stack s, char* Q);
//=====================================
//Main
int main(){
	loading();
	thucHienChuongTrinh();
	//TestBGColor();
	return 0;
}

//=====================================
//Functions
void thucHienChuongTrinh()
{
	int a[100];
	int chon, n, x;
	SList l;
	Stack s;
	NODE* q, * p;
	srand((int)time(NULL));
	do
	{
		system("cls");
		XY(35, 6);
		BGcolor(6);
		std::cout << "-=Chuong trinh X=-";
		chon = menu_02();
		system("cls");
		std::cout << "Your choice is: " << chon << std::endl;
		ShowCur(1);
		SetScreenBufferSize(90, 90);
		switch (chon)
		{
		case 1:
		{
			_nhapXuatDSLK(l, n);
			break;
		}
		case 2:
		{
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			std::cout << "Nhap vao node can tim: ";
			std::cin >> x;
			q = searchSList(l, x);
			if (!q)
			{
				std::cout << "\t  <Not Found!>";
			}
			else
			{
				std::cout << "-Tim thay " << x << " tai vi tri truoc ";
				if (!q->next)
				{
					std::cout << "[NULL]" << std::endl;
				}
				else
				{
					std::cout << "[" << q->next->info << "]" << std::endl;
				}
			}
			break;
		}
		case 3:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			nhapx(x);
			q = createNode(x);
			addHeadSList(l, q);
			std::cout << std::endl;
			showSList(l);
			break;
		case 4:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			nhapx(x);
			q = createNode(x);
			addTailSList(l, q);
			std::cout << std::endl;
			showSList(l);
			break;
		case 5:
			_themNodePsauNodeQ(l, q, p, n);
			break;
		case 6:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			deleteHeadSList(l);
			showSList(l);
			break;
		case 7:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			deleteTailSList(l);
			showSList(l);
			break;
		case 8:
			_xoaNodePsauNodeQ(l, p, q, n);
			showSList(l);
			break;
		case 9:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			interchangeSortSList_Ascending(l);
			showSList(l);
			break;
		case 10:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			interchangeSortSList_Descending(l);
			showSList(l);
			break;
		case 11:
			_nhapXuatDSLK(l, n);
			std::cout << "-So luong phan tu trong DSLK don: " << countSList(l);
			break;
		case 12:
			_nhapXuatDSLK(l, n);
			std::cout << "-Tong cac node trong DSLK don: " << sumOfSList(l);
			break;
		case 13:
			_nhapXuatDSLK(l, n);
			_XuatCacPTChan_Le(l);
			break;
		case 14:
			_nhapXuatDSLK(l, n);
			_XuatCacPTVTChan_Le(l);
			break;
		case 15:
			_nhapXuatDSLK(l, n);
			std::cout << "Nhap phan tu can dem: ";
			std::cin >> x;
			std::cout << "Co " << countXInSList(l,x) << " phan tu " << x << " trong DSLK don";
			break;
		case 16:
			_nhapXuatDSLK(l, n);
			std::cout << "\nPhan tu lon nhat trong DSLK: " << timPTMaxSList(l);
			std::cout << "\nPhan tu nho nhat trong DSLK: " << timPTMinSList(l);
			break;
		case 17:
			_nhapXuatDSLK(l, n);
			std::cout << "\nPhan tu chan nho nhat trong DSLK: " << timPTChanMinSList(l);
			break;
		case 18:
			_nhapXuatDSLK(l, n);
			std::cout << "\nPhan tu le lon nhat trong DSLK: " << timPTLeMaxSList(l);
			break;
		case 19:
			_nhapXuatDSLK(l, n);
			std::cout << "\nPhan tu chan lon nhat trong DSLK: " << timPTChanMaxSlist(l);
			break;
		case 20:
			_nhapXuatDSLK(l, n);
			std::cout << "\nPhan tu le nho nhat trong DSLK: " << timPTLeMinSList(l);
			break;
		case 21:
			_nhapXuatDSLK(l, n);
			_XoaCacPTMax_Min(l, n);
			showSList(l);
			break;
		case 22:
			_nhapXuatDSLK(l, n);
			themPTXCucDai(l);
			showSList(l);
			break;
		case 23:
			_KiemTraDSLKTang_Giam(l, n);
			break;
		case 24:
			break;
		case 25:
			_nhapXuatStack(s, n);
			break;
		case 26:
			_nhapXuatStack(s, n);
			std::cout << "Top of Stack: ";
			checkTopStack(s);
			break;
		case 27:
			char chon_1;
			_nhapXuatStack(s, n);
			do
			{
				_ThemVaoDinh(s);
				showStack(s);
				std::cout << "\nBan co muon them tiep ? Y/N - ";
				std::cin >> chon_1;
			} while (chon_1 == 'Y' || chon_1 == 'y');
			
			break;
		case 28:
			char P[100], Q[100];
			std::cout << "Nhap bieu thuc trung to: ";
			std::cin >> P;
			convertInfixToPostfix(s, P, Q);
			std::cout << "\nBieu thuc hau to: " << Q << std::endl;
			break;
		case 29:
			std::cout << "Nhap bieu thuc trung to: ";
			std::cin >> P;
			convertInfixToPostfix(s, P, Q);
			std::cout << "\nBieu thuc hau to: " << Q << std::endl;
			std::cout << "Ket qua: " << calculateInfix(s, Q);
			break;
		default:
			system("cls");
			XY(30, 2);
			std::cout << "Thanks for your patient!" << std::endl;
			break;
		}
		std::cout << std::endl;
		system("pause");
	} while (chon > 0 && chon < 30);
}
//NODE
NODE* createNode(Data x)
{
	NODE* p = new NODE;
	if (!p)
	{
		std::cout << "Not enough memory!" << std::endl;
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void deleteNode(NODE*& p)
{
	if (!p)
	{
		return;
	}
	delete p;
}
//Single List
void initList(SList& l)
{
	l.head = l.tail = NULL;
}

bool isEmptyList(SList l)
{
	return l.head == NULL;
}

void checkMemory(NODE* p)
{
	if (!p)
	{
		BGcolor(4);
		std::cout << "Not Enough Memory!" << std::endl;
		return;
	}
}

void createSList_Manual(SList& l, int n)
{
	int x;
	NODE* p;
	initList(l);
	for (int i = 0; i < n; i++)
	{
		//Input infomation
		std::cout << "Nhap node thu " << i << " :";
		std::cin >> x;
		//Create NODE
		p = createNode(x);
		//Check memory
		if (!p)
		{
			BGcolor(4);
			std::cout << "Not Enough Memory!" << std::endl;
			return;
		}
		//Add p into SList
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{						// [1|2]: [info|next]
			l.tail->next = p;	// [1|2]->[2|NULL]->NULL
			l.tail = p;			// [1|2]->[2|3]->[3|NULL]->NULL
		}
	}
}
void createSList_Random(SList& l, int n)
{
	int x;
	NODE* p;
	initList(l);
	for (int i = 0; i < n; i++)
	{
		//Generate infomation
		x = rand() % 100;
		//Create NODE
		p = createNode(x);
		//Check memory
		if (!p)
		{
			BGcolor(4);
			std::cout << "Not Enough Memory!" << std::endl;
			system("pause");
			return;
		}
		//Add p into SList l
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}
void _nhapXuatDSLK(SList& l, int& n)
{
	int chon;
	std::cout << "Nhap n: ";
	std::cin >> n;
	if (n < 0)
	{
		std::cout << "Processing to main Menu..." << std::endl;
		Sleep(500);
		return;
	}
	//Menu
	ShowCur(0);
	std::cout << "Vui long chon cach nhap DSLK: ";
	const char* s[100] = { "1. Nhap tu dong","2. Nhap thu cong" };
	chon = control(2, 30, 2, s);
	std::cout << std::endl;
	ShowCur(1);
	//-------
	switch (chon)
	{
	case 1:
		createSList_Random(l, n);
		goto x;
	case 2:
		createSList_Manual(l, n);
		goto x;
	default:
		std::cout << "Processing to main Menu..." << std::endl;
		Sleep(500);
		return;
	}
x: showSList(l);
}
void showSList(SList l)
{
	NODE* p;
	p = l.head;
	std::cout << "\n\n\t-Single List-" << std::endl;
	if (!p)
	{
		std::cout << "\t  <Empty!>" << std::endl;
	}
	while (p)
	{
		std::cout << "[" << p->info << "]-> ";
		p = p->next;
	}
	if (!p)
	{
		std::cout << "[NULL]" << std::endl;
	}
}

NODE* searchSList(SList l, int x)
{
	NODE* p;
	p = l.head;
	while (p)
	{
		if (p->info == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void addHeadSList(SList& l, NODE* p)
{
	if (!p)
	{
		return;
	}
	else
	{
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{
			p->next = l.head;
			l.head = p;
		}
	}
}

void nhapx(int& x)
{
	std::cout << "Nhap node muon them vao DSLK don: ";
	std::cin >> x;
}
void addTailSList(SList& l, NODE* p)
{
	if (!p)
	{
		return;
	}
	else
	{
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}

void addAfterNodeSList(SList& l, NODE* q, NODE* p)
{
	if (!p || !q)
	{
		return;
	}
	else
	{
		if (isEmptyList(l) == 1)
		{
			l.head = l.head = q;
		}
		else
		{
			if (q == l.tail)
			{
				addTailSList(l, p);
			}
			else
			{
				p->next = q->next;
				q->next = p;
			}
		}
	}
}

void _themNodePsauNodeQ(SList& l, NODE*& q, NODE*& p, int& n)
{
	int x, y;
	_nhapXuatDSLK(l, n);
	if (n <= 0)
	{
		return;
	}
	std::cout << "Nhap node q: ";
	std::cin >> y;
	std::cout << "Nhap node p muon them vao sau node q: ";
	std::cin >> x;
	p = createNode(x);
	q = l.head;
	while (q)
	{
		if (q->info == y)//Find node q
		{
			addAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
	std::cout << std::endl;
	showSList(l);
}

void deleteHeadSList(SList& l)
{
	if (isEmptyList(l) == 1)
	{
		return;
	}
	else
	{
		NODE* p = l.head;
		l.head = p->next;//Chuyen head cho node tiep theo
		p->next = NULL;
		delete p;
	}
}

void deleteTailSList(SList& l)
{
	if (isEmptyList(l) == 1)
	{
		return;
	}
	else
	{
		NODE* p = l.tail;
		NODE* q = l.head;
		//Cho q chay cho den node trc tail
		while (q->next != l.tail)
		{
			q = q->next;
		}
		//Cat node tail r thay q lam tail
		l.tail = q;
		l.tail->next = NULL;
		delete p;
	}
}

void deleteAfterNodeSList(SList& l, NODE* q, NODE* p)
{
	if (isEmptyList(l) == 1 || !p || !q)
	{
		return;
	}
	else
	{
		if (p == l.tail)
		{
			deleteTailSList(l);
		}
		else
		{
			if (p == l.head)
			{
				deleteHeadSList(l);
			}
			else
			{
				q->next = p->next;
				p->next = NULL;
				delete p;
			}
		}
	}
}

void _xoaNodePsauNodeQ(SList& l, NODE*& p, NODE*& q, int& n)
{
	int x, y;
	_nhapXuatDSLK(l, n);
	if (n <= 0)
	{
		return;
	}
	std::cout << "Nhap node p muon xoa: ";
	std::cin >> x;
	q = l.head;
	while (q)
	{
		if (q->next->info == x)
		{
			p = q->next; //NODE can xoa
			deleteAfterNodeSList(l, q, p);
			return;
		}
		if (!q->next->info)
		{
			std::cout << "Not found!" << std::endl;
			return;
		}
		q = q->next;
	}
}

void interchangeSortSList_Ascending(SList& l)
{
	for (NODE* p = l.head; p != l.tail; p = p->next)
	{
		for (NODE* q = p->next; q != NULL; q = q->next)
		{
			if (p->info > q->info)
			{
				std::swap(p->info, q->info);
			}
		}
	}
}

void interchangeSortSList_Descending(SList& l)
{
	for (NODE* p = l.head; p != l.tail; p = p->next)
	{
		for (NODE* q = p->next; q != NULL; q = q->next)
		{
			if (p->info < q->info)
			{
				std::swap(p->info, q->info);
			}
		}
	}
}

int countSList(SList l)
{
	int count = 0;
	NODE* p;
	p = l.head;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

int sumOfSList(SList l)
{
	int S = 0;
	NODE* p;
	p = l.head;
	while (p)
	{
		S += p->info;
		p = p->next;
	}
	return S;
}

void xuatCacPTChan(SList l)
{
	NODE* p;
	p = l.head;
	while (p)
	{
		if (p->info % 2 == 0)
		{
			std::cout << "[" << p->info << "]-> ";
		}
		p = p->next;
	}
}

void xuatCacPTLe(SList l)
{
	NODE* p;
	p = l.head;
	while (p)
	{
		if (p->info % 2 != 0)
		{
			std::cout << "[" << p->info << "]-> ";
		}
		p = p->next;
	}
}

void _XuatCacPTChan_Le(SList l)
{
	int chon = 0;
	ShowCur(0);
	std::cout << "Vui long chon loai xuat pt DSLK: ";
	const char* s[100] = { "1. Xuat pt chan","2. Xuat pt le" };
	chon = control(2, 33, 7, s);
	std::cout << std::endl;
	ShowCur(1);
	std::cout << "\n\n";
	switch (chon)
	{
	case 1:
		xuatCacPTChan(l);
		break;
	case 2:
		xuatCacPTLe(l);
		break;
	}
}

void xuatCacPTVTChan(SList l)
{
	int i = 0;
	NODE* p = l.head;
	while (p)
	{
		if (i % 2 == 0)
		{
			std::cout << "[" << p->info << "]-> ";
		}
		i++;
		p = p->next;
	}
}

void xuatCacPTVTLe(SList l)
{
	int i = 0;
	NODE* p = l.head;
	while (p)
	{
		if (i % 2 != 0)
		{
			std::cout << "[" << p->info << "]-> ";
		}
		i++;
		p = p->next;
	}
}

void _XuatCacPTVTChan_Le(SList l)
{
	int chon = 0;
	ShowCur(0);
	std::cout << "Vui long chon loai xuat pt DSLK: ";
	const char* s[100] = { "1. Xuat pt vi tri chan","2. Xuat pt vi tri le" };
	chon = control(2, 33, 7, s);
	std::cout << std::endl;
	ShowCur(1);
	std::cout << "\n\n";
	switch (chon)
	{
	case 1:
		xuatCacPTVTChan(l);
		break;
	case 2:
		xuatCacPTVTLe(l);
		break;
	}
}

int countXInSList(SList l, int x)
{
	int dem = 0;
	NODE* p = l.head;

	while (p)
	{
		if (p->info == x)
		{
			dem++;
		}
		p = p->next;
	}

	return dem;
}

int timPTMaxSList(SList l)
{
	NODE* p = l.head;
	int max = l.head->info;
	while (p)
	{
		if (p->info > max)
		{
			max = p->info;
		}
		p = p->next;
	}
	return max;
}

int timPTMinSList(SList l)
{
	NODE* p = l.head;
	int min = l.head->info;
	while (p)
	{
		if (p->info < min)
		{
			min = p->info;
		}
		p = p->next;
	}
	return min;
}

int isEmptyEvenSList(SList l)
{
	NODE* p = l.head;
	int check = 0;
	while (p)
	{
		if (p->info % 2 == 0)
		{
			check++;
		}
		p = p->next;
	}
	if (check == 0)
	{
		return 1;
	}
	return 0;
}

int isEmptyOddSList(SList l)
{
	NODE* p = l.head;
	int check = 0;
	while (p)
	{
		if (p->info % 2 != 0)
		{
			check++;
		}
		p = p->next;
	}
	if (check == 0)
	{
		return 1;
	}
	return 0;
}

int timPTChanMinSList(SList l)
{
	NODE* p = l.head;
	int min, dem = 0;
	//Check List
	if (p == NULL || isEmptyEvenSList(l) == 1)
	{
		return -1;
	}
	//Find first even num
	while (p)
	{
		if (p->info % 2 == 0)
		{
			min = p->info;
			break;
		}
		p = p->next;
	}
	//Find min even num
	while (p)
	{
		if (p->info % 2 == 0 && p->info < min)
		{
			min = p->info;
		}
		p = p->next;
	}
	return min;
}

int timPTLeMaxSList(SList l)
{
	int max;
	NODE* p = l.head;
	//Check
	if (p == NULL || isEmptyOddSList(l) == 1)
	{
		return 0;
	}

	//Find first odd num
	while (p)
	{
		if (p->info % 2 != 0)
		{
			max = p->info;
			break;
		}
		p = p->next;
	}
	//Find max odd num
	while (p)
	{
		if (p->info % 2 != 0 && p->info > max)
		{
			max = p->info;
		}
		p = p->next;
	}
	return max;
}

int timPTChanMaxSlist(SList l)
{
	int max;
	NODE* p = l.head;
	if (p == NULL || isEmptyEvenSList(l) == 1)
	{
		return -1;
	}
	while (p)
	{
		if (p->info % 2 == 0)
		{
			max = p->info;
			break;
		}
		p = p->next;
	}
	while (p)
	{
		if (p->info % 2  == 0 && p->info > max)
		{
			max = p->info;
		}
		p = p->next;
	}
	return max;
}

int timPTLeMinSList(SList l)
{
	int min;
	NODE* p = l.head;
	if (p == NULL || isEmptyOddSList(l) == 1)
	{
		return 0;
	}
	while (p)
	{
		if (p->info % 2 != 0)
		{
			min = p->info;
			break;
		}
		p = p->next;
	}
	while (p)
	{
		if (p->info % 2 != 0 || p->info < min)
		{
			min = p->info;
		}
		p = p->next;
	}
	return min;
}

void xoaPTMaxDSLK(SList& l, int n)
{
	NODE* q, * p;
	int x = timPTMaxSList(l);
	std::cout << "Phan tu Max: " << x;
	
	while (l.head->info == x)
	{
		deleteHeadSList(l);
		if (l.head == NULL)
		{
			return;
		}
	}
	
	while (l.tail->info == x)
	{
		deleteTailSList(l);
		if (l.tail == NULL)
		{
			return;
		}
	}
	
	q = l.head;
	while (q)
	{
		if (q->next == NULL)
		{
			break;
		}
		while (q->next->info == x)
		{
			p = q->next; //NODE can xoa
			deleteAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
}

void xoaPTMinDSLK(SList& l, int n)
{
	NODE* q, * p;
	int x = timPTMinSList(l);
	std::cout << "Phan tu Min: " << x;
	while (l.head->info == x)
	{
		deleteHeadSList(l);
		if (l.head == NULL)
		{
			return;
		}
	}
	while (l.tail->info == x)
	{
		deleteTailSList(l);
		if (l.tail == NULL)
		{
			return;
		}
	}
	q = l.head;
	while (q)
	{
		if (q->next == NULL)
		{
			return;
		}
		if (q->next->info == x)
		{
			p = q->next;
			deleteAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
}
void _XoaCacPTMax_Min(SList l, int n)
{
	int chon = 0;
	ShowCur(0);
	std::cout << "Vui long chon: ";
	const char* s[100] = { "1. Xoa PT Max","2. Xoa PT Min" };
	chon = control(2, 33, 7, s);
	std::cout << std::endl;
	ShowCur(1);
	std::cout << "\n\n";
	switch (chon)
	{
	case 1:
		xoaPTMaxDSLK(l, n);
		break;
	case 2:
		xoaPTMinDSLK(l, n);
		break;
	}
}

void themPTXCucDai(SList& l)
{
	int x;
	NODE* q, * p;
	nhapx(x);
	q = l.head;
	while (q)
	{
		if (q->next == NULL)
		{
			return;
		}
		if (q->info < x && q->next->info < x)
		{
			p = createNode(x);
			addAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
}

int isAscendingSList(SList l)
{
	NODE* p = l.head;
	if (isEmptyList(l) == NULL)
	{
		return 0;
	}

	while (p)
	{
		if (p->info > p->next->info)
		{
			return 0;
		}
		p = p->next;
	}

	return 1;
}
int isDescendingSList(SList l)
{
	NODE* p = l.head;
	if (isEmptyList(l) == NULL)
	{
		return 0;
	}

	while (p)
	{
		if (p->info < p->next->info)
		{
			return 0;
		}
		p = p->next;
	}

	return 1;
}
void _KiemTraDSLKTang_Giam(SList& l, int &n)
{
	int chon = 0;
	_nhapXuatDSLK(l, n);
	ShowCur(0);
	std::cout << "Vui long chon: ";
	const char* s[100] = { "1. Kiem tra DSLK tang","2. Kiem tra DSLK giam" };
	chon = control(2, 33, 7, s);
	std::cout << std::endl;
	ShowCur(1);
	std::cout << "\n\n";
	switch (chon)
	{
	case 1:	
		if (isAscendingSList(l) == 1)
		{
			std::cout << "\nTRUE" << std::endl;
		}
		else
		{
			std::cout << "\nFALSE" << std::endl;
		}
		break;
	case 2:
		if (isDescendingSList(l) == 1)
		{
			std::cout << "\nTRUE" << std::endl;
		}
		else
		{
			std::cout << "\nFALSE" << std::endl;
		}
		break;
	}
}
//================
//Stack 
NODE* pushS(Stack& s, NODE* p)
{
	if (p)
	{
		if (!s.top)
		{
			s.top = p;
		}
		else
		{
			p->next = s.top;
			s.top = p;
		}
	}
	return p;
}

NODE* popS(Stack& s)
{
	NODE* p = NULL;
	if (s.top)
	{
		p = s.top;
		s.top = s.top->next;
		p->next = NULL;
	}
	return p;
}

void initStack(Stack& s)
{
	s.top = NULL;
}

bool isEmptyStack(Stack s)
{
	return s.top == NULL;
}

void createStack_Random(Stack& s,int &n)
{
	int x;
	NODE* q;
	std::cout << "Nhap n: ";
	std::cin >> n;
	initStack(s);
	for (int i = 0; i < n; i++)
	{
		x = rand() % 100;
		q = createNode(x);
		checkMemory(q);
		if (isEmptyStack(s) == 1)
		{
			s.top = q;
		}
		else
		{
			pushS(s, q);
		}
	}
}

void showStack(Stack& s)
{
	NODE* p = s.top;
	std::cout << "\n\n\t-Stack-" << std::endl;
	if (!p)
	{
		std::cout << "\t<Empty!>" << std::endl;
	}
	while (p)
	{
		if (p == s.top)
		{
			std::cout << "-> " << p->info << "|";
		}
		else
		{
			if (!p->next)
			{
				std::cout << p->info << "]";
			}
			else
			{
				std::cout << p->info << "|";
			}
		}
		p = p->next;
	}
}

void _nhapXuatStack(Stack& s, int &n)
{
	createStack_Random(s, n);
	showStack(s);
	std::cout << std::endl;
}

void checkTopStack(Stack s)
{
	if (isEmptyStack(s) == 1)
	{
		std::cout << "<Empty>";
	}
	else
	{
		std::cout << s.top->info;
	}
}

void _ThemVaoDinh(Stack& s)
{
	int x;
	NODE* p;
	nhapx(x);
	p = createNode(x);
	pushS(s, p);
}

int checkPriority(char x)
{
	if (x == '^')
	{
		return 3;
	}
	if (x == '*' || x == '/')
	{
		return 2;
	}
	return 1;
}
void convertInfixToPostfix(Stack& s, char* P, char* Q)//((6+4)/2+7)/3-(1+2)*2)
{													  //1*2+3*((4-5)+6)/7
	NODE* p;										  //3*(2+6*2/3�1)�2*3/2+1
	char tmp;
	int j = 0;
	initStack(s);
	pushS(s, createNode('('));//Them ( vao stack
	showStack(s);
	for (int i = 0; i < strlen(P); i++)
	{
		p = createNode(P[i]);
		if (P[i] >= '0' && P[i] <= '9')//Neu P la toan hang
		{
			Q[j++] = P[i];
		}
		else
		{
			if (P[i] == '(')//Neu P la dau ( thi day vao stack
			{
				pushS(s, p);
				showStack(s);
			}
			else
			{
				if (P[i] == '^' || P[i] == '*' || P[i] == '/' || P[i] == '+' || P[i] == '-')//Neu P la toan tu 
				{
					while (checkPriority(P[i]) <= checkPriority(s.top->info) && s.top->info != '(')//Kiem tra do uu tien
					{
						Q[j++] = popS(s)->info;
					}
					pushS(s, p);
					showStack(s);
				}
				else
				{
					if (P[i] == ')')
					{
						while (s.top->info != '(')
						{
							Q[j++] = popS(s)->info;
							showStack(s);
						}
						popS(s);
						showStack(s);
					}
				}
			}
		}
	}
	while (s.top->info != '(')
	{
		Q[j++] = popS(s)->info;
		showStack(s);
	}
	showStack(s);
	Q[j] = '\0';
}
int calc(char op, int x, int y)
{
	switch (op)
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}
int calculateInfix(Stack s, char* Q)
{
	NODE* p;
	int x, y, result;
	initStack(s);
	for (int i = 0; i < strlen(Q); i++)
	{
		p = createNode(Q[i] - 48);
		if (Q[i] >= '0' && Q[i] <= '9')
		{
			pushS(s, p);
		}
		else
		{
			if (Q[i] == '^' || Q[i] == '*' || Q[i] == '/' || Q[i] == '+' || Q[i] == '-')
			{
				x = popS(s)->info;
				y = popS(s)->info;
				result = calc(Q[i], y, x);
				pushS(s, p = createNode(result));
			}
		}
	}
	return popS(s)->info;
}