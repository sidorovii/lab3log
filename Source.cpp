#include <time.h>
#include <conio.h>
#include <list>
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

int** m1;
int** m2;

void mainly(void) {
	srand(time(NULL)); // ����������
	setlocale(LC_ALL, "Rus");
	int N;

	printf("������� ���������� ������ �����: ");
	scanf_s("%d", &N);
	int** m1;
	int** m2;
	m1 = new int* [N];
	for (int i = 0; i < N; i++) {
		m1[i] = new int[N];
	}
	m2 = new int* [N];
	for (int i = 0; i < N; i++) {
		m2[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = (1 + i); j < N; j++) {
			m1[i][j] = rand() % 2;
			m1[j][i] = m1[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		m1[i][i] = 0;
	}


	for (int i = 0; i < N; i++) { // ����� �������
		for (int j = 0; j < N; j++) {
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		m2[i][i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = (1 + i); j < N; j++) {
			m2[i][j] = rand() % 2;
			m2[j][i] = m2[i][j];
		}
	}

	for (int i = 0; i < N; i++) { // ����� �������
		for (int j = 0; j < N; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}
	_getch();
}

void zadanie1() {
	int N, N2;
	printf("������� ���������� ������ �����: ");
	scanf_s("%d", &N);

	int** m2;
	N2 = N;

	m2 = new int* [N+1];
	for (int i = 0; i < N+1; i++) {
		m2[i] = new int[N+1];
	}
	srand(time(NULL)); // ����������
	for (int i = 0; i < N2; i++) {
		for (int j = (1 + i); j < N2; j++) {
			m2[i][j] = rand() % 2;
			m2[j][i] = m2[i][j];
		}
	}
	for (int i = 0; i < N2; i++) { // ��������� ������� ���������
		m2[i][i] = 0;
	}

	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("\n");

	int kol1, kol2;
	printf("������� ������ ������ ��� �������������� (����� ������): ");
	scanf_s("%d %d", &kol1, &kol2);
	kol1--;
	kol2--;

	for (int i = 0; i < N2; i++) { // ��������������
		if (m2[kol2][i]) {
			m2[kol1][i] = 1;
			m2[i][kol1] = 1;
		}
	}
	//// ��������� ������� �������
	for (int i = 0; i < kol2; i++) {
		for (int j = kol2; j < (N2 - 1); j++) {
			m2[i][j] = m2[i][j + 1];
			m2[j][i] = m2[j + 1][i];
		}
	}
	for (int i = kol2; i < (N2 - 1); i++) {
		for (int j = kol2; j < (N2 - 1); j++) {
			m2[i][j] = m2[i + 1][j + 1];
		}
	}
	m2[kol1][kol1] = 1;
	N2--;
	////
	for (int i = 0; i < N2; i++) { // ����� �������
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}
	N2++;

	printf("\n");
	printf("\n");

	printf("������� ������ ������ ��� ���������� ����� (����� ������): ");
	scanf_s("%d %d", &kol1, &kol2);
	kol1--;
	kol2--;

	if (m2[kol1][kol2]) {
		for (int i = 0; i < N2; i++) { // ��������������
			if (m2[kol2][i]) {
				m2[kol1][i] = 1;
				m2[i][kol1] = 1;
			}
		}
		//// ��������� ������� �������
		for (int i = 0; i < kol2; i++) {
			for (int j = kol2; j < (N2 - 1); j++) {
				m2[i][j] = m2[i][j + 1];
				m2[j][i] = m2[j + 1][i];
			}
		}
		for (int i = kol2; i < (N2 - 1); i++) {
			for (int j = kol2; j < (N2 - 1); j++) {
				m2[i][j] = m2[i + 1][j + 1];
			}
		}
		m2[kol1][kol1] = 1;
		N2--;
		////
		for (int i = 0; i < N2; i++) { // ����� �������
			for (int j = 0; j < N2; j++) {
				printf("%d ", m2[i][j]);
			}
			printf("\n");
		}
		N2++;

		printf("\n");

		printf("������� ����� ������� ��� �����������: ");
		scanf_s("%d", &kol1);

		kol1--;
		int sum = 0;

		for (int i = 0; i < N2; i++) { // ������� ������� ������
			if (m2[kol1][i]) {
				sum++;
				kol2 = i;		// ������ ������ 1 ������� �������
			}
		}

		for (int i = 0; i < 11; i++) {
			m2[N2][i] = 0;
			m2[i][N2] = 0;
		}

		if (!sum) {
			m2[kol1][N2] = 1;
			m2[N2][kol1] = 1;
			m2[N2][N2] = 0;
		}
		else {
			if (sum == 1) {
				for (int i = 0; i < N2; i++) { // ����������� �������� 1 ������� � ������
					m2[N2][i] = m2[kol1][i];
					m2[i][N2] = m2[i][kol1];
				}
				m2[N2][kol1] = 1;		// ���������
				m2[kol1][N2] = 1;
				m2[N2][N2] = 0;
			}
			else {                 // �������� ����� �������
				m2[N2][kol2] = 1;  // � 10 ������� ��� ������� kol2
				m2[N2][kol1] = 1;  // �������� ����� � ������������ ��������
				m2[kol2][N2] = 1;  // � ������� kol2 ��� ������� 10	
				m2[kol1][N2] = 1;  // �������� ����� � ������������ ��������
				m2[kol1][kol2] = 0;// ������������ ����� � ����� �� ������ 
				m2[kol2][kol1] = 0;
				m2[N2][N2] = 0;
			}
		}
	}
	for (int i = 0; i < N2; i++) { // ����� �������
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}
	_getch();
}



void zadanie3() {
	int N1, N2;
	printf("������� ������� ������ (����� ������): ");
	scanf_s("%d %d", &N1, &N2);

	int** m1;
	int** m2;
	int** c;

	m1 = new int* [N1];
	for (int i = 0; i < N1; i++) {
		m1[i] = new int[N1];
	}
	m2 = new int* [N2];
	for (int i = 0; i < N2; i++) {
		m2[i] = new int[N2];
	}

	const unsigned int N = max(N1, N2);
	int minn = min(N1, N2);

	c = new int* [N];
	for (int i = 0; i < N; i++) {
		c[i] = new int[N];
	}


	srand(time(NULL)); // ����������
	for (int i = 0; i < N1; i++) {
		for (int j = (1 + i); j < N1; j++) {
			m1[i][j] = rand() % 2;
			m1[j][i] = m1[i][j];
		}
	}

	for (int i = 0; i < N1; i++) {
		m1[i][i] = 0;
	}


	for (int i = 0; i < N1; i++) { // ����� �������
		for (int j = 0; j < N1; j++) {
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	// ����������

	for (int i = 0; i < N2; i++) {
		for (int j = (1 + i); j < N2; j++) {
			m2[i][j] = rand() % 2;
			m2[j][i] = m2[i][j];
		}
	}

	for (int i = 0; i < N2; i++) {
		m2[i][i] = 0;
	}

	for (int i = 0; i < N2; i++) { // ����� �������
		for (int j = 0; j < N; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}


	printf("\n\n\n");

	printf("��������� �����������: ");
	printf("\n\n\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = 0;
		}
	}

	for (int i = 0; i < minn; i++) {
		for (int j = 0; j < minn; j++) {
			if (m1[i][j] || m2[i][j]) {
				c[i][j] = 1;
			}
			else {
				c[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) { // ����� �������
		for (int j = 0; j < N; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	_getch();
}


void zadanie4() {
	int N1, N2, N3;

	printf("������� ���������� ������ ���� ������: ");
	scanf_s("%d %d", &N1, &N2);
	int** a;
	int** b;
	int** c;
	a = new int* [N1];
	for (int i = 0; i < N1; i++) {
		a[i] = new int[N1];
	}
	b = new int* [N2];
	for (int i = 0; i < N2; i++) {
		b[i] = new int[N2];
	}
	N3 = N1 * N2;
	c = new int* [N3];
	for (int i = 0; i < N3; i++) {
		c[i] = new int[N3];
	}

	srand(time(NULL)); // ����������
	for (int i = 0; i < N1; i++) {
		for (int j = (1 + i); j < N1; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}

	for (int i = 0; i < N1; i++) {
		a[i][i] = 0;
	}

	for (int i = 0; i < N2; i++) {
		for (int j = (1 + i); j < N2; j++) {
			b[i][j] = rand() % 2;
			b[j][i] = b[i][j];
		}
	}

	for (int i = 0; i < N2; i++) {
		b[i][i] = 0;
	}

	int N;
	if (N1 > N2) {
		N = N1;
	}
	else {
		N = N2;
	}

	for (int i = 0; i < N3; i++) {
		for (int j = 0; j < N3; j++) {
			c[i][j] = 0;
		}
	}

	int x1, x2, y1, y2;
	for (int i = 0; i < N3; i++) {
		for (int j = 0; j < N3; j++) {
			x1 = i / N;
			x2 = i % N;
			y1 = j / N;
			y2 = j % N;

			if (x1 == y1) {
				if (b[x2][y2]) {
					c[i][j] = 1;
				}
			}
			else {
				if (x2 == y2) {
					if (a[x1][y1]) {
						c[i][j] = 1;
					}
				}
			}
		}
	}

	printf("��������� ������������: \n\n");

	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N1; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < N2; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("���������: ");
	printf("\n");
		for (int i = 0; i < N3; i++) {
			for (int j = 0; j < N3; j++) {
				if (c[i][j] == 0) {
					HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					printf("%d ", c[i][j]);
				}
				else {
					HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("%d ", c[i][j]);
				}
			}
			printf("\n");
		}

	_getch();
}

int Menu(void)
{
	system("CLS");
	int c = 0;
	setlocale(LC_ALL, "Rus");
	while (c < '0' || c > '4')
	{
		printf(
			"::=================================::\n"
			"|| 1 : ����������                  ||\n"
			"|| 2 : ������� 1                   ||\n"
			"|| 3 : ������� 3                   ||\n"
			"|| 4 : ������� 4                   ||\n"
			"|| 4 : �����                       ||\n"
			"::=================================::\n"
			"> ");
		c = _getch();
		system("cls");
	}
	return c;
}

void main(void)
{
	int Select;
	while ((Select = Menu()) != '0' && Select != 27)
		switch (Select)
		{
		case '1':
			mainly();
			break;
		case '2':
			zadanie1();
			break;
		case '3':
			zadanie3();
			break;
		case '4':
			zadanie4();
			break;
		}
}