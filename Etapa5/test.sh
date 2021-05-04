echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
if [ "$1" = "debug" ]; then
  ./etapa5 <test.txt
  #valgrind ./etapa5 <test.txt
else
  ./etapa5 <test.txt >output.iloc
  echo "Running output code with ilocsim..."

fi
echo "Finished!"
make clean
