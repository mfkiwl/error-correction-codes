#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "bit-array.h"
#include "serial.h"
#include "serial_impl.h"

size_t serial_encode(bits_t *dst, bits_t *src, serial_cfg_t *cfg) {
	size_t ret = 0;
	uint8_t sum = 0;
	bit b;
	while (bitarray_size(src) >= (size_t) cfg->data_bits) {
		bitarray_push_back(dst, START_BIT);
		for (int i = 0; i < cfg->data_bits; ++i) {
			b = bitarray_next_front(src);
			bitarray_push_back(dst, b);
			sum += b;
		}
		if (cfg->parity_bit != PARITY_NONE) {
			bitarray_push_back(dst, parity(sum, cfg->parity_bit));
		}
		sum = 0;
		for (int i = 0; i < cfg->stop_bits; ++i) {
			bitarray_push_back(dst, STOP_BIT);
		}
		++ret;
	}
	return ret;
}
