#include "sortvec.h"
#include <stdlib.h>  /*size_t; free(); *alloc()*/
#include <time.h> // time()
#include <stdio.h> // printf()
/*Задание: сделать упорядоченный набор элементов на массиве
Перечень операций:
	* получение элемента по индексу;
	* принадлежность элемента вектору
	изменение элемента; ?
	арифметические операции над векторами: поэлементное
		сложение, вычитание, умножение, деление;
	* операции определения нижней и верхней границ индекса; ?
	* размер вектора;
	* инициализация вектора и его очистка;
	* слияние векторов;
	//допы:
	* случайное заполнение структуры данных; ?
	заполнение из файла;
	сохранение структуры в файл;
*/

#ifdef WIN32
#define _maybe_unused_ /*Не поддерживается MSVC*/
#else 
#define _maybe_unused_ [[maybe_unused]] 
#endif /* ifdef WIN32 */

_maybe_unused_ static void ConstFill(DATATYPE *const arr, size_t size,
				     DATATYPE const val) {
	while (size--)
		arr[size] = val;//(DATATYPE)size;//rand();
}

_maybe_unused_ static void LinearFill(DATATYPE *const arr, size_t size) {
	while (size--)
		arr[size] = (DATATYPE)size;//rand();
}

_maybe_unused_ static void RandomiseArray(DATATYPE *const arr, size_t size) {
	while (size--)
		arr[size] = rand();
}

int main(void) {
	srand((unsigned int)time(NULL));
	SortedVec *vec = SortedVecInit();
	if (vec == NULL)
		return ERR_MALLOC;

	const size_t arrLen = 10;
	DATATYPE *arr = (DATATYPE *)calloc(sizeof(DATATYPE), arrLen);
	RandomiseArray(arr, arrLen);
	//LinearFill(arr, arrLen);
	ConstFill(arr, arrLen,1);
	SortedVecInsertArray(vec, arrLen, arr);

	free(arr);

	for (long i = 0; ; i++){
		DATATYPE cur;
		if(SortedVecGet(vec, i, &cur) == ERR_NOSUCHELEMENT)
			break;
		printf("[%03ld] = %lf\n", i, cur);
	}

	SortedVecRemoveElement(vec, 99);

	for (long i = 0; ; i++){
		DATATYPE cur;
		if(SortedVecGet(vec, i, &cur) == ERR_NOSUCHELEMENT)
			break;
		printf("[%03ld] = %lf\n", i, cur);
	}

	printf("counter = %d\n", SortedVecDoesBelong(vec, 2));

	SortedVecDeInit(&vec);
	return ERR_NO;
}
