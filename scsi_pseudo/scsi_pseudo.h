#define S_TEST_UNIT_READY  0x00
#define S_REWIND  0x01
#define S_REQUEST_SENSE  0x03
#define S_FORMAT  0x04
#define S_READ_BLOCK_LIMITS  0x05
#define S_REASSIGN_BLOCKS  0x07
#define S_INITIALIZE_ELEMENT_STATUS  0x07
#define S_READ_6  0x08
#define S_WRITE_6  0x0a
#define S_SEEK_6  0x0b
#define S_READ_REVERSE_6  0x0f
#define S_WRITE_FILEMARKS_6  0x10
#define S_SPACE_6  0x11
#define S_INQUIRY  0x12
#define S_VERIFY_6  0x13
#define S_RECOVER_BUFFERED_DATA  0x14
#define S_MODE_SELECT_6  0x15
#define S_RESERVE_6  0x16
#define S_RELEASE_6  0x17
#define S_COPY  0x18
#define S_ERASE_6  0x19
#define S_MODE_SENSE_6  0x1a
#define S_START_STOP_UNIT  0x1b
#define S_LOAD_UNLOAD  0x1b
#define S_RECEIVE_DIAGNOSTIC_RESULTS  0x1c
#define S_SEND_DIAGNOSTIC  0x1d
#define S_PREVENT_ALLOW_MEDIUM_REMOVAL  0x1e
#define S_READ_FORMAT_CAPACITIES  0x23
#define S_READ_CAPACITY_10  0x25
#define S_READ_10  0x28
#define S_READ_GENERATION  0x29
#define S_WRITE_10  0x2a
#define S_SEEK_10  0x2b
#define S_LOCATE_10  0x2b
#define S_ERASE_10  0x2c
#define S_READ_UPDATED_BLOCK  0x2d
#define S_WRITE_AND_VERIFY_10  0x2e
#define S_VERIFY_10  0x2f
#define S_SET_LIMITS_10  0x33
#define S_PRE_FETCH_10  0x34
#define S_READ_POSITION  0x34
#define S_SYNCHRONIZE_CACHE_10  0x35
#define S_LOCK_UNLOCK_CACHE_10  0x36
#define S_READ_DEFECT_DATA_10  0x37
#define S_INITIALIZE_ELEMENT_STATUS_WITH_RANGE  0x37
#define S_MEDIUM_SCAN  0x38
#define S_COMPARE  0x39
#define S_COPY_AND_VERIFY  0x3a
#define S_WRITE_BUFFER  0x3b
#define S_READ_BUFFER  0x3c
#define S_UPDATE_BLOCK  0x3d
#define S_READ_LONG_10  0x3e
#define S_WRITE_LONG_10  0x3f
#define S_CHANGE_DEFINITION  0x40
#define S_WRITE_SAME_10  0x41
#define S_UNMAP  0x42
#define S_READ_TOC_PMA_ATIP  0x43
#define S_REPORT_DENSITY_SUPPORT  0x44
#define S_PLAY_AUDIO_10  0x45
#define S_GET_CONFIGURATION  0x46
#define S_PLAY_AUDIO_MSF  0x47
#define S_SANITIZE  0x48
#define S_GET_EVENT_STATUS_NOTIFICATION  0x4a
#define S_PAUSE_RESUME  0x4b
#define S_LOG_SELECT  0x4c
#define S_LOG_SENSE  0x4d
#define S_XDWRITE_10  0x50
#define S_XPWRITE_10  0x51
#define S_READ_DISC_INFORMATION  0x51
#define S_XDREAD_10  0x52
#define S_XDWRITEREAD_10  0x53
#define S_SEND_OPC_INFORMATION  0x54
#define S_MODE_SELECT_10  0x55
#define S_RESERVE_10  0x56
#define S_RELEASE_10  0x57
#define S_REPAIR_TRACK  0x58
#define S_MODE_SENSE_10  0x5a
#define S_CLOSE_TRACK_SESSION  0x5b
#define S_READ_BUFFER_CAPACITY  0x5c
#define S_SEND_CUE_SHEET  0x5d
#define S_PERSISTENT_RESERVE_IN  0x5e
#define S_PERSISTENT_RESERVE_OUT  0x5f
#define S_EXTENDED_CDB  0x7e
#define S_VARIABLE_LENGTH_CDB  0x7f
#define S_XDWRITE_EXTENDED_16  0x80
#define S_WRITE_FILEMARKS_16  0x80
#define S_READ_REVERSE_16  0x81
#define S_THIRD_PARTY_COPY_OUT_COMMANDS  0x83
#define S_THIRD_PARTY_COPY_IN_COMMANDS  0x84
#define S_ATA_PASS_THROUGH_16  0x85
#define S_ACCESS_CONTROL_IN  0x86
#define S_ACCESS_CONTROL_OUT  0x87
#define S_READ_16  0x88
#define S_COMPARE_AND_WRITE  0x89
#define S_WRITE_16  0x8a
#define S_ORWRITE  0x8b
#define S_READ_ATTRIBUTE  0x8c
#define S_WRITE_ATTRIBUTE  0x8d
#define S_WRITE_AND_VERIFY_16  0x8e
#define S_VERIFY_16  0x8f
#define S_PRE_FETCH_16  0x90
#define S_SYNCHRONIZE_CACHE_16  0x91
#define S_SPACE_16  0x91
#define S_LOCK_UNLOCK_CACHE_16  0x92
#define S_LOCATE_16  0x92
#define S_WRITE_SAME_16  0x93
#define S_ERASE_16  0x93
#define S_SERVICE_ACTION_BIDIRECTIONAL  0x9d
#define S_SERVICE_ACTION_IN_16  0x9e
#define S_SERVICE_ACTION_OUT_16  0x9f
#define S_REPORT_LUNS  0xa0
#define S_ATA_PASS_THROUGH_12  0xa1
#define S_SECURITY_PROTOCOL_IN  0xa2
#define S_MAINTENANCE_IN  0xa3
#define S_MAINTENANCE_OUT  0xa4
#define S_REPORT_KEY  0xa4
#define S_MOVE_MEDIUM  0xa5
#define S_PLAY_AUDIO_12  0xa5
#define S_EXCHANGE_MEDIUM  0xa6
#define S_MOVE_MEDIUM_ATTACHED  0xa7
#define S_READ_12  0xa8
#define S_SERVICE_ACTION_OUT_12  0xa9
#define S_WRITE_12  0xaa
#define S_SERVICE_ACTION_IN_12  0xab
#define S_ERASE_12  0xac
#define S_READ_DVD_STRUCTURE  0xad
#define S_WRITE_AND_VERIFY_12  0xae
#define S_VERIFY_12  0xaf
#define S_SEARCH_DATA_HIGH_12  0xb0
#define S_SEARCH_DATA_EQUAL_12  0xb1
#define S_SEARCH_DATA_LOW_12  0xb2
#define S_SET_LIMITS_12  0xb3
#define S_READ_ELEMENT_STATUS_ATTACHED  0xb4
#define S_SECURITY_PROTOCOL_OUT  0xb5
#define S_SEND_VOLUME_TAG  0xb6
#define S_READ_DEFECT_DATA_12  0xb7
#define S_READ_ELEMENT_STATUS  0xb8
#define S_READ_CD_MSF  0xb9
#define S_REDUNDANCY_GROUP_IN  0xba
#define S_REDUNDANCY_GROUP_OUT  0xbb
#define S_SPARE_IN  0xbc
#define S_SPARE_OUT  0xbd
#define S_VOLUME_SET_IN  0xbe
#define S_VOLUME_SET_OUT  0xbf

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

struct sp_opcode_info_t {
  int (*pfp)(struct scsi_cmnd *, struct sp_dev_info *);
};

int s_test_unit_ready(struct scsi_cmnd *, struct sp_dev_info *);
int s_rewind(struct scsi_cmnd *, struct sp_dev_info *);
int s_request_sense(struct scsi_cmnd *, struct sp_dev_info *);
int s_format(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_block_limits(struct scsi_cmnd *, struct sp_dev_info *);
int s_reassign_blocks(struct scsi_cmnd *, struct sp_dev_info *);
int s_initialize_element_status(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_seek_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_reverse_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_filemarks_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_space_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_inquiry(struct scsi_cmnd *, struct sp_dev_info *);
int s_verify_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_recover_buffered_data(struct scsi_cmnd *, struct sp_dev_info *);
int s_mode_select_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_reserve_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_release_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_copy(struct scsi_cmnd *, struct sp_dev_info *);
int s_erase_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_mode_sense_6(struct scsi_cmnd *, struct sp_dev_info *);
int s_start_stop_unit(struct scsi_cmnd *, struct sp_dev_info *);
int s_load_unload(struct scsi_cmnd *, struct sp_dev_info *);
int s_receive_diagnostic_results(struct scsi_cmnd *, struct sp_dev_info *);
int s_send_diagnostic(struct scsi_cmnd *, struct sp_dev_info *);
int s_prevent_allow_medium_removal(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_format_capacities(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_capacity_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_generation(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_seek_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_locate_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_erase_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_updated_block(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_and_verify_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_verify_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_set_limits_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_pre_fetch_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_position(struct scsi_cmnd *, struct sp_dev_info *);
int s_synchronize_cache_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_lock_unlock_cache_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_defect_data_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_initialize_element_status_with_range(struct scsi_cmnd *, struct sp_dev_info *);
int s_medium_scan(struct scsi_cmnd *, struct sp_dev_info *);
int s_compare(struct scsi_cmnd *, struct sp_dev_info *);
int s_copy_and_verify(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_buffer(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_buffer(struct scsi_cmnd *, struct sp_dev_info *);
int s_update_block(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_long_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_long_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_change_definition(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_same_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_unmap(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_toc_pma_atip(struct scsi_cmnd *, struct sp_dev_info *);
int s_report_density_support(struct scsi_cmnd *, struct sp_dev_info *);
int s_play_audio_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_get_configuration(struct scsi_cmnd *, struct sp_dev_info *);
int s_play_audio_msf(struct scsi_cmnd *, struct sp_dev_info *);
int s_sanitize(struct scsi_cmnd *, struct sp_dev_info *);
int s_get_event_status_notification(struct scsi_cmnd *, struct sp_dev_info *);
int s_pause_resume(struct scsi_cmnd *, struct sp_dev_info *);
int s_log_select(struct scsi_cmnd *, struct sp_dev_info *);
int s_log_sense(struct scsi_cmnd *, struct sp_dev_info *);
int s_xdwrite_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_xpwrite_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_disc_information(struct scsi_cmnd *, struct sp_dev_info *);
int s_xdread_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_xdwriteread_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_send_opc_information(struct scsi_cmnd *, struct sp_dev_info *);
int s_mode_select_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_reserve_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_release_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_repair_track(struct scsi_cmnd *, struct sp_dev_info *);
int s_mode_sense_10(struct scsi_cmnd *, struct sp_dev_info *);
int s_close_track_session(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_buffer_capacity(struct scsi_cmnd *, struct sp_dev_info *);
int s_send_cue_sheet(struct scsi_cmnd *, struct sp_dev_info *);
int s_persistent_reserve_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_persistent_reserve_out(struct scsi_cmnd *, struct sp_dev_info *);
int s_extended_cdb(struct scsi_cmnd *, struct sp_dev_info *);
int s_variable_length_cdb(struct scsi_cmnd *, struct sp_dev_info *);
int s_xdwrite_extended_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_filemarks_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_reverse_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_third_party_copy_out_commands(struct scsi_cmnd *, struct sp_dev_info *);
int s_third_party_copy_in_commands(struct scsi_cmnd *, struct sp_dev_info *);
int s_ata_pass_through_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_access_control_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_access_control_out(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_compare_and_write(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_orwrite(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_attribute(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_attribute(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_and_verify_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_verify_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_pre_fetch_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_synchronize_cache_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_space_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_lock_unlock_cache_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_locate_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_same_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_erase_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_service_action_bidirectional(struct scsi_cmnd *, struct sp_dev_info *);
int s_service_action_in_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_service_action_out_16(struct scsi_cmnd *, struct sp_dev_info *);
int s_report_luns(struct scsi_cmnd *, struct sp_dev_info *);
int s_ata_pass_through_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_security_protocol_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_maintenance_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_maintenance_out(struct scsi_cmnd *, struct sp_dev_info *);
int s_report_key(struct scsi_cmnd *, struct sp_dev_info *);
int s_move_medium(struct scsi_cmnd *, struct sp_dev_info *);
int s_play_audio_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_exchange_medium(struct scsi_cmnd *, struct sp_dev_info *);
int s_move_medium_attached(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_service_action_out_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_service_action_in_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_erase_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_dvd_structure(struct scsi_cmnd *, struct sp_dev_info *);
int s_write_and_verify_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_verify_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_search_data_high_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_search_data_equal_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_search_data_low_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_set_limits_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_element_status_attached(struct scsi_cmnd *, struct sp_dev_info *);
int s_security_protocol_out(struct scsi_cmnd *, struct sp_dev_info *);
int s_send_volume_tag(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_defect_data_12(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_element_status(struct scsi_cmnd *, struct sp_dev_info *);
int s_read_cd_msf(struct scsi_cmnd *, struct sp_dev_info *);
int s_redundancy_group_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_redundancy_group_out(struct scsi_cmnd *, struct sp_dev_info *);
int s_spare_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_spare_out(struct scsi_cmnd *, struct sp_dev_info *);
int s_volume_set_in(struct scsi_cmnd *, struct sp_dev_info *);
int s_volume_set_out(struct scsi_cmnd *, struct sp_dev_info *);

struct sp_opcode_info_t *sp_get_opcode_info(u8 cmd);
