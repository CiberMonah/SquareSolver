@echo off
set SOURCE_FILES=Main.cpp SolveEquation.cpp Eqio.cpp Testing.cpp
set FLAGS=-Wall -Wfloat-equal -Wsign-conversion -Warray-bounds -Wdiv-by-zero -Werror 
g++ %FLAGS% %SOURCE_FILES% -o file.exe