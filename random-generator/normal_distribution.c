#include <float.h>
#include <math.h>
#include "random.h"

double normal_distribution(double mu, double sigma, rnd_state_t *rnd) {
	double u1, u2, z;
	do {
		u1 = rnd_fp64(rnd);
		u2 = rnd_fp64(rnd);
	} while (u1 <= DBL_MIN);
	z = sqrt(-2.0 * log(u1)) * cos(2*M_PI * u2);
	return z * sigma + mu;
}
