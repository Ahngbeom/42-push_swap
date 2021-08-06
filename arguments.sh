#!/bin/bash

TESTER=./minckim_push_swap_tester/random_numbers
COMMAND="pa|pb|sa|sb|ss|ra|rb|rr|rra|rrb|rrr"

ARG=$($TESTER $1 0)

clear
make all
echo "========================"
echo -e "\e[30;105mArguments : $ARG\e[0m"
echo "========================"

./push_swap $ARG
echo -ne "How many times use command? "
echo $(./push_swap $ARG | grep -woP $COMMAND | wc -l)
# ./push_swap $ARG | grep -P $COMMAND | wc -l
CHECKER=$(./push_swap $ARG | grep -woP $COMMAND | ./checker_linux $ARG)
# CHECKER=$(./push_swap $ARG | grep -oP $COMMAND | ./checker_Mac $ARG)
if [[ $CHECKER == "OK" ]]; then
    echo -ne "\e[30;103mChecker : \e[1;32m$CHECKER ✔️\e[0m\n"
else
    echo -ne "Checker : \e[1;31m$CHECKER\e[0m ❌\n"
fi
