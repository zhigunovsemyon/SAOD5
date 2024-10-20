#pragma once
#include <stdlib.h>

// Тип данных
#define DATAYPE int

typedef struct {
	size_t max_size; // Максимальная вместимость набора
	size_t cur_size; // Текущий размер набора
	DATAYPE *data;
} SortedVec;

// Коды ошибок
enum ErrorCodes {
	ERR_NO,	    // Без ошибок
	ERR_MALLOC, // Ошибка malloc
	ERR_SPACE   // Нет места под новый сегмент
};

// Создание вектора в памяти
SortedVec *SortedVecInit(size_t const max_size);

// Очистка памяти
void SortedVecDeInit(SortedVec **ptr);
