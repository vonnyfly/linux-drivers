#!/bin/bash

cat raw.html | tr '[:lower:]' '[:upper:]' | sed 's/ /_/g' >x.tmp
sed -i 's/_(/_/g' x.tmp
sed -i 's/)//g' x.tmp
sed -i 's/(/_/g' x.tmp
sed -i 's/-/_/g' x.tmp
sed -i 's/\//_/g' x.tmp

echo "
#define pr_fmt(fmt) KBUILD_MODNAME \":%s: \" fmt, __func__

#include \"scsi_pseudo.h\"
" > scsi_pseudo_impl.c

awk '{printf "#define S_%s  0x%s\n", $2, tolower($1)}' x.tmp > scsi_pseudo.h
cp scsi_pseudo.h x.tmp

echo "
#include <linux/module.h>

#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/timer.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/genhd.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>
#include <linux/scatterlist.h>
#include <linux/blkdev.h>
#include <linux/crc-t10dif.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/atomic.h>
#include <linux/hrtimer.h>

#include <net/checksum.h>

#include <asm/unaligned.h>

#include <scsi/scsi.h>
#include <scsi/scsi_cmnd.h>
#include <scsi/scsi_device.h>
#include <scsi/scsi_host.h>
#include <scsi/scsicam.h>
#include <scsi/scsi_eh.h>
#include <scsi/scsi_tcq.h>
#include <scsi/scsi_dbg.h>" >> scsi_pseudo.h

echo -e "\nstruct sp_dev_info {
  struct list_head dev_list;
  struct sp_host_info *sp_host;
};

struct sp_host_info {
  struct list_head host_list;
  struct Scsi_Host *shost;
  struct device dev;
  struct list_head dev_info_list;
};

struct sp_opcode_info_t {
  int (*pfp)(struct scsi_cmnd *, struct sp_dev_info *);
};
" >> scsi_pseudo.h

cat x.tmp | awk '{print $2}' | while read i;do func=`echo $i | tr '[:upper:]' '[:lower:]'`;echo "int $func(struct scsi_cmnd *, struct sp_dev_info *);";done >> scsi_pseudo.h



echo "struct sp_opcode_info_t *sp_opcode_arr[256] = {">> scsi_pseudo_impl.c
cat x.tmp | awk '{print $2}' | while read i;do func=`echo $i | tr '[:upper:]' '[:lower:]'`;echo "  [$i] = {&$func},";done >> scsi_pseudo_impl.c

echo "};" >> scsi_pseudo_impl.c


cat x.tmp | awk '{print $2}' | while read i;do func=`echo $i | tr '[:upper:]' '[:lower:]'`;echo -e "int\n$func(struct scsi_cmnd *scp, struct sp_dev_info *sdp)\n{\n  pr_info(\"\\\\n\");\n  return 0;\n}\n";done >> scsi_pseudo_impl.c
echo "#define CMD(n) case n: pr_info(\"cmd: %s\n\", #n);return &sp_opcode_arr[n]">> scsi_pseudo_impl.c

echo "struct sp_opcode_info_t *sp_get_opcode_info(u8 cmd)
{
  switch(cmd) {
" >> scsi_pseudo_impl.c

# delete the same code.
awk '!a[$3]++' x.tmp | awk '{print $2}' | while read i;do echo -e "    CMD($i);\n";done >> scsi_pseudo_impl.c
echo "
    default: pr_info(\"Invalid cmd: 0x%2x\n\", cmd);return NULL;
  }
}
" >> scsi_pseudo_impl.c

echo -e "\nstruct sp_opcode_info_t *sp_get_opcode_info(u8 cmd);" >> scsi_pseudo.h
rm x.tmp
