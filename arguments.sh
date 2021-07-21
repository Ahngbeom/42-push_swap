#!/bin/bash

TESTER=./push_swap_tester/random_numbers
COMMAND="pa|pb|sa|sb|ss|ra|rb|rra|rrb|rrr"

ARG=$($TESTER $1 0)

clear
make all
echo "========================"
echo -e "\e[30;105mArguments : $ARG\e[0m"
echo "========================"

./push_swap $ARG
echo -ne "How many times use command? "
echo $(./push_swap $ARG | grep -oP $COMMAND | wc -l)
# ./push_swap $ARG | grep -P $COMMAND | wc -l
CHECKER=$(./push_swap $ARG | grep -oP $COMMAND | ./checker_linux $ARG)
if [[ $CHECKER == "OK" ]]; then
    echo -ne "\e[30;103mChecker : \e[1;92m$CHECKER ✔️\e[0m\n"
else
    echo -ne "Checker : \e[1;31m$CHECKER\e[0m ❌\n"
fi



# echo -ne "Checker : " && ./push_swap $ARG | grep -P $COMMAND | ./checker_Mac $ARG