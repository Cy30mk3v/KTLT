#include <stdio.h>
#include "Header.h"

bool isBmpFile(FILE *f)
{
	if (f == NULL)
		return false;

	BmpSignature signature;
	fseek(f, 0, 0L);
	fread(&signature, sizeof(BmpSignature), 1, f);

	return signature.data[0] == 'B' && signature.data[1] == 'M';
}