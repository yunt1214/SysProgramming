#include <sys/types.h> /* system.c */
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
int mysystem(const char *cmdstring) 
{
	pid_t pid; 
	int status;
	if (cmdstring == NULL) /* 명령어가 NULL인 경우 */ 
		return(1); 
	if ( (pid = fork()) < 0) {
		status = -1; /* 프로세스 생성 실패 */
	} else if (pid == 0) { /* 자식 프로세스 */
		execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
		_exit(127); /* execl 오류 */
	} else { /* 부모 프로세스 */
		while (waitpid(pid, &status, 0) < 0)
			if (errno != EINTR) {
				status = -1; /* waitpid()로부터 EINTR외의 오류 */
				break;
			}
	}
	return(status);
}
int main()
{
	int status;
	if ((status = mysystem("date")) < 0)
		perror("mysystem() 오류");
	printf("종료코드 %d\n", WEXITSTATUS(status));
	if ((status = mysystem("hello")) < 0)
		perror("mysystem() 오류");
	printf("종료코드 %d\n", WEXITSTATUS(status));
	if ((status = mysystem("who; exit 44")) < 0)
		perror("mysystem() 오류");
	printf("종료코드 %d\n", WEXITSTATUS(status));
}
