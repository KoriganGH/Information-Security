#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     
#include <time.h>  

using namespace std;

string binary(int u)
{
	string s;
	for (int i = 512; i > 0; i = i / 2)
		if (u & i) s = s+"T";
		else s = s + "F";
	return s;
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
	int t_ans = rand() % 999+1;
	cout << "Enter the N" << endl;
	int N;
	cin >> N;
	ofstream fout;
	fout.open("C:/Users/kiror/Desktop/input.txt");
	fout << N << endl;
	int* array = new int[N];
	for (int i = 0; i < N; i++) {
		array[i] = rand() % 999 + 1;
		fout << binary(array[i]) << compare(binary(array[i]), binary(t_ans)) << endl;
	}
	fout.close();
    int ans = rand() % 999 + 1;
	for (int i = 0; i < N; i++) {
		if (ans == array[i]) {
			ans = rand() % 999 + 1;
			i = 0;
		}
	}
	fout.open("C:/Users/kiror/Desktop/output.txt");
	fout << "POSSIBLE SOLUTION" << endl;
	fout << binary(ans) << endl;
	fout.close();
	/*
	int test = rand() % 999 + 1;
	while (srav(binary(test), binary(t_ans))!=10) {
		cout << binary(test) << srav(binary(test), binary(t_ans)) << endl;
		test = rand() % 999 + 1;
	}
	cout << endl;
	cout << "OMG True answer is - " << binary(test) << compare(binary(test), binary(t_ans)) << endl;
	*/
	system("pause");
}
