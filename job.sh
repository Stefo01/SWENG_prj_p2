#!/bin/bash
#SBATCH --job-name=jobMPI
#SBATCH --time=10:00
#SBATCH --ntasks=2
#SBATCH --partition=g100_all_serial

export OMPI_MCA_btl=^vader,tcp,openib
export HWLOC_COMPONENTS=-gl
export TMPDIR=$HOME/tmp
mkdir -p $TMPDIR

singularity run matrix_multiplication.sif > output.txt 2> error.txt