#!/bin/bash
#SBATCH --job-name=run_matrix_mult
#SBATCH --ntasks=1
#SBATCH --time=10:00
#SBATCH --output=output.txt
#SBATCH --error=error.txt

singularity instance start matrix_multiplication.sif instance1

singularity run instance://instance1

singularity instance stop instance1