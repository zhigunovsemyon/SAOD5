#include "sortvec.h" //includes stdlib.h
#include <time.h> // time()
#include <stdio.h> // printf()
/*Задание: сделать упорядоченный набор элементов на массиве
Перечень операций:
	* получение элемента по индексу;
	принадлежность элемента вектору
	изменение элемента;
	арифметические операции над векторами: поэлементное
		сложение, вычитание, умножение, деление;
	операции определения нижней и верхней границ индекса;
	размер вектора;
	* инициализация вектора и его очистка;
	слияние векторов;
	//допы:
	* случайное заполнение структуры данных;
	заполнение из файла;
	сохранение структуры в файл;
*/

static void ConstFill(DATATYPE *const arr, size_t size, DATATYPE const val) {
	while (size--)
		arr[size] = val;//(DATATYPE)size;//rand();
}

static void LinearFill(DATATYPE *const arr, size_t size) {
	while (size--)
		arr[size] = (DATATYPE)size;//rand();
}

static void RandomiseArray(DATATYPE *const arr, size_t size) {
	while (size--)
		arr[size] = rand();
}

int main(void) {
	srand((unsigned int)time(NULL));
	SortedVec *vec = SortedVecInit();
	if (vec == NULL)
		return ERR_MALLOC;

	const size_t arrLen = 100;
	DATATYPE *arr = (DATATYPE *)calloc(sizeof(DATATYPE), arrLen);
	// RandomiseArray(arr, arrLen);
	// LinearFill(arr, arrLen);
	// ConstFill(arr, arrLen,1);
	SortedVecInsertArray(vec, arrLen, arr);

	free(arr);

	for (size_t i = 0; i < arrLen; i++)
		printf("[%03llu] = %d\n", i, SortedVecGet(vec, (long)i));

	SortedVecDeInit(&vec);
	return ERR_NO;
}
