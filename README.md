# Push swap

## Описание
Нужно создать программу для сортировки двух "стеков" за наименьшее кол-во операций. 

Only these moves are allowed:

* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). 
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). 
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

At the end, stack b must empty empty and all integers must be in stack a, sorted in ascending order. 

## Запуск программы

В папке программы в терминале напишите - make

Зупустите программу c аргументами для сортировки:
./push_swap 12 44 1 2323 33232 -111
В терминале появятся команды для сортировки.

./cheker 12 44 1 2323 33232 -111 
Далее впишите команды, и чекер даст ответ, отсортирован ли список. Можно вместе использовать с программой сортировки через пайп:
./push_swap 12 44 1 2323 33232 -111 | ./cheker 12 44 1 2323 33232 -111 
