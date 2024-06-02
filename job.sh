#!/bin/bash

IMAGE_NAME=matrix_multiplication.sif

STDOUT_FILE=output.txt
STDERR_FILE=error.txt

singularity build $IMAGE_NAME test1.def
singularity instance start $IMAGE_NAME instance1
singularity run instance://instance1 > $STDOUT_FILE 2> $STDERR_FILE
singularity instance stop instance1

# Rendo eseguibile with chmod +x job.sh
# scp -> come cp ma tramite ssh    user@... :percorso dove voglio metterlo