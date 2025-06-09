rm Identite_*
rm PI
rm *~
gcc Somme_darboux_pi.c -o PI -lm
gcc Identite.c -o Identite_C -lm
g++ Identite.cpp -o Identite_CPP -lm
gfortran -o Identite_F90 Identite.f90
./Identite_C
./Identite_CPP
./Identite_F90
./PI
python Identite.py
python moindre_carres.py
