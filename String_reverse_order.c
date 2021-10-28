//ÄæĞò×Ö·û´®ÄÚÈİ
#include <stdio.h>
fun(char* arr, int start, int end) {
	if (start < end) {
		fun(arr, start + 1, end - 1);
		char tem = arr[start];
		arr[start] = arr[end];
		arr[end] = tem;
	}
}
int main() {
	char a[] = { "abcde" };
	int len = strlen(a);
	fun(a, 0, len - 1);
	printf("%s ", a);
	return 0;
}