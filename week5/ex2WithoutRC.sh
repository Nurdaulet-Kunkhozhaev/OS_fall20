echo 1 > ex2.txt

i=1
while [ $i -le 100 ]
do
  if ln ex2.txt ex2.lock
  then
    num=$(tail -1 ex2.txt)
    expr $num + 1 >> ex2.txt
    rm ex2.lock
    i=$((i+1))
  fi
done
# now we added locks so race condition doesn't happen
# lines 5-6 form critical region because shared file ex2.txt is accessed there