/* AVR template generated by GLISS2 ($(date)) */

#define TARGET_ENDIANNESS $(TARGET_ENDIANNESS)
#define HOST_ENDIANNESS $(HOST_ENDIANNESS)

#define AVR_ORDER_BYTES_CISC \
	word = (buff[1] << 24) | (buff[0] << 16) | (buff[3] << 8) | buff[2];
