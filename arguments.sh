#!/bin/bash

TESTER=./minckim_push_swap_tester/random_numbers
COMMAND="pa|pb|sa|sb|ss|ra|rb|rr|rra|rrb|rrr"

ARG=$($TESTER $1 0)

clear
make all

echo 
echo -e "Arguments : \e[30;105m $ARG\e[0m"
echo 

./push_swap $ARG | grep -n ""

echo -ne "\e[46;30mHow many times use command? "
echo -ne $(./push_swap $ARG | grep -woP $COMMAND | wc -l)
echo -e "\e[0m"

## Linux
CHECKER=$(./push_swap $ARG | grep -woP $COMMAND | ./checker_linux $ARG)

## Mac
# CHECKER=$(./push_swap $ARG | grep -oP $COMMAND | ./checker_Mac $ARG)

if [[ $CHECKER == "OK" ]]; then
    echo -ne "\e[30;103mChecker : \e[1;32m$CHECKER ✔️\e[0m\t"
    echo -e "\e[95m\e[5mCongratulation !!! \e[25m\e[0m"
else
    echo -ne "Checker : \e[1;31m$CHECKER\e[0m ❌\n"
fi

## Linux - valgrind
echo -e "\e[97;100m💣 Memory Leak Check"
MEMLEAK_CHECK=$(valgrind --leak-check=full ./push_swap $ARG)
echo -e "\e[0m"