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

int main() {}
