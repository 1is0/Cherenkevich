using System;

namespace LAB1
{
    class Program
    {
        static void vvod(ref int n)
        {
            while (!int.TryParse(Console.ReadLine(), out n))
            {
                Console.WriteLine("Ошибка ввода!Введите целое число");
            }
        }

        static void input(Matrix matr)
        {
            Console.WriteLine("Заполните матрицу:");
            string[] arr;
            for (int i = 0; i < matr.row; i++)
            {
                arr = Console.ReadLine().Split(' ');
                for (int j = 0; j < matr.colm; j++)
                {
                    if (!int.TryParse(arr[j], out matr.matrix[i, j]))
                    {
                        Console.WriteLine("В строке присуствует ненужный символ.Введите ее заново:");
                        i--; break;
                    }
                    matr.matrix[i, j] = Convert.ToInt32(arr[j]);
                }
            }
        }
        static void cout(Matrix matr)
        {
            for (int i = 0; i < matr.row; i++)
            {
                for (int j = 0; j < matr.colm; j++)
                {
                    Console.Write(matr.matrix[i, j]);
                    Console.Write('\t');
                }
                Console.WriteLine();
            }
        }

        static void kolvo(ref int nomber, int n)
        {
            bool a = false;
            while (a == false)
            {
                vvod(ref nomber);
                if (nomber <= 0 || nomber > n)
                {
                    Console.WriteLine("Ошибка при вводе номера.Повторите операцию,предварительно нажав любую клавушу.");
                    Console.ReadKey();
                }
                else a = true;
            }
        }

        static void Menu()
        {
            int strok = 0;
            int stolbsov = 0;
            Console.WriteLine("Введите кол-во матриц которое потребуется:");
            int n = 0;
            vvod(ref n);
            Matrix[] arr = new Matrix[n];
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("Введите кол-во строк и столбцов матрицы " + (i + 1));
                Console.WriteLine("Строк:");
                vvod(ref strok);
                Console.WriteLine("Столбцов:");
                vvod(ref stolbsov);
                arr[i] = new Matrix(strok, stolbsov);
            }
            while (true)
            {
                Console.Clear();
                Console.WriteLine("Выберите действие нажав соответствующую клавищу:");
                Console.WriteLine("1.Заполнить матрицу.");
                Console.WriteLine("2.Вывод матрицы.");
                Console.WriteLine("3.Найти сумму матриц a и b");
                Console.WriteLine("4.Найти определитель матрицы.");
                Console.WriteLine("5.Найти произведение матриц a и b");
                Console.WriteLine("9.Выход из программы");
                switch (Convert.ToString(Console.ReadLine()))
                {
                    case "1":
                        {

                            Console.WriteLine("Введите номер матрицы для ввода:");
                            int nomber = 0;
                            kolvo(ref nomber, n);
                            input(arr[nomber - 1]);
                            break;
                        }
                    case "2":
                        {
                            Console.WriteLine("Введите номер матрицы для вывода:");
                            int nomber = 0;
                            kolvo(ref nomber, n);
                            cout(arr[nomber - 1]);
                            Console.WriteLine("Нажмите любую клавишу для возврата в меню");
                            Console.ReadKey();
                            break;
                        }
                    case "3":
                        {
                            Console.WriteLine("Введите номера матриц для сложения:");
                            int nomber = 0;
                            int nom2 = 0;
                            kolvo(ref nomber, n);
                            kolvo(ref nom2, n);
                            if (arr[nomber - 1].colm == arr[nom2 - 1].colm && arr[nomber - 1].row == arr[nom2 - 1].row)
                            {
                                Matrix summa = new Matrix(arr[nom2 - 1].row, arr[nom2 - 1].colm);
                                summa.matrix = summa.Summa(arr[nom2 - 1], arr[nomber - 1]);
                                Console.WriteLine("Сумма матриц:");
                                cout(summa);
                                Console.WriteLine("Нажмите любую клавишу для возврата в меню");
                                Console.ReadKey();
                            }
                            else
                            {
                                Console.WriteLine("Данные матрицы несогласованные.Выберите другие.");
                                Console.WriteLine("Нажмите любую клавишу для возврата в меню");
                                Console.ReadKey();
                            }
                            break;
                        }
                    case "4":
                        {
                            Console.WriteLine("Введите номер матрицы:");
                            int nomber = 0;
                            kolvo(ref nomber, n);
                            Console.WriteLine("Определитель матрицы:");
                            Console.WriteLine(arr[nomber - 1].Det(arr[nomber - 1]));
                            Console.WriteLine("Нажмите любую клавишу для возврата в меню");
                            Console.ReadKey();
                            break;
                        }
                    case "5":
                        {
                            Console.WriteLine("Введите номера матриц для умножения:");
                            int nomber = 0;
                            int nom2 = 0;
                            kolvo(ref nomber, n);
                            kolvo(ref nom2, n);
                            if (arr[nomber - 1].colm != arr[nom2 - 1].row)
                            {
                                Console.WriteLine("Умножение невозможно.Кол-во столбцов первой матрицы не равно кол-ву столбцов второй");
                                Console.WriteLine("Нажмите любую клавишу для возврата в меню");
                                Console.ReadKey();
                                break;
                            }
                            Matrix Proizved = new Matrix(arr[nomber - 1].row, arr[nom2 - 1].colm);
                            Proizved.matrix = Proizved.Proizv(arr[nomber - 1], arr[nom2 - 1]);
                            cout(Proizved);
                            Console.WriteLine("Нажмите любую клавишу для возврата в меню");
                            Console.ReadKey();
                            break;
                        }
                    case "9": { return; }

                    default:
                        Console.WriteLine("Ошибка ввода.Повторите ввод:");
                        Console.ReadKey();
                        break;
                }
            }
        }

        static void Main(string[] args)
        {
            Menu();
        }
    }
}
