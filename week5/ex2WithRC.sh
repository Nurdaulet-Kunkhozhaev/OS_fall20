echo 1 > ex2.txt

for i in {1..100}
do
  num=$(tail -1 ex2.txt)
  expr $num + 1 >> ex2.txt
done
# usually race condition appears instantly
# lines 5-6 form critical region because shared file ex2.txt is accessed there