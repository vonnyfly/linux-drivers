#define pr_fmt(fmt) KBUILD_MODNAME ":%s: " fmt, __func__

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
static int scsi_pseudo_add_host = 0;
static int scsi_pseudo_num_tgts = 1;
static int scsi_pseudo_max_luns = 1;

#define MY_NAME "scsi_pseudo"

static char scsi_pseudo_proc_name[] = MY_NAME;
static LIST_HEAD(sp_host_list);

struct sp_dev_info {
  struct list_head dev_list;
  struct sp_host_info *sp_host;
};

struct sp_host_info {
  struct list_head host_list;
  struct Scsi_Host *shost;
  struct device dev;
  struct list_head dev_info_list;
};

static int scsi_pseudo_bus_match(struct device *dev,
    struct device_driver *driver);
static int scsi_pseudo_driver_probe(struct device *dev);
static int scsi_pseudo_driver_remove(struct device *dev);
static void scsi_pseudo_release_adapter(void);
static int scsi_pseudo_queuecommand(struct Scsi_Host *sshost,
    struct scsi_cmnd *cmnd);

static struct bus_type pseudo_bus = {
  .name = "myscsi",
  .match = scsi_pseudo_bus_match,
  .probe = scsi_pseudo_driver_probe,
  .remove = scsi_pseudo_driver_remove,
  //.drv_groups = sdebug_drv_groups,
};

static struct scsi_host_template sp_driver_template = {
  .proc_name =    MY_NAME,
  .name =     MY_NAME,
  .queuecommand =   scsi_pseudo_queuecommand,
  .can_queue =    10,
  .this_id =    7,
  .sg_tablesize =   SCSI_MAX_SG_CHAIN_SEGMENTS,
  .cmd_per_lun =    255,
  .max_sectors =    -1U,
  .use_clustering =   DISABLE_CLUSTERING,
  .module =   THIS_MODULE,
};



static int scsi_pseudo_bus_match(struct device *dev,
    struct device_driver *driver)
{
  //sdev_printk(KERN_INFO, dev, "%s\n", __func__);
  pr_info("\n");
  return 1;
}

static int scsi_pseudo_driver_probe(struct device *dev)
{
  struct sp_host_info *sp_host;
  struct Scsi_Host *sshost;

  pr_info("\n");
  sp_host = container_of(dev, struct sp_host_info, dev);
  sshost = scsi_host_alloc(&sp_driver_template, sizeof(sp_host));
  sp_host->shost = sshost;
  *((struct sp_host_info **)sshost->hostdata) = sp_host;

  scsi_add_host(sshost, dev);
  scsi_scan_host(sshost);
  return 0;
}

static int scsi_pseudo_driver_remove(struct device *dev)
{
  pr_info("\n");
  return 1;
}

static struct sp_dev_info *
scsi_pseudo_device_create(struct sp_host_info *sp_host, gfp_t flags)
{
  struct sp_dev_info *sp_dev;
  sp_dev = kzalloc(sizeof(*sp_dev), flags);
  sp_dev->sp_host = sp_host;
  list_add_tail(&sp_dev->dev_list, &sp_host->dev_info_list);
  return sp_dev;
}

///////////////////////////////////////////////////////////////////////
static struct device *pseudo_primary;

static struct device_driver scsi_pseudo_driverfs = {
  .name = scsi_pseudo_proc_name,
  .bus = &pseudo_bus,
};

static int scsi_pseudo_add_adapter(void)
{
  int k;
  struct sp_host_info *sp_host;

  sp_host = kzalloc(sizeof(*sp_host), GFP_KERNEL);
  INIT_LIST_HEAD(&sp_host->dev_info_list);

  for (k = 0; k < scsi_pseudo_num_tgts * scsi_pseudo_max_luns; ++k) {
    scsi_pseudo_device_create(sp_host, GFP_KERNEL);
  }
  list_add_tail(&sp_host->host_list, &sp_host_list);

  sp_host->dev.bus = &pseudo_bus;
  sp_host->dev.parent = pseudo_primary;
  sp_host->dev.release = &scsi_pseudo_release_adapter;
  dev_set_name(&sp_host->dev, "adapter%d", scsi_pseudo_add_host);
  /*
   * there trigger scsi_pseudo_match --> scsi_pseudo_probe
   */
  device_register(&sp_host->dev);
  pr_info("add adapter %d\n", scsi_pseudo_add_host);
  scsi_pseudo_add_host++;

  return 0;
}

static void scsi_pseudo_remove_adapter(void)
{

}
static void scsi_pseudo_release_adapter(void)
{

}


static int
scsi_pseudo_queuecommand(struct Scsi_Host *sshost, struct scsi_cmnd *cmnd)
{
  return 0;
}
////////////////////////////////////////////////////////////////
static int __init scsi_pseudo_init(void)
{
  int k;
  pseudo_primary = root_device_register("pseudo_scsi2");
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
  pr_info("exit\n");
}
module_init(scsi_pseudo_init);
module_exit(scsi_pseudo_exit);
MODULE_AUTHOR("Alex Feng");
MODULE_LICENSE("GPL");
