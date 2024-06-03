#!/bin/bash
#SBATCH --job-name=run_matrix_mult
#SBATCH --ntasks=1
#SBATCH --time=10:00

singularity instance start matrix_multiplication.sif instance1
singularity run instance://instance1 > output.txt 2> error.txt
singularity instance stop instance1