/*
 Copyright (c) 2010 Mosalam Ebrahimi

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
*/

//TODO: add MSE computation in the filter class and for noisy measurements

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "alphabeta.h"
#include "simulator.h"

using namespace std;

int main(int argc, char **argv) {
	
	float alpha = 0.1;
	float beta = 0.01;
	
	if (argc == 3) {
		alpha = atof(argv[1]);
		beta = atof(argv[2]);
	}
	
	// assuming a good guess of initial state is known (6.0)
	// can set this to zero and see the behavior of difference filters
	AlphaBeta<float> filter(alpha, beta, 6.0);
	
	cout<<filter.GetDerivative()<<endl;

	Simulator sim;
	
	float delta_time;
	vector<float> noisy_vec;
	vector<float> real_vec;
	vector<float> filtered_vec;
	float noisy;
	float real;
	float filtered = 0;
	float time = 0.0f;
	
	ofstream data_file("data");
	
	for (; time<4.0f; time += delta_time) {
		sim.MeasureState(noisy, real);
		noisy_vec.push_back(noisy);
		real_vec.push_back(real);
		delta_time = sim.GetDeltaTime();

		filter.Process(noisy, delta_time);
		filtered = filter.GetFilteredState();
		filtered_vec.push_back(filtered);

		data_file<<time<<" "<<real<<" "<<noisy
			 <<" "<<filtered<<endl;
	}
	
	data_file.close();
	
	FILE* gnuplot = popen("gnuplot", "w");
/*	fprintf(gnuplot, "set terminal pdfcairo \n");
	fprintf(gnuplot, "set output \"plot.pdf\" \n");*/
	fprintf(gnuplot, "set terminal canvas mouse size 600,400 fsize 10 lw 1" \
			 "jsdir \"/usr/local/share/gnuplot/4.4/js\" \n");
	fprintf(gnuplot, "set output \"plot.html\" \n");
	
	fprintf(gnuplot, "plot 'data' using 1:2 title 'ground truth' with l,");
	fprintf(gnuplot, "'data' using 1:3 title 'noisy measurement' with l,");
	fprintf(gnuplot, "'data' using 1:4 title 'filtered measurement'" \
			 "with l \n");
	
	pclose(gnuplot);

	return 0;
}
