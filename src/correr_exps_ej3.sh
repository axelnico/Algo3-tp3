make clean
make


#Imprimir experimento1 del ejercicio 3


 # # #./tp3 3 -expRandom 100 a >../exp/entrada_exp1_ej3a.txt
 # # #./tp3 3 -exp 100 a <../exp/entrada_exp1_ej3a.txt >> ../exp/salida_exp1_ej3.data
 # # #./tp3 3 -exp 30 a <../exp/entrada_exp1.txt >> ../exp/../exp/salida_exp1_ej3.data
 # ./tp3 3 -exp 45 a <../exp/ej3/entrada_exp1_45input_gym_fijos.txt > ../exp/salida_exp1_ej3a.data
 # # #./tp3 3 -exp 16 a <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp1_ej3.data
 # # #./tp3 3 -expRandom 100 b >../exp/entrada_exp1_ej3.txt
 # # #./tp3 3 -exp 100 b <../exp/entrada_exp1_ej3a.txt >> ../exp/salida_exp1_ej3.data
 # # #./tp3 3 -exp 30 b <../exp/entrada_exp1.txt >> ../exp/salida_exp1_ej3.data
 # ./tp3 3 -exp 45 b <../exp/ej3/entrada_exp1_45input_gym_fijos.txt > ../exp/salida_exp1_ej3b.data
 # # #./tp3 3 -exp 16 b <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp1_ej3.data



# Imprimir experimento2 del ejercicio 3

 # ./tp3 1 -exp 30 <../exp/entrada_exp1.txt >> ../exp/salida_exp2_ej3
 # ./tp3 1 -exp 20 <../exp/entrada_exp4_20input_gym_fijos.txt >> ../exp/salida_exp2_ej3
 # ./tp3 1 -exp 16 <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp2_ej3

 # ./tp3 3 -exp 30 a <../exp/entrada_exp1.txt >> ../exp/salida_exp2_ej3
 # ./tp3 3 -exp 20 a <../exp/entrada_exp4_20input_gym_fijos.txt >> ../exp/salida_exp2_ej3
 # ./tp3 3 -exp 16 a <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp2_ej3


 # ./tp3 3 -exp 30 b <../exp/entrada_exp1.txt >> ../exp/salida_exp2_ej3
 # ./tp3 3 -exp 20 b <../exp/entrada_exp4_20input_gym_fijos.txt >> ../exp/salida_exp2_ej3
 # ./tp3 3 -exp 16 b <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp2_ej3




# Imprimir experimento2 del ejercicio3 como quiere keke


./tp3 1 -exp 16 <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp2_ej3.1

./tp3 3 -exp 16 a <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp2_ej3.1

./tp3 3 -exp 16 b <../exp/entrada_exp2_16input_con_sol.txt >> ../exp/salida_exp2_ej3.1