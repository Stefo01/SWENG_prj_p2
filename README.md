## SE4HPCproject Part 2 -- Highlights of our work 

### Step 2.1

After using the repository template from https://github.com/SimoneReale/SE4HPC_project_part2, we moved on to implement the first step: **Automating the build, test and release processes**. We created a CI/CD pipeline that executes the building and testing processes whenever files are pushed or a pull request is made in the repository. You can find it under the 'Build' job in the 'test.yml' file.

### Step 2.2

**Containerizing the Application**:

Initially, we defined a Singularity image (building test1.def) containing only the dependencies, including the correct installation of MPI and CMake. Then, we created a second image (test2.def) where the repository files are copied, and the build process takes place within the container. This approach saved us time in creating images while we tested various Singularity commands locally. After completing the tests, we created the final file, matrix_multiplication.def, in which we included the mpirun execution within the container.

**NOTE**: In the secondtype branch, we also created another implementation of the matrix_multiplication.def file that generates an image allowing the container to be executed by launching it with mpirun from outside.

**Executing on the Cluster**:

For this step, we followed the instructions by transferring the container to the cluster using the scp command and verified its correct operation without errors on the cluster. We used the only Singularity image created locally, referencing the matrix_multiplication.def file.



## STEP 3 -- Automating Job Submission with Containerization

We extended GitHub Actions by using eWaterCycle/setup-singularity@v7 to install Singularity. We built the matrix_multiplication.def file to create the reference image, which we do not download as an artifact on GitHub to save space. Next, we downloaded and used sshpass to transfer the newly built container and job.sh. We then used another command to run job.sh, which executes the container on the cluster and returns the output.txt and error.txt files, which we download and make visible as artifacts in GitHub Actions.

**NOTE**: The build and singularity jobs are connected by a dependency. This ensures that if additional tests are to be performed, the container is only created and executed on the cluster if and only if the built tests are successfully completed. Otherwise, it doesn't make sense to create the container and run everything on the cluster.

