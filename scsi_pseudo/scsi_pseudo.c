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
#include <scsi/scsi_dbg.h>


static int scsi_pseudo_sector_size = 512;
static int scsi_pseudo_dev_size_mb = 8;
static unsigned int scsi_pseudo_sectors;
static int scsi_pseudo_hosts = 1;


static char scsi_pseudo_proc_name[] = "scsi_pseudo";

static int scsi_pseudo_bus_match(struct device *dev,
    struct device_driver *driver);
static int scsi_pseudo_driver_probe(struct device *dev);
static int scsi_pseudo_driver_remove(struct device *dev);
static struct bus_type pseudo_bus = {
  .name = "pseudo",
  .match = scsi_pseudo_bus_match,
  .probe = scsi_pseudo_driver_probe,
  .remove = scsi_pseudo_driver_remove,
  //.drv_groups = sdebug_drv_groups,
};

static int scsi_pseudo_bus_match(struct device *dev,
    struct device_driver *driver)
{
  return 1;
}

static int scsi_pseudo_driver_probe(struct device *dev)
{
  return 1;
}

static int scsi_pseudo_driver_remove(struct device *dev)
{
  return 1;
}

static struct device_driver scsi_pseudo_driverfs = {
  .name = scsi_pseudo_proc_name,
  .bus = &pseudo_bus,
};

static int scsi_pseudo_add_adapter(void)
{
  return 0;
}

static void scsi_pseudo_remove_adapter(void)
{

}
static struct device *pseudo_primary;
static int __init scsi_pseudo_init(void)
{
  int k;
  pseudo_primary = root_device_register("pseudo_0");
  bus_register(&pseudo_bus);
  driver_register(&scsi_pseudo_driverfs);
  for (k = 0; k < scsi_pseudo_hosts; ++k) {
    scsi_pseudo_add_adapter();
  }

  pr_info("built in %d host(s)\n", scsi_pseudo_hosts);
  return 0;
}

static void __exit scsi_pseudo_exit(void)
{
  int k = 0;
  for (; k < scsi_pseudo_hosts; ++k) {
    scsi_pseudo_remove_adapter();
  }
  driver_unregister(&scsi_pseudo_driverfs);
  bus_unregister(&pseudo_bus);
  root_device_unregister(pseudo_primary);
  pr_info("exit scsi_pseudo\n");
}
module_init(scsi_pseudo_init);
module_exit(scsi_pseudo_exit);
MODULE_AUTHOR("Alex Feng");
MODULE_LICENSE("GPL");
