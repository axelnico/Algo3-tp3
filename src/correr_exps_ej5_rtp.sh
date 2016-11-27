make clean
make
echo "corriendo ej1.."
./tp3 1 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >../exp/salidaEj5/random_16_inputs.csv
echo "corriendo ej2.."
./tp3 2 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv
echo "corriendo ej3.."
./tp3 3 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv
echo "corriendo ej4.."
./tp3 4 -exp 16 <../exp/entradaEj5/random_16_inputs.txt >>../exp/salidaEj5/random_16_inputs.csv


echo "corriendo ej2 con 99 instancias.."
./tp3 2 -exp 99 <../exp/entradaEj5/random_99_inputs.txt >>../exp/salidaEj5/random_99_inputs.csv
echo "corriendo ej3 con 99 instancias.."
./tp3 3 -exp 99 <../exp/entradaEj5/random_99_inputs.txt >>../exp/salidaEj5/random_99_inputs.csv
echo "corriendo ej4 con 99 instancias.."
./tp3 4 -exp 99 <../exp/entradaEj5/random_99_inputs.txt >>../exp/salidaEj5/random_99_inputs.csv