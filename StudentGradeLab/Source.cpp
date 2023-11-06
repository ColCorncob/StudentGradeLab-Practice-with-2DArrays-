#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string studentNames[5];
	double studentGrades[5][6];
	string headerNames[7] = { " ", "Grade 1", "Grade 2", "Grade 3", "Grade 4", "Grade 5", "Average" };

	int numberOfColumns = sizeof(studentGrades[0]) / sizeof(double);
	int numberOfRows = sizeof(studentGrades) / sizeof(studentGrades[0]);

	for (int a = 0; a < numberOfRows; a++)
	{
		cout << "Please enter the student's name...";
		getline(cin, studentNames[a]);
		studentGrades[a][5] = 0;

		for (int b = 0; b < numberOfColumns - 1; b++)
		{
			cout << "Please enter this student's grade #" << b + 1 << "...";
			cin >> (studentGrades[a][b]);
			studentGrades[a][5] += studentGrades[a][b];
		}
		studentGrades[a][5] = studentGrades[a][5] / 5;
		cin.ignore();
	}

	cout << endl;
	cout << left << setw(12) << headerNames[0] << "\t";
	for (int i = 1; i < 7; i++)
	{
		cout << left << setw(10) << headerNames[i];
	}
	cout << endl;

	for (int c = 0; c < numberOfRows; c++)
	{
		cout << left << setw(12) << studentNames[c] << "\t";
		for (int d = 0; d < numberOfColumns; d++)
		{
			cout << left << setw(10) << fixed << setprecision(2) << studentGrades[c][d];
		}
		cout << endl;
	}
}