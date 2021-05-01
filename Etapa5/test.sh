echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
./etapa5 <test.txt >output.txt
# valgrind ./etapa5 <test.txt
echo "Finished!"
make clean
