#pragma once
#include <stdlib.h> /*size_t; free(); *alloc()*/

// Тип данных
#define DATATYPE double

/*Определение неполного типа данных*/
typedef struct _SortedVec SortedVec;

// Коды ошибок
enum ErrorCode {
	ERR_NO,	    // Без ошибок
	ERR_MALLOC, // Ошибка malloc
	ERR_NOSUCHELEMENT // Нет места под новый сегмент
};

// Создание вектора в памяти
SortedVec *SortedVecInit(void);

// Очистка памяти
void SortedVecDeInit(SortedVec **const ptr);

// Устанавливает элемент по адресу ptr равным элементу структруры по переданному индексу
enum ErrorCode SortedVecGet(SortedVec const *const, long index, DATATYPE *const ptr);

/*Вставка массива чисел Array размера ArrSize в вектор*/
enum ErrorCode SortedVecInsertArray(SortedVec *const, size_t const ArrSize,
			    DATATYPE const *const Array);

// Удаление элемента, равного Element
enum ErrorCode SortedVecRemoveElement(SortedVec *const, DATATYPE const Element);

// Геттер размера вектора
long SortedVecSize(SortedVec const *const this);

// Установка максимального элемента вектора по адресу ptr
enum ErrorCode SortedVecGetMax(SortedVec const *const this,
			       DATATYPE *const ptr);

// Установка минимального элемента вектора по адресу ptr
enum ErrorCode SortedVecGetMin(SortedVec const *const this,
			       DATATYPE *const ptr);

// Добавление в один вектор элементов из другого
enum ErrorCode SortedVecAddToThis(SortedVec *const this, SortedVec const *const other);

/*Проверка принадлежности элемента element вектору this.
1 -- принадлежит, 0 -- не принадлежит */
int SortedVecDoesBelong(SortedVec const *const this, DATATYPE const element);

// Прибавить к каждому элементу вектора offset
void SortedVecIncreaseEachElement(SortedVec *const this,
				  DATATYPE const offset);

// Умножить каждый элемент вектора на mult
void SortedVecMultiplyEachElement(SortedVec *const this,
				  DATATYPE const mult);

// Вычесть из каждого элемента вектора offset
inline void SortedVecDecreaseEachElement(SortedVec *const this,
					 DATATYPE const offset) {
	SortedVecIncreaseEachElement(this, (-1) * offset);
}

// Поделить каждый элемент вектора на div
void SortedVecDivideEachElement(SortedVec *const this,
					 DATATYPE const div) {
	SortedVecMultiplyEachElement(this, 1 / div);
}
