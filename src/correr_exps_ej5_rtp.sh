make clean
make

./tp3 1 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >../exp/salidaEj5/random_16_inputs.csv
./tp3 2 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv
./tp3 3 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv
./tp3 4 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv

./tp3 2 -exp 99 <../exp/entradaEj5/random_99_inputs.txt >>../exp/salidaEj5/random_99_inputs.csv
./tp3 3 -exp 99 <../exp/entradaEj5/random_99_inputs.txt >>../exp/salidaEj5/random_99_inputs.csv
./tp3 4 -exp 99 <../exp/entradaEj5/random_99_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv

