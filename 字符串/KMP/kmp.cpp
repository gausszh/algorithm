#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
using namespace std;
/**
*@param T{string} , 子串 
*/
void get_next(int* next, char* T, int length	){
	int i=0, j=-1;
	next[0] = -1;
	while(i < length-1){
		if(j == -1 || T[i] == T[j]){
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}	 
}
/**
 *返回子串T 在主串S中第pos个字符之后的位置。若不存在，则函数返回0
 *
 */
int index_kmp(char* S, char* T, int pos){
	int i = pos;
	int j = 0;
	int next[500];
	int len_S = strlen(S) , len_T = strlen(T) ;
	get_next(next, T, len_T);
	for(; i < len_S && j < len_T;){
		if(S[i] == T[j] || j == 0){
			i++;
			j++;
		} else {
			j = next[j];
		}
	} 
	if(j >= len_T){
		return i - len_T;
	} else {
		return 0;
	} 

} 
/*
 * 第一个参数主串， 然后是子串
 */
int main(int argc, char *argv[])
{
    //char S[100], T[100];
	//cin >> S;
	//cin >>T;
	printf("ret is %d\n", index_kmp(argv[1], argv[2], 0));
	return 0;
}
