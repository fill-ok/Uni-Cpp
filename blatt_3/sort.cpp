#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include<iomanip>
using namespace std;

#define MAXLENGTH 50000

void swap(int num[], int i, int j) {
	int tmp = num[j];
	num[j]  = num[i];
	num[i]  = tmp;
}

void sort1(int num[], int start, int end) {
	int finished = 0, i;

	while(!finished) {
		finished = 1;
		for(i=start ; i<end ; i++) {
			if(num[i] > num[i+1]) {
				swap(num, i, i+1);
				finished = 0;
			}
		}
	}
}

void sort2(int num[], int start, int end) {
	int min, i;

	do {
		min = start;
		for(i=start+1; i<=end; i++) {
			if(num[i] < num[min])
				min = i;
		}
		swap(num, min, start);
		start++;
	}
	while(start < end);
}

void sum(int num1[], int num2[], int length, long int *erg) {
	int i;
	*erg = 0.0;

	for(i=0 ; i<length ; i++)
		*erg += num1[i] + num2[i];
}

void prod(int num1[], int num2[], int length, long int *erg) {
	*erg = num1[0] * num1[length/2] * num1[length-1];
	*erg += num2[0] * num2[length/2] * num2[length-1];
}

void out(int num[], int start, int end) {
	int i;
	for(i=start ; i<=end ; i++)
		cout << ("%d ", num[i]);
	cout << ("\n");
}

int main() {
	int i;
	int numbers1[MAXLENGTH];
	int numbers2[MAXLENGTH];
	int length;
	long int summe;
	long int erg;

	cout << ("Anzahl der Elemente: ");
	cin >> length;

	if(length<=0 || length>MAXLENGTH) {
		cout << "Fehler, Anzahl muss zwischen 1 und" << MAXLENGTH << "liegen!\n" << endl;
		return 1;
	}

	/* Mit Zufallszahlen zwischen 1 und length fuellen */
	srand(time(NULL));
	for(i=0 ; i<length ; i++) {
		numbers1[i] = rand() % length + 1;
		numbers2[i] = rand() % length + 1;
	}

	summe = 0;
	for(i=0 ; i<length ; i++)
		summe += numbers1[i];

	cout << ("\n");

	cout << ("Array 1 vor dem Sortieren: \n");
	out(numbers1,0,length-1);
	cout << ("Array 2 vor dem Sortieren: \n");
	out(numbers2,0,length-1);

	cout << "Der Mittelwert von Array 1 hat den Wert . \n" << (double)summe/length;
	cout << "\n";

	cout("Sortiere Array 1 mit %d Elementen mit Algorithmus 1...\n", length);
	sort1(numbers1,0,length-1);

	cout("Sortiere Array 2 mit %d Elementen mit Algorithmus 2...\n", length);
	sort2(numbers2,0,length-1);
	cout("\n");

	cout("Array 1 nach dem Sortieren: \n");
	out(numbers1,0,length-1);
	cout("Array 2 nach dem Sortieren: \n");
	out(numbers2,0,length-1);
	cout("\n");

	sum(numbers1, numbers2, length, &erg);
	cout("Ergebnis von sum: %ld\n", erg);

	prod(numbers1, numbers2, length, &erg);
	cout("Ergebnis von prod: %ld\n", erg);

	cout("\n");

	return 0;
}
