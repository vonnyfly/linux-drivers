TARGET:=scsi_pseudo
obj-m:=$(TARGET).o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
install:
	insmod $(TARGET).ko
rm:
	rmmod $(TARGET).ko
