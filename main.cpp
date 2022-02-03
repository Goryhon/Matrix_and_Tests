#include <iostream>
#include <windows.h>
#include <cmath>
#include <gtest/gtest.h>
#include "MatrixMath.h"
#include "MatrixFilePrint.h"
#include "MatrixConsolePrint.h"

namespace {//Вроде так привильно, но с мейном работаь не будет
	TEST(isSimpleTest, SimpleNumber) {
	EXPECT_TRUE(isSimple(2));
	EXPECT_TRUE(isSimple(3));
	EXPECT_TRUE(isSimple(5));
	EXPECT_TRUE(isSimple(7));
	EXPECT_TRUE(isSimple(2147483647));
}

	TEST(isSimpleTest, NonSimpleNumber) {
		EXPECT_FALSE(isSimple(0));
		EXPECT_FALSE(isSimple(1));
		EXPECT_FALSE(isSimple(4));
		EXPECT_FALSE(isSimple(6));
		EXPECT_FALSE(isSimple(2147483646));
	}

	TEST(TransposeTest, SimplTest) {
		int arr[M][M] = {
			{-12, -6, -6, -8, 3},
			{-8, -7, -6, 5, -3},
			{0, -7, 7, -9, -4},
			{-1, 10, -8, -15, -5},
			{6, -4, -2, -5, -3}};
		int answer[M][M] = {
			{-12, -8, 0, -1, 6},
			{-6, -7, -7, 10, -4},
			{-6, -6, 7, -8, -2},
			{-8, 5, -9, -15, -5},
			{3, -3, -4, -5, -3}};
		Transpose(arr);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				EXPECT_EQ(arr[i][j], answer[i][j]);
			}
		}
	}

	TEST(MatrixMul, GZero){
		int arr[M][M] = {
			{-12, -6, -6, -8, 3},
			{-8, -7, -6, 5, -3},
			{0, -7, 7, -9, -4},
			{-1, 10, -8, -15, -5},
			{6, -4, -2, -5, -3}};
		int mul = 2;
		int answer[M][M] = {
			{-24, -12, -12, -16, 6},
			{-16, -14, -12, 10, -6},
			{0, -14, 14, -18, -8},
			{-2, 20, -16, -30, -10},
			{12, -8, -4, -10, -6}};
		MatrixMul(arr, mul);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				EXPECT_EQ(arr[i][j], answer[i][j]);
			}
		}
	}

	TEST(MatrixMul, LZero){
		int arr[M][M] = {
			{-12, -6, -6, -8, 3},
			{-8, -7, -6, 5, -3},
			{0, -7, 7, -9, -4},
			{-1, 10, -8, -15, -5},
			{6, -4, -2, -5, -3}};
		int mul = -2;
		int answer[M][M] = {
			{24, 12, 12, 16, -6},
			{16, 14, 12, -10, 6},
			{0, 14, -14, 18, 8},
			{2, -20, 16, 30, 10},
			{-12, 8, 4, 10, 6}};
		MatrixMul(arr, mul);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				EXPECT_EQ(arr[i][j], answer[i][j]);
			}
		}
	}

	TEST(MatrixMul, Zero){
		int arr[M][M] = {
			{-12, -6, -6, -8, 3},
			{-8, -7, -6, 5, -3},
			{0, -7, 7, -9, -4},
			{-1, 10, -8, -15, -5},
			{6, -4, -2, -5, -3}};
		int mul = 0;
		int answer[M][M] = {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}};
		MatrixMul(arr, mul);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				EXPECT_EQ(arr[i][j], answer[i][j]);
			}
		}
	}

	TEST(MatrixAdd, SimpleTest){
		int arrA[M][M] = {
			{-12, -6, -6, -8, 3},
			{-8, -7, -6, 5, -3},
			{0, -7, 7, -9, -4},
			{-1, 10, -8, -15, -5},
			{6, -4, -2, -5, -3}};
		int arrB[M][M] = {
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 0},
			{0, -1, -2, -3, -4},
			{-5, -6, -7, -8, -9},
			{6, 4, 3, 2, 1}};
		int answer[M][M] = {
			{-11, -4, -3, -4, 8},
			{-2, 0, 2, 14, -3},
			{0, -8, 5, -12, -8},
			{-6, 4, -15, -23, -14},
			{12, 0, 1, -3, -2}};
		MatrixAdd(arrA, arrB);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				EXPECT_EQ(arrA[i][j], answer[i][j]);
			}
		}
	}
}

//using namespace std;
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//    int arr[M][M] = {
//            {-12, -6, -6, -8, 3},
//            {-8, -7, -6, 5, -3},
//            {0, -7, 7, -9, -4},
//            {-1, 10, -8, -15, -5},
//            {6, -4, -2, -5, -3},
//    };
//    int b[M][M];
//    int i, j, k = 0;
//    int n = 0;
//    int max = -99999, row, col;
//    double gmean = 1;
//
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < M; j++)
//        {
//            if (arr[i][j] > max)
//            {
//                max = arr[i][j];
//                row = i + 1;
//                col = j + 1;
//            }
//            if (arr[i][j] < 0)
//            {
//                k++;
//            }
//        }
//    }
//
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < M; j++)
//        {
//            if (((i + j) + 1 == M) && isSimple(arr[i][j]))
//            {
//                gmean *= arr[i][j];
//                n++;
//            }
//        }
//    }
//
//    cout << "Максимальный элемент: " << max << " Строка: " << row << " Столбец: " << col << endl;
//    cout << "Количество отрицательных элементов: " << k << endl;
//    cout << "Среднее геометрическое: " << pow(gmean, 1.0 / n) << endl;
//    cout << endl;
//    cout << "A = B * 3: " << endl;
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < M; j++)
//        {
//            b[i][j] = arr[i][j] * 3;
//            cout << b[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    Transpose(arr);
//    cout << "Транспонированная матрица: " << endl;
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < M; j++)
//            cout << arr[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
//    cout << "А = 3 * B + B^T: " << endl;
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < M; j++)
//        {
//            cout << b[i][j] + arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}



//
//TEST(MatrixMathTest, GetSumElemMatrix){
//int **TestMatrix = new int *[5];
//for (int i=0;i<5;i++)TestMatrix[i] = new int [5];
////test1
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = j;
//EXPECT_EQ(GetSumElemMatrix(TestMatrix,5),50);
////test2
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 0;
//EXPECT_EQ(GetSumElemMatrix(TestMatrix,5),0);
////test3
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 1;
//EXPECT_EQ(GetSumElemMatrix(TestMatrix,5),25);
//}
//
//TEST(MatrixMathTest, GetCountNechetElemsMatrix){
//int **TestMatrix = new int *[5];
//for (int i=0;i<5;i++)TestMatrix[i] = new int [5];
////test1
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = j;
//EXPECT_EQ(GetCountNechetElemsMatrix(TestMatrix,5),10);
////test2
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 0;
//EXPECT_EQ(GetCountNechetElemsMatrix(TestMatrix,5),0);
////test3
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 1;
//EXPECT_EQ(GetCountNechetElemsMatrix(TestMatrix,5),25);
//}
//
//TEST(MatrixMathTest, GetMinElemOnMainDiag){
//int **TestMatrix = new int *[5];
//for (int i=0;i<5;i++)TestMatrix[i] = new int [5];
////test1
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = j;
//EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),1);
////test2
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = -1;
//EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),-1);
////test3
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix[i][j] = 1;
//EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),1);
////test4
//for (int i=0;i<5;i++) for (int j=5;j>0;j--) TestMatrix[i][j] = j;
//EXPECT_EQ(GetMinElemOnMainDiag(TestMatrix,5),1);
//}
//
//TEST(MatrixMathTest, DiffMatrix){
//int **TestMatrix1 = new int *[5];
//int **TestMatrix2 = new int *[5];
//int **TestMatrixRes1 = new int *[5];//результат работы подпрограмм
//int **TestMatrixRes2 = new int *[5];//то, что должно быть
//
//for (int i=0;i<5;i++)TestMatrix1[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrix2[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrixRes1[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrixRes2[i] = new int [5];
//
////test1
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = j;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix2[i][j] = j;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = 0;
//
//TestMatrixRes1 = DiffMatrix(TestMatrix1,TestMatrix2,5);
//
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
//
////test2
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = i;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix2[i][j] = j;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = TestMatrix1[i][j] - TestMatrix2[i][j];
//
//TestMatrixRes1 = DiffMatrix(TestMatrix1,TestMatrix2,5);
//
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
//}
//
//TEST(MatrixMathTest, TranspMatrix){
//int **TestMatrix1 = new int *[5];
//int **TestMatrixRes1 = new int *[5];//результат работы подпрограмм
//int **TestMatrixRes2 = new int *[5];//то, что должно быть
//
//for (int i=0;i<5;i++)TestMatrix1[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrixRes1[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrixRes2[i] = new int [5];
//
////test1
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = j;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = TestMatrix1[j][i];
//
//TestMatrixRes1 = TranspMatrix(TestMatrix1,5);
//
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
//
////test2
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = i;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = TestMatrix1[j][i];
//
//TestMatrixRes1 = TranspMatrix(TestMatrix1,5);
//
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
//}
//
//TEST(MatrixMathTest, MultMatrix){
//int **TestMatrix1 = new int *[5];
//int **TestMatrix2 = new int *[5];
//int **TestMatrixRes1 = new int *[5];//результат работы подпрограмм
//int **TestMatrixRes2 = new int *[5];//то, что должно быть
//
//for (int i=0;i<5;i++)TestMatrix1[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrix2[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrixRes1[i] = new int [5];
//for (int i=0;i<5;i++)TestMatrixRes2[i] = new int [5];
//
////test1
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix1[i][j] = j;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrix2[i][j] = j;
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) TestMatrixRes2[i][j] = j*10;
//
//TestMatrixRes1 = MultMatrix(TestMatrix1,TestMatrix2,5);
//
//for (int i=0;i<5;i++) for (int j=0;j<5;j++) EXPECT_EQ(TestMatrixRes1[i][j],TestMatrixRes2[i][j]);
//}
