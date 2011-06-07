#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h>


/*
exit��������
0�����ɹ���ɡ�   
1���ܴ���   
2ϵͳ�Ҳ���ָ�����ļ��� 
3ϵͳ�Ҳ���ָ����·����   
4ϵͳ�޷����ļ���   
5�ܾ����ʡ�   
6�����Ч��   
7�洢���ƿ鱻��
*/
void sa_handler(int num, siginfo_t * info, void *myact)
{ 
	//���յ�SIGCHLD
	int status; 
	int pid = waitpid(-1, &status, WNOHANG); 
	if (WIFEXITED(status)) { 
		printf("The child %d exit with code %d\n", pid, WEXITSTATUS(status)); 
	} 
} 

int main() 
{ 
	//�ӽ��̵�pid 
	int c_pid; 
	int pid; 
	struct sigaction act;
//	int sig;
//	sig = atoi(argv[1]);

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sa_handler;
	sigaction(SIGCHLD, &act, NULL);


#if 0
	signal(SIGCHLD, handler); 
#endif

	if ((pid = fork())) 
	{ 
		//������ 
		c_pid = pid; 
        int i;
		printf("The child process is %d\n", c_pid); 

		//�����̲��ȴ������Լ�������
		for (i = 0; i < 10; i++) 
		{ 
			printf("Do parent things.\n"); 
			sleep(1); 
		} 

		exit(0); 
	} 
	else 
	{ 
		//�ӽ��� 
		printf("I 'm a child.\n"); 
		sleep(2); 
		exit(2); 
	} 
}
