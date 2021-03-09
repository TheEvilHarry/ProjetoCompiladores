echo "Cleaning..."
make clean
echo "Compiling..."
make
echo "Running test from test.txt and saving output to output.txt..."
./etapa3 <./test.txt >output.txt
echo "Finished!"
make clean
