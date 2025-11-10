#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main (){
	if(fork()>0){
		int sts;	//存储子进程退出状态
		pid_t pid =wait(&sts); //等待任意子进程退出
		cout<<"已终止的子进程编号是"<<pid<<endl;
		if(WIFEXITED(sts))	//检查是否正常退出
			{cout<<"子进程正常退出,退出状态是"<<WEXITSTATUS(sts)<<endl;}
		else{cout<<"子进程异常退出，终止它的信号是"<<WTERMSIG(sts)<<endl;}
}
	else{
		//子进程
		sleep(5);
		exit(0);	
		}
}
