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

DAC(){}

bool comparator(double a, double b) {
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

int main(){

}

