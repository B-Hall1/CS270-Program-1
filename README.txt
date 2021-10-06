Blair Hall		blair.hall@uky.edu		January 25, 2018
README.txt, Makefile, kstring.h, kstring-stubs.c, test-abbrev.c, test-full.c
Running Instructions: To compile type make, To run type ./test-abbrev or ./test-full,
Implementation Notes: I used malloc primarily to allocate memory, I also used memcpy and memset, to check for errors I check to see if malloc returned Null 
Limitations: When I first tested my program test case 14 and 16 failed because I had my if statement as if (pos > str.length || pos < 0) abort(); instead of if (pos >= str.length) abort();
References: I discussed my Program with my tutor Thomas Barber. He explainedto me how free, malloc, memset, and memcpy work. 
