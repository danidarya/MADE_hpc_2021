#!/bin/bash

my_array=(apple banana "Fruit Basket" orange 1 2 3 4 5 77)
len=${#my_array[@]}

for (( i=0; i<$len; i++ ))
  do
      echo ${my_array[$i]}
done
