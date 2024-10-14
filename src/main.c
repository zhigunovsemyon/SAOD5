#include <stdio.h>
#include <stdlib.h>
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
#define DATAYPE int

typedef struct {
	size_t max_size;//Максимальная вместимость набора
	size_t cur_size;//Текущий размер набора
	DATAYPE *data;
} SortedVec;

SortedVec* SortedVecInit(size_t const max_size) {
	SortedVec* ptr = (SortedVec *)malloc(sizeof(SortedVec) + sizeof(DATAYPE) * max_size);
	if (!ptr)
		return NULL;
	ptr->max_size = max_size;
	ptr->cur_size = 0;
	ptr->data = (DATAYPE *)(ptr + 1);
	return ptr;
}

void SortedVecDeInit(SortedVec **ptr){
	free(*ptr);
	*ptr = NULL;
}

int main(void) {
	SortedVec* vec = SortedVecInit(100);
	SortedVecDeInit(&vec);
	return EXIT_SUCCESS;
}
