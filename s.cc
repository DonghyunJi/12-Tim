#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

class Output {
	public:
		queue<int>data;
		double input;
		int check;
};

double DAC(Output output) {
	queue<int>sample;
	int i, j;
	double x;
	double ref = 0;

	sample = output.data;

	for (i = 0; i < output.check + 1; i++) {
		x = 1;
		for (j = 0; j < i + 1; j++) x = x * 1 / 2;
		if (i != output.check) {
			ref = ref + 10 * x * sample.front();
			sample.pop();
		}
		else ref = ref + 10 * x;
	}
	cout << "Input Voltage : " << output.input << " V" << " / Reference Voltage : " << ref << " V" << endl;
	return ref;
}

bool Comparator(double a, double b) {
	return a >= b;
}

Output SAR_logic(Output output) {
	queue<int>sample;
	int i;

	output.data.push(Comparator(output.input, DAC(output)));
	output.check++;
	sample = output.data;
	cout << output.check << "'s cycle : ";
	for (i = 0; i < output.check; i++) {
		cout << sample.front() << " ";
		sample.pop();
	}
	cout << endl;
	return output;
}

int main() {
	double x;
	int i;

	Output output;

	cout << "Input Volatage(0V ~ 10V) : ";
	cin >> x;
	output.check = 0;
	output.input = x;

	while (output.check != 8) {
		cout << "Converting . . . " << endl;
		output = SAR_logic(output);
	}
	cout << "-----------------------Conversion Success-----------------------" << endl;
	cout << "    Analog input : " << output.input << " V -> Digital output : ";
	for (i = 0; i < output.check; i++) {
		cout << output.data.front() << " ";
		output.data.pop();
	}
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	return 0;
}
