Компиляция программы с разными флагами оптимизации произведена командами

make OPT=-g NAME=matrix_g
make OPT=-O3 NAME=matrix_O3

Удаление файлов, полученных при компиляции 

make clean
Результаты измерений работы программы в файлах [result_g.txt](https://github.com/danidarya/MADE_hpc_2021/blob/main/homework02/matrix_multiplication/result_g.txt) и 
[result_O3.txt](https://github.com/danidarya/MADE_hpc_2021/blob/main/homework02/matrix_multiplication/result_O3.txt) соответственно. Видно, что флаг -О3 дает существенно ускорение скорости программы.

Результат теста LINPACK в файле [result_linpack.txt](https://github.com/danidarya/MADE_hpc_2021/blob/main/homework02/result_linpack.txt)
