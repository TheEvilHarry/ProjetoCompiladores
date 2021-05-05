echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
if [ "$1" = "debug" ]; then
  ./etapa5 <test.txt
else
  if [ "$1" = "valgrind" ]; then
    valgrind ./etapa5 <test.txt
  else
    ./etapa5 <test.txt >output.iloc
    echo "Running output code with ilocsim..."
    timeout 3 python3 ./ilocsim.py -s -x <output.iloc >ilocsim_output.txt
  fi
fi
echo "Finished!"
make clean