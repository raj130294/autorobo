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

#ifndef ALPHABETA_H
#define ALPHABETA_H

#include <iostream>

// allow only int, float and double types
template<class T> class PossibleType;
template<> class PossibleType<int> { };
template<> class PossibleType<float> { };
template<> class PossibleType<double> { };

template <class T>
class AlphaBeta : private PossibleType<T> {
public:	
	AlphaBeta(T alpha_, T beta_, T init_x=0.0, T init_v=0.0) {
		alpha = alpha_;
		beta = beta_;
		vk_1 = init_v;
		xk_1 = init_x;
	}
	
	void Process(T measurement, T delta_t); 
	
	T GetFilteredState() { return xk_1; }
	
	T GetDerivative() { return vk_1; }
	
private:
	// correction parameters
	float alpha;
	float beta;
	
	// model states
	float xk_1;
	float vk_1;
};

template <class T>
void AlphaBeta<T>::Process(T measurement, T delta_t) {
	// 1.project state estimates
	T xk = vk_1 * delta_t + xk_1;
	T vk = vk_1;
	
	// 2.compute residual
	T residual = measurement - xk;
	
	// 3.correct state estimates
	xk_1 = xk + alpha * residual;
	vk_1 = vk + beta / delta_t * residual;
}

#endif // ALPHABETA_H
