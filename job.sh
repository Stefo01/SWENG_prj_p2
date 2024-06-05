#!/bin/bash
#SBATCH --job-name=jobMPI
#SBATCH --time=10:00
#SBATCH --nodes=1
#SBATCH --ntasks=2
#SBATCH --partition=g100_all_serial


module load openmpi
export HWLOC_COMPONENTS=-gl
export TMPDIR=$HOME/tmp
mkdir -p $TMPDIR

mpirun -n 2 singularity exec matrix_multiplication.sif /opt/build/main  > output.txt 2> error.txt
