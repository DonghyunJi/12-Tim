#include<cstdio>
#include<iostream>

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

bool comparator(){}

SAR_logic(){}

int main(){

}


