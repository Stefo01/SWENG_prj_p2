#!/bin/bash
#SBATCH --job-name=jobMPI
#SBATCH --time=10:00
#SBATCH --ntasks=2

export TMPDIR=$HOME/tmp
mkdir -p $TMPDIR

singularity run  matrix_multiplication.sif > output.txt 2> error.txt