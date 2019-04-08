#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <wait.h>
#include "hw1_syscalls.h"
#include <stdlib.h>

#define assertTest(expression)\
    do {\
        if (!(expression)) {\
            printf("Assertion failed at %s:%d: "\
                   "in function \"%s\" "\
                   "with assertion \"%s\".\n",\
                   __FILE__, __LINE__, __func__, (#expression));\
        }\
    } while (0)

#define assertFail(index, syscall, syscall_threshold, proc_restriction)\
    do {\
        assertTest(fail[(index)].syscall_num == (syscall));\
        assertTest(fail[(index)].syscall_restriction_threshold == (syscall_threshold));\
        assertTest(fail[(index)].proc_restriction_level == (proc_restriction));\
        assertTest(fail[(index)].time > 0);\
    } while (0)

static void resetProcess();

static void restrict_fail_pidNegative();

static void restrict_fail_procPrivNegative();

static void restrict_fail_procPrivGreaterThan2();

static void restrict_fail_scrlNull();

static void restrict_fail_sizeNegative();

static void restrict_fail_returnESRCHBeforeEINVAL();

static void restrict_success_simple();

static void restrict_success_overrideScrDifferentPriv();

static void restrict_success_overrideMoreScr();

static void restrict_success_overrideLessScr();

static void restrict_success_restrictForOther();

static void restrict_success_sonHasNoRestrictions();

static void exampleTest();

static void set_proc_restriction_fail_pidNegative();

static void set_proc_restriction_fail_procPrivNegative();

static void set_proc_restriction_fail_procPrivGreaterThan2();

static void set_proc_restriction_fail_returnESRCHBeforeEINVAL();

static void set_proc_restriction_success();

static void get_process_log_fail_pidNegative();

static void get_process_log_fail_sizeMoreThanLogHas_hasNoneRequest1();

static void get_process_log_fail_sizeMoreThanLogHas_has1Request2();

static void get_process_log_fail_sizeMoreThan100();

static void get_process_log_fail_sizeNegative();

static void get_process_log_fail_returnESRCHBeforeEINVAL();

static void get_process_log_success_simple();

static void get_process_log_success_moreThan100();

static void get_process_log_success_failSorted();

static void test_zombieRetainInfo();


int main() {

    scr scrl[] = {{13, 2}, // 13 = time.
                  {20, 1}, // 20 = getpid.
                  {64, 0}}; // 64 = getppid.

    assertTest(sc_restrict(getpid(), 1, scrl, 3) == 0);

    pid_t sonPid = fork();
    if (sonPid == 0) {
        assertTest(getpid() != -1);
        assertTest(getppid() != -1);
        assertTest(time(NULL) != -1);
        exit(0);
    } else {
        assertTest(getppid() != -1);
        assertTest(getpid() != -1);
 //       assertTest(time(NULL) == -1);
  //      assertTest(errno == ENOSYS);
    }

    resetProcess();
    // restrict_fail_pidNegative();
    // resetProcess();
    // restrict_fail_procPrivNegative();
    // resetProcess();
    // restrict_fail_procPrivGreaterThan2();
    // resetProcess();
    // restrict_fail_scrlNull();
    // resetProcess();
    // restrict_fail_sizeNegative();
    // resetProcess();
    // restrict_fail_returnESRCHBeforeEINVAL();
    // resetProcess();
    // restrict_success_simple();
    // resetProcess();
    // restrict_success_overrideScrDifferentPriv();
    // resetProcess();
    // restrict_success_overrideMoreScr();
    // resetProcess();
    // restrict_success_overrideLessScr();
    // resetProcess();
    // restrict_success_restrictForOther();
    // resetProcess();
    // exampleTest();
    // resetProcess();
    // set_proc_restriction_fail_pidNegative();
    // resetProcess();
    // set_proc_restriction_fail_procPrivNegative();
    // resetProcess();
    // set_proc_restriction_fail_procPrivGreaterThan2();
    // resetProcess();
    // set_proc_restriction_fail_returnESRCHBeforeEINVAL();
    // resetProcess();
    // set_proc_restriction_success();
    // resetProcess();
    // get_process_log_fail_pidNegative();
    // resetProcess();
    // get_process_log_fail_sizeMoreThanLogHas_hasNoneRequest1();
    // resetProcess();
    // get_process_log_fail_sizeMoreThanLogHas_has1Request2();
    // resetProcess();
    // get_process_log_fail_sizeMoreThan100();
    // resetProcess();
    // get_process_log_fail_sizeNegative();
    // resetProcess();
    // get_process_log_fail_returnESRCHBeforeEINVAL();
    // resetProcess();
    // get_process_log_success_simple();
    // resetProcess();
    // get_process_log_success_moreThan100();
    // resetProcess();
    // get_process_log_success_failSorted();
    // resetProcess();
    // test_zombieRetainInfo();
    printf("End.\n");
    return 0;
}

static void resetProcess() {
    pid_t pid = fork();
    if (pid != 0) {
        exit(0);
    }
}