#include "sortvec.h" //includes stdlib.h
#include <time.h> // time()
#include <stdio.h> // printf()
/*Задание: сделать упорядоченный набор элементов на массиве
Перечень операций:
	получение элемента по индексу;
	принадлежность элемента вектору
	изменение элемента;
	арифметические операции над векторами: поэлементное
		сложение, вычитание, умножение, деление;
	операции определения нижней и верхней границ индекса;
	размер вектора;
	инициализация вектора и его очистка;
	слияние векторов;
	//
	случайное заполнение структуры данных;
	заполнение из файла;
	сохранение структуры в файл;
	необходимо уметь обосновать выбранные размеры переменных
		и временных буферов.
*/

void ConstFill(DATATYPE *arr, size_t size, DATATYPE val){
	while (size--)
		arr[size] = val;//(DATATYPE)size;//rand();
}

void LinearFill(DATATYPE *arr, size_t size){
	while (size--)
		arr[size] = (DATATYPE)size;//rand();
}

void RandomiseArray(DATATYPE *arr, size_t size){
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
		printf("[%03li] = %i\n", i, SortedVecGet(vec, (long)i));

	SortedVecDeInit(&vec);
	return ERR_NO;
}
