TARGET := my_scsi_pseudo
obj-m += $(TARGET).o
$(TARGET)-objs := ./scsi_pseudo_impl.o ./scsi_pseudo.o

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
