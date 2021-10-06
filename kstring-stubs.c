#include "kstring.h"
#include <stdlib.h>
#include <string.h>

char kstrget(kstring str, size_t pos)
{
	if (pos > str.length || pos < 0) {
	abort();
	}
	return str.data[pos];

}

void kstrput(kstring str, size_t pos, char ch)
{
	if (pos > str.length || pos < 0) {
	abort();
	}
	str.data[pos] = ch;
}

size_t kstrlen(kstring str)
{
	str.length;
	return str.length;
}

kstring kstralloc(size_t nbytes)
{
	kstring result = { NULL, 0 };
	result.length = nbytes;
	result.data = malloc(nbytes);
	if(result.data == NULL){
	abort();
	}
	memset(result.data, 0, nbytes);
	
	return result;	
}

kstring kstrfrom(const char *cstr)
{
	kstring result = { NULL, 0 };
	
	result.length = strlen(cstr) + 1;
	result.data = malloc(strlen(cstr)+1);
	if(result.data == NULL) {
	abort();
	}
	memcpy(result.data, cstr, result.length);	
	return result;
}

void kstrfree(kstring str)
{
	free(str.data);
}

void kstrextend(kstring *strp, size_t nbytes)
{
	if (strp->length < nbytes){
	//strp->length = nybytes;
	char* temp = malloc(nbytes);
	if(temp == NULL)
	abort();
	memcpy(temp, strp->data, strp->length);
	free(strp->data);
	memset(temp + strp->length, 0, nbytes-strp->length);
	strp->data = temp;
	strp->length = nbytes;
	}	
	
	
}

void kstrcat(kstring *destp, kstring src)
{
	int org_length = destp->length;
	kstrextend(destp, destp->length + src.length);
	memcpy(destp->data + org_length, src.data, src.length);	
}
