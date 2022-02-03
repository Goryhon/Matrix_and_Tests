#ifndef UNTITLED1_MATRIXMATH_H
#define UNTITLED1_MATRIXMATH_H
#define M 5

bool isSimple(int N); //Функция проверки числа на простоту
void Transpose(int matrix[M][M]); //Функция транспонирования матрицы
void MatrixMul(int matrix[M][M], int mul); //Функция умножения матрицы на число
void MatrixAdd(int matrixA[M][M], int matrixB[M][M]); //Функция суммы матриц
#endif //UNTITLED1_MATRIXMATH_H
