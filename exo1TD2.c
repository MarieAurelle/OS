#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	int p = fork();
	int statuts;
	
	if(p == 0)
	{
		int pid = getpid();
		printf("pid du processus : %d \n", pid);
		int ppid = getppid();
		printf("pid du père du processus : %d \n", ppid);
		
		exit(pid%10);
	}
		
	printf("Processus fils : %d \n", p);
	wait(&statuts);
	
	if(WIFEXITED(statuts)) //pour voir que le processus fils s'est terminé correctement
		printf("Code retour : %d \n", WEXITSTATUS(statuts)); //retourne la valeur de code de retour, si on met juste statuts -> décallé
	else 
		printf("ERROR");	
}
