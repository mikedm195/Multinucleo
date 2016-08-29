ALL: serial openmp bloque thread bloques_threads
.PHONY= clean

serial: serial.c
	gcc serial.c -o serial

openmp: openmp.c
	gcc openmp.c -o openmp -fopenmp

bloque: bloque.cu
	nvcc bloque.cu -o bloque

thread: thread.cu
	nvcc thread.cu -o thread

bloques_threads: bloques_threads.cu
	nvcc bloques_threads.cu -o bloques_threads

clean:
	\rm -f serial openmp bloque thread bloques_threads
