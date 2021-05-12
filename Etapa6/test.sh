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
    if [ "$1" = "e5" ]; then
      for file in ./E5Tests/*; do
        test_file_name=${file}
        ./etapa6 <${test_file_name} >output.iloc
        echo "Running output code with ilocsim..."
        full_file_name="${test_file_name##*/}"
        file_name="${full_file_name%.*}"
        timeout 3 python3 ./ilocsim.py --stack=64000 --data=32000 -s -x <output.iloc >./E5TestResults/ilocsim_output${file_name}.txt
      done
    else
      for file in ./E6Tests/*; do
        test_file_name=${file}
        full_file_name="${test_file_name##*/}"
        file_name="${full_file_name%.*}"
        mkdir E6TestsCompiled
        ./etapa6 <${test_file_name} >./E6TestsCompiled/${file_name}.s
        gcc -m64 ./E6TestsCompiled/${file_name}.s -o ./E6TestsCompiled/${file_name}
        ./E6TestsCompiled/${file_name}
        echo $? >./E6TestResults/gcc_output${file_name}.txt
      done
    fi
  fi
fi
echo "Finished!"
make clean
