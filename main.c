#include <stdio.h>
#include <blockdev/lvm.h>

int main() {
    gboolean result = bd_lvm_check_deps();
    if(!result){
        printf("ERROR dependencies are not satisfied\n");
        return 1;
    }
    gboolean foo = bd_lvm_init();
    if(!foo) {
        printf("ERROR initialization did not finish\n");
        return 1;
    }

    // okie do shit now

    bd_lvm_close();
    return 0;
}
