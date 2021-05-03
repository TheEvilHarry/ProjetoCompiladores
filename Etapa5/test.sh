echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
./etapa5 <test.txt >output.iloc
# valgrind ./etapa5 <test.txt
echo "Running output code with ilocsim..."
timeout 3 python3 ./ilocsim.py -s -x <output.iloc >ilocsim_output.txt
echo "Finished!"
make clean
