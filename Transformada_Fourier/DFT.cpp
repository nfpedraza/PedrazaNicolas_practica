/* 
 * Discrete Fourier transform (C++)
 * by Project Nayuki, 2017. Public domain.
 * https://www.nayuki.io/page/how-to-implement-the-discrete-fourier-transform
 */

// Shared definitions
#include <cmath>
#include <vector>
using std::size_t;
using std::vector;


/* 
 * Computes the discrete Fourier transform (DFT) of the given complex vector.
 * All the array arguments must have the same length.
 */
#include <complex>
using namespace std;
using std::complex;
using std::exp;
vector<complex<double> > computeDft(const vector<complex<double> > &input) {
	vector<complex<double> > output;
	size_t n = input.size();
	for (size_t k = 0; k < n; k++) {  // For each output element
		complex<double> sum(0.0, 0.0);
		for (size_t t = 0; t < n; t++) {  // For each input element
			double angle = 2 * M_PI * t * k / n;
			sum += input[t] * exp(-angle);
		}
		output.push_back(sum);
	}
	return output;
}

int main(){
    cout<< computeDft()<<"\n";
    return 0;
}