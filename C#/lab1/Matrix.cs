using System;

namespace LAB1
{
    public class Matrix
    {
        public int row;
        public int colm;
        public int[,] matrix;


        public Matrix(int rows, int colms)
        {
            row = rows; colm = colms;
            matrix = new int[row, colms];
        }



        public int[,] Summa(Matrix c1, Matrix c2)
        {
            int[,] mass = new int[c1.row, c1.colm];
            for (int i = 0; i < c1.row; i++)
            {
                for (int j = 0; j < c1.colm; j++)
                {
                    mass[i, j] = c1.matrix[i, j] + c2.matrix[i, j];
                }
            }
            return mass;
        }


        public double Det(Matrix A)
        {
            double[,] copy = new double[A.row, A.colm];
            for (int i = 0; i < A.row; i++)
            {
                for (int j = 0; j < A.colm; j++)
                {
                    copy[i, j] = Convert.ToDouble(A.matrix[i, j]);
                }
            }
            for (int k = 1; k < A.row; k++)
            {
                for (int i = k; i < A.row; i++)
                {
                    double C = 1;
                    if (copy[k - 1, k - 1] != 0) { C = copy[i, k - 1] / copy[k - 1, k - 1]; }
                    for (int j = 0; j < A.row; j++)
                    {
                        copy[i, j] -= C * copy[k - 1, j];

                    }
                }
            }
            double det = 1;
            for (int i = 0; i < A.row; i++)
            {
                det *= copy[i, i];
            }
            return det;
        }


        public int[,] Proizv(Matrix c1, Matrix c2)
        {
            int[,] mass = new int[c1.row, c2.colm];
            for (int i = 0; i < c2.colm; i++)
            {
                for (int j = 0; j < c1.colm; j++)
                {
                    mass[i, j] = 0;
                    for (int k = 0; k < c1.colm; k++)
                    {
                        mass[i, j] += c1.matrix[i, k] * c2.matrix[k, j];
                    }
                }
            }
            return mass;
        }
    }
}