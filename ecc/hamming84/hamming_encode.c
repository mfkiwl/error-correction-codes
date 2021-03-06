#include "bit-array.h"
#include "hamming-code.h"
#include "hamming_impl.h"

size_t hamming_encode(bits_t *dst, bits_t *src) {
	size_t ret = 0;
	bit a, b, c, d, x, y, z, p;
	while (bitarray_size(src) >= 4) {
		a = bitarray_next_front(src);
		b = bitarray_next_front(src);
		c = bitarray_next_front(src);
		d = bitarray_next_front(src);
		hamming84(a, b, c, d, &x, &y, &z, &p);
		bitarray_push_back(dst, a);
		bitarray_push_back(dst, b);
		bitarray_push_back(dst, c);
		bitarray_push_back(dst, d);
		bitarray_push_back(dst, x);
		bitarray_push_back(dst, y);
		bitarray_push_back(dst, z);
		bitarray_push_back(dst, p);
		++ret;
	}
	return ret;
}
