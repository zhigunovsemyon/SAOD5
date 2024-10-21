#include "sortvec.h"
#include <stdlib.h> /*size_t; free(); *alloc()*/
#include <stdbool.h>

/*Сокрытая реализация типа данных*/
typedef struct _SortedVec {
	long max_size; // Максимальная вместимость набора
	long cur_size; // Текущий размер набора
	DATATYPE *data;
} SortedVec;

static bool SortedVecResize_(SortedVec *const this, long const newsize) {
	if (this->max_size > newsize)
		return true;

	DATATYPE *newdata = (DATATYPE *)realloc(this->data, newsize * sizeof(DATATYPE));
	if (newdata == NULL)
		return false;

	this->max_size = newsize;
	this->data = newdata;
	return true;
}

#define DEFAULT_SIZE 100 //Размер инита по умолчанию
SortedVec *SortedVecInit(void) {
	// Выделение памяти под дескриптор
	SortedVec *ptr = (SortedVec *)malloc(sizeof(SortedVec));	
	if (!ptr) // проверка памяти
		return NULL;
	// выделение памяти под данные
	ptr->data = (DATATYPE *)calloc(DEFAULT_SIZE, sizeof(DATATYPE));
	if (!ptr->data){ // проверка памяти
		free(ptr);
		return NULL;
	}
	// Задание максимального размера
	ptr->max_size = DEFAULT_SIZE;
	// Задание текущего нулевого размера
	ptr->cur_size = 0;
	
	// Возврат памяти
	return ptr;
}

// Очистка памяти
void SortedVecDeInit(SortedVec **ptr) {
	// Освобождение памяти
	free((*ptr)->data);
	free(*ptr);
	// Перестановка указателя на NULL
	*ptr = NULL;
}
