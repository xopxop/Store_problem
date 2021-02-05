# Store_problem
Solution written in C:
  + Solution file: Solve_in_C/solution.c
  + How to run a test program:
    Requirement: gcc or clang and make. By default, the program is complied with clang. However, if you want to compile with gcc, go to Makefile file , comment line 1 and uncomment line2
    + make or make all: for run Makefile
    + make clean: delete object files
    + make fclean: delete object files and the test program
    the test program (my_program) take maximum 1 argument, if there is no argument, the default value for the 'batch size selection' parameter is 1 otherwise
    the program will take 1 or 0 in order to set the 'batch size selection' parameter
