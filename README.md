## SE4HPCproject Part 2 -- Highlights of our work 

### Step 2.1

After using the repository template from https://github.com/SimoneReale/SE4HPC_project_part2, we moved on to implementing the first step: **Automating the build, test and release processes**. We created a CI/CD pipeline that executes the building and testing processes whenever files are pushed or a pull request is made in the repository. You can find this under the 'Build' job in the 'test.yml' file.

### Step 2.2

**Containerizing the Application**:

Initially, we defined a Singularity image (building test1.def) containing only the dependencies, including the correct installation of MPI and CMake. Then, we created a second image (test2.def) where the repository files are copied, and the build process takes place within the container. This approach saved us time in creating images while we tested various Singularity commands locally. After completing the tests, we created the final file, container_matrix.def, in which we included the `mpirun` execution within the container.

**Executing on the Cluster**:

For this step, we followed the instructions by transferring the container to the cluster using the `scp` command and verified its correct operation without errors on the cluster. We used the only Singularity image created locally, referencing the container_matrix.def file.
We used the command `sbatch job.sh` to run the container. The export are used to remove some warnings which appeared in the error.txt, while every #SBATCH is used to set up the job for the cluster using slurm. The two commands regarding `TMPDIR` are used to change the folder used by MPI, due to the fact that the standard `TMPDIR` folder can be accessed in the cluster account only by the user or the creator of the job, which means that the container couldn't access it and returned an error of 'Permission Denied'. 

The error "No protocol defined" was solved using `export HWLOC_COMPONENTS=-gl` from https://github.com/open-mpi/ompi/issues/7701

The error "WARNING: There was an error initializing an OpenFabrics device." was solved using `export OMPI_MCA_btl=^vader,tcp,openib` from https://github.com/open-mpi/ompi/issues/10693

**Main and SecondType**

We left two branches in this repository because we wanted to leave both type of container we created. At first we did the one inside the main branch, where we built the container running `mpirun` as a runscript. While this method works, it's not really good for scalability, because in this way it's not possible to change the number of processor to run the `mpirun` exec. Moreover the matrices were needed inside the container, meaning that the executable inside the container could only run a multiplication for those two matrices. For a matrix multiplication kind of operation, we felt like it was not the way to go.

We than proceeded to write a different .def file in the new branch, which built the container installing openmpi and the exec, but not running anything. Then the job.sh would run the exec using `mpirun`. In this way the cluster would run mpi inside himself, and not using the one on the container, and also use the matrices inside the cluster, not the container. This way we potentially got more scalability, even though it was blocked in the main.cpp file, because we could use the number of nodes and processors defined inside the job.sh and not the container. And it's also a more useful type of container, for matrix multiplication, because we can give different matrices, not only the one inside the container.


## STEP 3 -- Automating Job Submission with Containerization

We extended GitHub Actions by using eWaterCycle/setup-singularity@v7 to install Singularity. We built the matrix_multiplication.def file to create the reference image, which we do not download as an artifact on GitHub to save space. Next, we downloaded and used `sshpass` to transfer the newly built container and job.sh. We then used another command to run job.sh, which executes the container on the cluster and returns the output.txt and error.txt files, which we download and make visible as artifacts in GitHub Actions.

**NOTE**: The build and Singularity jobs are connected by a dependency. This ensures that if additional tests are to be performed, the container is only created and executed on the cluster if and only if the built tests are successfully completed. Otherwise, it wouldn't make sense to create the container and run everything on the cluster.

