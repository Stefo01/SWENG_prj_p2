singularity instance start matrix_multiplication.sif instance1
singularity run instance://instance1 > output.txt 2> error.txt
singularity instance stop instance1