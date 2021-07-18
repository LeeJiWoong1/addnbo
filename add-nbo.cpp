#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t Ntohl(char* file)
{
	FILE* in = fopen(file, "rb");
	uint32_t buf;
	uint32_t a = fread(&buf, 1, sizeof(uint32_t), in);
	if (a != sizeof(uint32_t))
	{
		fprintf(stderr, "File size not %lu Byte!!\n", a);
		exit(-1);
	}
	buf = ntohl(buf);
	fclose(in);

	return buf;
}

int main(int argc, char* argv[]) {

	uint32_t n1, n2;
	uint32_t sum;
	n1 = Ntohl(argv[1]), n2 = Ntohl(argv[2]);
	sum = n1 + n2;
	printf("(%d) 0x%.4x + (%d) 0x%.4x = (%d) 0x%.4x\n", n1, n1, n2, n2, sum, sum);

	return 0;
}

