#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>     
#include <time.h>  

using namespace std;

string binary(int u)
{
	string s;
	for (int i = 512; i > 0; i = i / 2)
		if (u & i) s = s + "T";
		else s = s + "F";
	return s;
}

int ten(string x)
{
	int j = 0;
	int i = 9;
	int a = 0;
	while (j!=10) {
		if (x[j] == 'T') {
			a = a + pow(2, i);
		}
		i--;
		j++;
	}
	return a;
}

int compare(string x, string y) {
	int c = 0;
	for (int i = 0; i < 10; i++) {
		if (x[i] == y[i])
			c++;
	}
	return c;
}

int main()
{
	srand(time(NULL));
/*	
	int t_ans = rand() % 999 + 1;
	cout << "Enter the N" << endl;
	int N;
	cin >> N;
	fout.open("C:/Users/User/Desktop/input.txt");
	fout << N << endl;
	int* array = new int[N];
	for (int i = 0; i < N; i++) {
		array[i] = rand() % 999 + 1;
		fout << binary(array[i]) << compare(binary(array[i]), binary(t_ans)) << endl;
	}
	fout.close();
*/
	ofstream fout;
	ifstream fin;
	fin.open("C:/Users/User/Desktop/input.txt");
	string st;
	string buf = "1111111111";
	string n2;
	fin >> n2;
	int N2 = atoi(n2.c_str());
	int* array2 = new int[N2];
	int j = 0;
	while (!fin.eof()) {
		fin >> st;
		for (int i = 0; i < 10; i++)
			buf[i] = st[i];
		array2[j] = ten(buf);
		j++;
	}
	fin.close();
	int ans = rand() % 999 + 1;
	for (int i = 0; i < N2; i++) {
		if (ans == array2[i]) {
			ans = rand() % 999 + 1;
			i = 0;
		}
	}
	fout.open("C:/Users/User/Desktop/output.txt");
	fout << "POSSIBLE SOLUTION" << endl;
	fout << binary(ans) << endl;
	fout.close();
	system("pause");
}
