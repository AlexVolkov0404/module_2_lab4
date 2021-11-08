// module_2_lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct PID {
	char A[256];
	char B[256];
};
int poshuk(char r1[256], char r2[256]) { //пошук номера входження підстановки в рядку
	int n1 = strlen(r1);
	int n2 = strlen(r2);
	int i = 0;
	bool b = false;
	while ((i <= (n1 - n2)) && (b == false)) {
		int j = 0;
		while ((j < n2) && (r1[i + j] == r2[j])) {
			j = j + 1;
		}
		if (j - 1 == n2 - 1) b = true;
		else i = i + 1;
	}
	int res;
	if (b) res = i;
	else res = -1;
	return res;
}
void zamina(char r1[256], char r2[256], char r3[256], int p) { //виконує заміну в підстановці 
	int n1 = strlen(r1);

	int n2 = strlen(r2);

	int n3 = strlen(r3);
	char r[256];
	strncpy_s(r, r1, p);
	strcat(r, r3);
	for (int i = p; i <= n1 + 1; i++) {
		r[i + n3] = r1[i + n2];
	}

	//cout << r<<endl;
	strcpy(r1, r);

}
int main()
{
	char s[256];
	cout << "vvedit ryadok: ";
	cin >> s;
	int k;
	cout << "vvedit kilkist pidstanovok: ";
	cin >> k;
	PID* ryadok = new PID[k + 1];


	for (int i = 1; i <= k; i++) {
		cout << "vvedit sho shukaemo: ";
		cin >> ryadok[i].A;
		cout << "vvedit sho zaminyaemo: ";
		cin >> ryadok[i].B;

	}
	char s1[256] = { 'a' };
	int i = 1;
	bool b;
	while ((strcmp(s, s1) != 0) || (i <= k)) {   //реалізація алгоритму Маркова
		strcpy_s(s1, s);
		if (poshuk(s, ryadok[i].A) > -1) {
			int m = poshuk(s, ryadok[i].A);
			zamina(s, ryadok[i].A, ryadok[i].B, m);
		}
		if (strcmp(s, s1) == 0) { i = i + 1; }
		else { i = 1; };
	}
	cout << s;
}

