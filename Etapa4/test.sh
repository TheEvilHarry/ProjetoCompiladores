echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
./etapa4 <test.txt >output.txt
# valgrind ./etapa4 <test.txt
echo "Finished!"
make clean
