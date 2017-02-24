int main(int argc, char *argv[])
{
    pid_t pid;
    pid=fork();
    if(pid==-1){
        perror("fork failure");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("pid in child=%d and parent=%d\n",getpid(),getppid()); 
    }
    else{
        printf("pid in parent=%d and childid=%d\n",getpid(),pid);
    }

    int status = -1;
    waitpid(pid, &status, WEXITED);

    printf("The child exited with return code %d\n", status);
    exit(EXIT_SUCCESS);
}
