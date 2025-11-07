#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main (){
	if(fork()>0){
		int sts;
		pid_t pid =wait(&sts);
		cout<<"已终止的子进程编号是"<<pid<<endl;
		if(WIFEXITED(sts)){cout<<"子进程正常退出,退出状态是"<<WEXITSTATUS(sts)<<endl;}
		else{cout<<"子进程异常退出，终止它的信号是"<<WTERMSIG(sts)<<endl;}
}
	else{
		//子进程
		sleep(30);
		exit(0);	
		}
}
