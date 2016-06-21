#include "util/ascii_convert.h"
#include "genos/serialization/hserial.h"
#include "string.h"

#include "debug/dprint.h"

unsigned int hserial_half(char* buf, int8_t& ref, uint8_t flag)
{
	if (flag == SER) *buf = hbyte2hex(ref & 0xF);
	else ref = hex2hbyte(*buf);
	return 1;
};

unsigned int hserial(char* buf, int8_t& ref, uint8_t flag)
{
	if (flag == SER) uint8_to_hex(buf,ref);
	else ref = hex_to_uint8(buf);
	return 2;
};

unsigned int hserial(char* buf, int16_t& ref, uint8_t flag)
{
	if (flag == SER) uint16_to_hex(buf,ref);
	else ref = hex_to_uint16(buf);
	return 4;
};

unsigned int hserial(char* buf, int32_t& ref, uint8_t flag)
{
	if (flag == SER) uint32_to_hex(buf,ref);
	else ref = hex_to_uint32(buf);
	return 8;
};

unsigned int hserial(char* buf, int64_t& ref, uint8_t flag)
{
	if (flag == SER) uint64_to_hex(buf,ref);
	else ref = hex_to_uint64(buf);
	return 16;
};

unsigned int hserial(char* buf, uint8_t& ref, uint8_t flag)
{
	if (flag == SER) uint8_to_hex(buf,ref);
	else ref = hex_to_uint8(buf);
	return 2;
};

unsigned int hserial(char* buf, uint16_t& ref, uint8_t flag)
{
	if (flag == SER) uint16_to_hex(buf,ref);
	else ref = hex_to_uint16(buf);
	return 4;
};

unsigned int hserial(char* buf, uint32_t& ref, uint8_t flag)
{
	if (flag == SER) uint32_to_hex(buf,ref);
	else ref = hex_to_uint32(buf);
	return 8;
};

unsigned int hserial(char* buf, uint64_t& ref, uint8_t flag)
{
	if (flag == SER) uint64_to_hex(buf,ref);
	else ref = hex_to_uint64(buf);
	return 16;
};