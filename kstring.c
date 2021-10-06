#include "kstring.h"
#include <stdlib.h>
#include <string.h>

char kstrget(kstring str, size_t pos)
{	//if the pos is out of bounds abort
	if (pos >= str.length) {
	abort();
	}
	//return the str.data at the index
	return str.data[pos];

}

void kstrput(kstring str, size_t pos, char ch)
{	//if the pos is out of bounds abort
	if (pos >= str.length) {
	abort();
	}
	//return the str.data at the index
	str.data[pos] = ch;
}

size_t kstrlen(kstring str)
{	//return the length of the string
	return str.length;
}

kstring kstralloc(size_t nbytes)
{	//create a new kstring object
	kstring result = { NULL, 0 };
	//sets the length of the object equal to the nbytes
	result.length = nbytes;
	//sets the data ptr to the memory location
	result.data = malloc(nbytes);
	//if the data ptr points to NULL abort
	if(result.data == NULL){
	abort();
	}
	//initializes data to the NULL byte
	memset(result.data, 0, nbytes);
	//return the result(kstring object)
	return result;	
}

kstring kstrfrom(const char *cstr)
{	//create a new kstring object
	kstring result = { NULL, 0 };
	//sets the length of the object equal to the length of the cstr ptr + 1
	result.length = strlen(cstr) + 1;
	//sets the data ptr to the memory location
	result.data = malloc(strlen(cstr)+1);
	//if the data ptr points to NULL abort
	if(result.data == NULL) {
	abort();
	}
	//copies the cstr to the data ptr of result
	memcpy(result.data, cstr, result.length);
	//return the result(kstring object)	
	return result;
}

void kstrfree(kstring str)
{	//frees the memory location of the str.data
	free(str.data);
}

void kstrextend(kstring *strp, size_t nbytes)
{	//if the length of the strp is less than the nbytes
	if (strp->length < nbytes){
	//set the char ptr temp equal to the memory location
	char* temp = malloc(nbytes);
	//if the temp ptr points to NULL abort 
	if(temp == NULL)
	abort();
	//copies the data of the strp to the temp ptr
	memcpy(temp, strp->data, strp->length);
	//frees the location of the strp->data
	free(strp->data);
	//initializes the data to the NULL byte
	memset(temp + strp->length, 0, nbytes-strp->length);
	//sets the data of strp to temp
	strp->data = temp;
	//sets the length of strp to nbytes
	strp->length = nbytes;
	}	
	
	
}

void kstrcat(kstring *destp, kstring src)
{	//stores the original length of the destp ptr
	int org_length = destp->length;
	//calls kstextend with destp as the ptr and destp->length + src.length as the length instead of nbytes
	kstrextend(destp, destp->length + src.length);
	//copies the src data to the destp data + the org_length
	memcpy(destp->data + org_length, src.data, src.length);	
}
