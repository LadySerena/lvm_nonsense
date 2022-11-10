// Copyright (C) 2022  Serena Tiede
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//

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

    // list all pvs
    GError *err = NULL;

    GError *pvCreateErr = NULL;

    gboolean create = bd_lvm_pvcreate("/dev/loop6p2",0,0,NULL,&pvCreateErr);

    if(!create) {
        printf("ERROR pv creation failed: %s\n",pvCreateErr->message);
        return 1;
    }



    BDLVMPVdata *ret = g_new0(BDLVMPVdata, 1);

    BDLVMPVdata **data = &ret;


    data = bd_lvm_pvs(&err);

    g_assert((err != NULL)||err == NULL);
    if (err != NULL) {
        printf("ERROR listing physical volumes: %s\n", err->message);
        g_error_free(err);
    } else {
        printf("pv name is: %s\n", (*data)->pv_name);
        g_free(ret);
    }

    bd_lvm_close();
    return 0;
}
