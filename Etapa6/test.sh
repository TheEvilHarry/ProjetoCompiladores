echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
if [ "$1" = "debug" ]; then
  ./etapa6 <test.txt
else
  if [ "$1" = "valgrind" ]; then
    valgrind ./etapa6 <test.txt
  else
    for file in ./tests/*; do
      test_file_name=${file}
      ./etapa6 <${test_file_name} >output.iloc
      echo "Running output code with ilocsim..."
      full_file_name="${test_file_name##*/}"
      file_name="${full_file_name%.*}"
      timeout 3 python3 ./ilocsim.py --stack=64000 --data=32000 -s -x <output.iloc >./test_results/ilocsim_output${file_name}.txt
      # cat ./test_results/ilocsim_output${file_name}.txt |
      #   awk ’/ memory value/,0’ |
      #   grep -v memory |
      #   awk ’{print $1 "|" $2}’
    done
  fi
fi
echo "Finished!"
make clean
