#pragma once

// Тип данных
#define DATAYPE int

/*Определение неполного типа данных*/
typedef struct _SortedVec SortedVec;

// Коды ошибок
enum ErrorCodes {
	ERR_NO,	    // Без ошибок
	ERR_MALLOC, // Ошибка malloc
	ERR_SPACE   // Нет места под новый сегмент
};

// Создание вектора в памяти
SortedVec *SortedVecInit(long const max_size);

// Очистка памяти
void SortedVecDeInit(SortedVec **ptr);
