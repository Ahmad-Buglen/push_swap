#!/bin/bash

count=500

cycle=1

ok="OK"

for (( i=1; i <= cycle; i++ ))
do
numbers=$(./generator $count)
# echo "mas = $numbers"
instructions=$(./push_swap "$numbers")
# echo "instructions = $instructions"
rezult=$(./checker "$numbers" "$instructions")

size=$( echo "$instructions" | wc -w)
# if [["$rezult" = "$ok"]]
# then
echo "$count : $size : $rezult"
# fi
# echo "-KO-"
done







# echo "instructions = $instructions"





# echo "for $count numbers, $size operations and rezult $rezult"
