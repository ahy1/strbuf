

#include "strbuf.h"

#include <stdio.h>
#include <string.h>

int printit(const char *str)
{
	printf("[%s]\n", str);
	return 0;
}

int main()
{
	STRBUF *sb;
	size_t ix;

	sb=sballoc(10);

	printf("%ld\n", sbix(sb));
	sbcat(sb, "Test1");
	sbstop(sb);
	printf("%ld\n", sbix(sb));
	sbcat(sb, "Test2");
	printf("%ld\n", sbix(sb));
	sbcat(sb, "Ext2");
	sbstop(sb);
	printf("%ld\n", sbix(sb));

	sbforeach(sb, 0, printit);

	ix=sbsearch(sb, 0, strcmp, "Test2Ext2");
	if (ix!=(size_t)-1) printf("OK: [[%s]]\n", sbcstr(sb, ix));
	else printf("ERROR: Not found!\n");

	ix=sbsearch(sb, 0, strcmp, "TestX");
	if (ix!=(size_t)-1) printf("ERROR: [[%s]]\n", sbcstr(sb, ix));
	else printf("OK: Not found!\n");

	sbwritejson(sb, 0, (int (*)(const char *))printf);

	sbwritecsv(sb, 0, ';', '\"', (int (*)(const char *))printf);

	putchar('\n');

	return 0;
}


