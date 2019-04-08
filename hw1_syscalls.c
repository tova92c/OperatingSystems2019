#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

int sys_sc_restrict(pid_t pid , int proc_restriction_level, scr* restrictions_list, int list_size){
	if(pid<0)
		return -ESRCH;
	task_t* tsk=find_task_by_pid(pid);
    if (tsk==NULL){
        return -ESRCH;
    }
	if(proc_restriciton_level<0 || proc_restriciton_level>2 || list_size<0)
		return -EINVAL;
	//memory error -ENOMEM

	//any other problem -EINVAL
	
	return 0;
}
int sys_set_proc_restriction(pid_t pid , int proc_restriciton_level){
	if(pid<0)
		return -ESRCH;
	task_t* tsk=find_task_by_pid(pid);
    if (tsk==NULL){
        return -ESRCH;
    }
	if(proc_restriciton_level<0 || proc_restriciton_level>2)
		return -EINVAL;

	//any other problem -EINVAL
	return 0;
}
int sys_get_process_log(pid_t pid, int size, fai* user_mem){
	if(pid<0)
		return -ESRCH;
	task_t* tsk=find_task_by_pid(pid);
    if (tsk==NULL){
        return -ESRCH;
    }
	//if size>actual number of recrods in the log -EINVAL
	if(size<0)
		return -EINVAL;
		//memory error -ENOMEM
	//any other problem -EINVAL

	return 0;
}	