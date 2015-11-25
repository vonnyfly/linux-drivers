
#define pr_fmt(fmt) KBUILD_MODNAME ":%s: " fmt, __func__

#include "scsi_pseudo.h"

struct sp_opcode_info_t *sp_opcode_arr[256] = {
  [S_TEST_UNIT_READY] = {&s_test_unit_ready},
  [S_REWIND] = {&s_rewind},
  [S_REQUEST_SENSE] = {&s_request_sense},
  [S_FORMAT] = {&s_format},
  [S_READ_BLOCK_LIMITS] = {&s_read_block_limits},
  [S_REASSIGN_BLOCKS] = {&s_reassign_blocks},
  [S_INITIALIZE_ELEMENT_STATUS] = {&s_initialize_element_status},
  [S_READ_6] = {&s_read_6},
  [S_WRITE_6] = {&s_write_6},
  [S_SEEK_6] = {&s_seek_6},
  [S_READ_REVERSE_6] = {&s_read_reverse_6},
  [S_WRITE_FILEMARKS_6] = {&s_write_filemarks_6},
  [S_SPACE_6] = {&s_space_6},
  [S_INQUIRY] = {&s_inquiry},
  [S_VERIFY_6] = {&s_verify_6},
  [S_RECOVER_BUFFERED_DATA] = {&s_recover_buffered_data},
  [S_MODE_SELECT_6] = {&s_mode_select_6},
  [S_RESERVE_6] = {&s_reserve_6},
  [S_RELEASE_6] = {&s_release_6},
  [S_COPY] = {&s_copy},
  [S_ERASE_6] = {&s_erase_6},
  [S_MODE_SENSE_6] = {&s_mode_sense_6},
  [S_START_STOP_UNIT] = {&s_start_stop_unit},
  [S_LOAD_UNLOAD] = {&s_load_unload},
  [S_RECEIVE_DIAGNOSTIC_RESULTS] = {&s_receive_diagnostic_results},
  [S_SEND_DIAGNOSTIC] = {&s_send_diagnostic},
  [S_PREVENT_ALLOW_MEDIUM_REMOVAL] = {&s_prevent_allow_medium_removal},
  [S_READ_FORMAT_CAPACITIES] = {&s_read_format_capacities},
  [S_READ_CAPACITY_10] = {&s_read_capacity_10},
  [S_READ_10] = {&s_read_10},
  [S_READ_GENERATION] = {&s_read_generation},
  [S_WRITE_10] = {&s_write_10},
  [S_SEEK_10] = {&s_seek_10},
  [S_LOCATE_10] = {&s_locate_10},
  [S_ERASE_10] = {&s_erase_10},
  [S_READ_UPDATED_BLOCK] = {&s_read_updated_block},
  [S_WRITE_AND_VERIFY_10] = {&s_write_and_verify_10},
  [S_VERIFY_10] = {&s_verify_10},
  [S_SET_LIMITS_10] = {&s_set_limits_10},
  [S_PRE_FETCH_10] = {&s_pre_fetch_10},
  [S_READ_POSITION] = {&s_read_position},
  [S_SYNCHRONIZE_CACHE_10] = {&s_synchronize_cache_10},
  [S_LOCK_UNLOCK_CACHE_10] = {&s_lock_unlock_cache_10},
  [S_READ_DEFECT_DATA_10] = {&s_read_defect_data_10},
  [S_INITIALIZE_ELEMENT_STATUS_WITH_RANGE] = {&s_initialize_element_status_with_range},
  [S_MEDIUM_SCAN] = {&s_medium_scan},
  [S_COMPARE] = {&s_compare},
  [S_COPY_AND_VERIFY] = {&s_copy_and_verify},
  [S_WRITE_BUFFER] = {&s_write_buffer},
  [S_READ_BUFFER] = {&s_read_buffer},
  [S_UPDATE_BLOCK] = {&s_update_block},
  [S_READ_LONG_10] = {&s_read_long_10},
  [S_WRITE_LONG_10] = {&s_write_long_10},
  [S_CHANGE_DEFINITION] = {&s_change_definition},
  [S_WRITE_SAME_10] = {&s_write_same_10},
  [S_UNMAP] = {&s_unmap},
  [S_READ_TOC_PMA_ATIP] = {&s_read_toc_pma_atip},
  [S_REPORT_DENSITY_SUPPORT] = {&s_report_density_support},
  [S_PLAY_AUDIO_10] = {&s_play_audio_10},
  [S_GET_CONFIGURATION] = {&s_get_configuration},
  [S_PLAY_AUDIO_MSF] = {&s_play_audio_msf},
  [S_SANITIZE] = {&s_sanitize},
  [S_GET_EVENT_STATUS_NOTIFICATION] = {&s_get_event_status_notification},
  [S_PAUSE_RESUME] = {&s_pause_resume},
  [S_LOG_SELECT] = {&s_log_select},
  [S_LOG_SENSE] = {&s_log_sense},
  [S_XDWRITE_10] = {&s_xdwrite_10},
  [S_XPWRITE_10] = {&s_xpwrite_10},
  [S_READ_DISC_INFORMATION] = {&s_read_disc_information},
  [S_XDREAD_10] = {&s_xdread_10},
  [S_XDWRITEREAD_10] = {&s_xdwriteread_10},
  [S_SEND_OPC_INFORMATION] = {&s_send_opc_information},
  [S_MODE_SELECT_10] = {&s_mode_select_10},
  [S_RESERVE_10] = {&s_reserve_10},
  [S_RELEASE_10] = {&s_release_10},
  [S_REPAIR_TRACK] = {&s_repair_track},
  [S_MODE_SENSE_10] = {&s_mode_sense_10},
  [S_CLOSE_TRACK_SESSION] = {&s_close_track_session},
  [S_READ_BUFFER_CAPACITY] = {&s_read_buffer_capacity},
  [S_SEND_CUE_SHEET] = {&s_send_cue_sheet},
  [S_PERSISTENT_RESERVE_IN] = {&s_persistent_reserve_in},
  [S_PERSISTENT_RESERVE_OUT] = {&s_persistent_reserve_out},
  [S_EXTENDED_CDB] = {&s_extended_cdb},
  [S_VARIABLE_LENGTH_CDB] = {&s_variable_length_cdb},
  [S_XDWRITE_EXTENDED_16] = {&s_xdwrite_extended_16},
  [S_WRITE_FILEMARKS_16] = {&s_write_filemarks_16},
  [S_READ_REVERSE_16] = {&s_read_reverse_16},
  [S_THIRD_PARTY_COPY_OUT_COMMANDS] = {&s_third_party_copy_out_commands},
  [S_THIRD_PARTY_COPY_IN_COMMANDS] = {&s_third_party_copy_in_commands},
  [S_ATA_PASS_THROUGH_16] = {&s_ata_pass_through_16},
  [S_ACCESS_CONTROL_IN] = {&s_access_control_in},
  [S_ACCESS_CONTROL_OUT] = {&s_access_control_out},
  [S_READ_16] = {&s_read_16},
  [S_COMPARE_AND_WRITE] = {&s_compare_and_write},
  [S_WRITE_16] = {&s_write_16},
  [S_ORWRITE] = {&s_orwrite},
  [S_READ_ATTRIBUTE] = {&s_read_attribute},
  [S_WRITE_ATTRIBUTE] = {&s_write_attribute},
  [S_WRITE_AND_VERIFY_16] = {&s_write_and_verify_16},
  [S_VERIFY_16] = {&s_verify_16},
  [S_PRE_FETCH_16] = {&s_pre_fetch_16},
  [S_SYNCHRONIZE_CACHE_16] = {&s_synchronize_cache_16},
  [S_SPACE_16] = {&s_space_16},
  [S_LOCK_UNLOCK_CACHE_16] = {&s_lock_unlock_cache_16},
  [S_LOCATE_16] = {&s_locate_16},
  [S_WRITE_SAME_16] = {&s_write_same_16},
  [S_ERASE_16] = {&s_erase_16},
  [S_SERVICE_ACTION_BIDIRECTIONAL] = {&s_service_action_bidirectional},
  [S_SERVICE_ACTION_IN_16] = {&s_service_action_in_16},
  [S_SERVICE_ACTION_OUT_16] = {&s_service_action_out_16},
  [S_REPORT_LUNS] = {&s_report_luns},
  [S_ATA_PASS_THROUGH_12] = {&s_ata_pass_through_12},
  [S_SECURITY_PROTOCOL_IN] = {&s_security_protocol_in},
  [S_MAINTENANCE_IN] = {&s_maintenance_in},
  [S_MAINTENANCE_OUT] = {&s_maintenance_out},
  [S_REPORT_KEY] = {&s_report_key},
  [S_MOVE_MEDIUM] = {&s_move_medium},
  [S_PLAY_AUDIO_12] = {&s_play_audio_12},
  [S_EXCHANGE_MEDIUM] = {&s_exchange_medium},
  [S_MOVE_MEDIUM_ATTACHED] = {&s_move_medium_attached},
  [S_READ_12] = {&s_read_12},
  [S_SERVICE_ACTION_OUT_12] = {&s_service_action_out_12},
  [S_WRITE_12] = {&s_write_12},
  [S_SERVICE_ACTION_IN_12] = {&s_service_action_in_12},
  [S_ERASE_12] = {&s_erase_12},
  [S_READ_DVD_STRUCTURE] = {&s_read_dvd_structure},
  [S_WRITE_AND_VERIFY_12] = {&s_write_and_verify_12},
  [S_VERIFY_12] = {&s_verify_12},
  [S_SEARCH_DATA_HIGH_12] = {&s_search_data_high_12},
  [S_SEARCH_DATA_EQUAL_12] = {&s_search_data_equal_12},
  [S_SEARCH_DATA_LOW_12] = {&s_search_data_low_12},
  [S_SET_LIMITS_12] = {&s_set_limits_12},
  [S_READ_ELEMENT_STATUS_ATTACHED] = {&s_read_element_status_attached},
  [S_SECURITY_PROTOCOL_OUT] = {&s_security_protocol_out},
  [S_SEND_VOLUME_TAG] = {&s_send_volume_tag},
  [S_READ_DEFECT_DATA_12] = {&s_read_defect_data_12},
  [S_READ_ELEMENT_STATUS] = {&s_read_element_status},
  [S_READ_CD_MSF] = {&s_read_cd_msf},
  [S_REDUNDANCY_GROUP_IN] = {&s_redundancy_group_in},
  [S_REDUNDANCY_GROUP_OUT] = {&s_redundancy_group_out},
  [S_SPARE_IN] = {&s_spare_in},
  [S_SPARE_OUT] = {&s_spare_out},
  [S_VOLUME_SET_IN] = {&s_volume_set_in},
  [S_VOLUME_SET_OUT] = {&s_volume_set_out},
};
int
s_test_unit_ready(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_rewind(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_request_sense(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_format(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_block_limits(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_reassign_blocks(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_initialize_element_status(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_seek_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_reverse_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_filemarks_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_space_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_inquiry(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_verify_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_recover_buffered_data(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_mode_select_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_reserve_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_release_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_copy(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_erase_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_mode_sense_6(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_start_stop_unit(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_load_unload(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_receive_diagnostic_results(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_send_diagnostic(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_prevent_allow_medium_removal(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_format_capacities(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_capacity_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_generation(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_seek_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_locate_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_erase_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_updated_block(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_and_verify_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_verify_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_set_limits_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_pre_fetch_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_position(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_synchronize_cache_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_lock_unlock_cache_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_defect_data_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_initialize_element_status_with_range(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_medium_scan(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_compare(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_copy_and_verify(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_buffer(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_buffer(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_update_block(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_long_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_long_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_change_definition(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_same_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_unmap(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_toc_pma_atip(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_report_density_support(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_play_audio_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_get_configuration(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_play_audio_msf(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_sanitize(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_get_event_status_notification(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_pause_resume(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_log_select(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_log_sense(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_xdwrite_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_xpwrite_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_disc_information(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_xdread_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_xdwriteread_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_send_opc_information(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_mode_select_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_reserve_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_release_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_repair_track(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_mode_sense_10(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_close_track_session(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_buffer_capacity(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_send_cue_sheet(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_persistent_reserve_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_persistent_reserve_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_extended_cdb(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_variable_length_cdb(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_xdwrite_extended_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_filemarks_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_reverse_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_third_party_copy_out_commands(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_third_party_copy_in_commands(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_ata_pass_through_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_access_control_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_access_control_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_compare_and_write(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_orwrite(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_attribute(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_attribute(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_and_verify_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_verify_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_pre_fetch_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_synchronize_cache_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_space_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_lock_unlock_cache_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_locate_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_same_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_erase_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_service_action_bidirectional(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_service_action_in_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_service_action_out_16(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_report_luns(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_ata_pass_through_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_security_protocol_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_maintenance_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_maintenance_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_report_key(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_move_medium(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_play_audio_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_exchange_medium(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_move_medium_attached(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_service_action_out_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_service_action_in_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_erase_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_dvd_structure(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_write_and_verify_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_verify_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_search_data_high_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_search_data_equal_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_search_data_low_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_set_limits_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_element_status_attached(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_security_protocol_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_send_volume_tag(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_defect_data_12(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_element_status(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_read_cd_msf(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_redundancy_group_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_redundancy_group_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_spare_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_spare_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_volume_set_in(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

int
s_volume_set_out(struct scsi_cmnd *scp, struct sp_dev_info *sdp)
{
  pr_info("\n");
  return 0;
}

#define CMD(n) case n: pr_info("cmd: %s\n", #n);return &sp_opcode_arr[n]
struct sp_opcode_info_t *sp_get_opcode_info(u8 cmd)
{
  switch(cmd) {

    CMD(S_TEST_UNIT_READY);

    CMD(S_REWIND);

    CMD(S_REQUEST_SENSE);

    CMD(S_FORMAT);

    CMD(S_READ_BLOCK_LIMITS);

    CMD(S_REASSIGN_BLOCKS);

    CMD(S_READ_6);

    CMD(S_WRITE_6);

    CMD(S_SEEK_6);

    CMD(S_READ_REVERSE_6);

    CMD(S_WRITE_FILEMARKS_6);

    CMD(S_SPACE_6);

    CMD(S_INQUIRY);

    CMD(S_VERIFY_6);

    CMD(S_RECOVER_BUFFERED_DATA);

    CMD(S_MODE_SELECT_6);

    CMD(S_RESERVE_6);

    CMD(S_RELEASE_6);

    CMD(S_COPY);

    CMD(S_ERASE_6);

    CMD(S_MODE_SENSE_6);

    CMD(S_START_STOP_UNIT);

    CMD(S_RECEIVE_DIAGNOSTIC_RESULTS);

    CMD(S_SEND_DIAGNOSTIC);

    CMD(S_PREVENT_ALLOW_MEDIUM_REMOVAL);

    CMD(S_READ_FORMAT_CAPACITIES);

    CMD(S_READ_CAPACITY_10);

    CMD(S_READ_10);

    CMD(S_READ_GENERATION);

    CMD(S_WRITE_10);

    CMD(S_SEEK_10);

    CMD(S_ERASE_10);

    CMD(S_READ_UPDATED_BLOCK);

    CMD(S_WRITE_AND_VERIFY_10);

    CMD(S_VERIFY_10);

    CMD(S_SET_LIMITS_10);

    CMD(S_PRE_FETCH_10);

    CMD(S_SYNCHRONIZE_CACHE_10);

    CMD(S_LOCK_UNLOCK_CACHE_10);

    CMD(S_READ_DEFECT_DATA_10);

    CMD(S_MEDIUM_SCAN);

    CMD(S_COMPARE);

    CMD(S_COPY_AND_VERIFY);

    CMD(S_WRITE_BUFFER);

    CMD(S_READ_BUFFER);

    CMD(S_UPDATE_BLOCK);

    CMD(S_READ_LONG_10);

    CMD(S_WRITE_LONG_10);

    CMD(S_CHANGE_DEFINITION);

    CMD(S_WRITE_SAME_10);

    CMD(S_UNMAP);

    CMD(S_READ_TOC_PMA_ATIP);

    CMD(S_REPORT_DENSITY_SUPPORT);

    CMD(S_PLAY_AUDIO_10);

    CMD(S_GET_CONFIGURATION);

    CMD(S_PLAY_AUDIO_MSF);

    CMD(S_SANITIZE);

    CMD(S_GET_EVENT_STATUS_NOTIFICATION);

    CMD(S_PAUSE_RESUME);

    CMD(S_LOG_SELECT);

    CMD(S_LOG_SENSE);

    CMD(S_XDWRITE_10);

    CMD(S_XPWRITE_10);

    CMD(S_XDREAD_10);

    CMD(S_XDWRITEREAD_10);

    CMD(S_SEND_OPC_INFORMATION);

    CMD(S_MODE_SELECT_10);

    CMD(S_RESERVE_10);

    CMD(S_RELEASE_10);

    CMD(S_REPAIR_TRACK);

    CMD(S_MODE_SENSE_10);

    CMD(S_CLOSE_TRACK_SESSION);

    CMD(S_READ_BUFFER_CAPACITY);

    CMD(S_SEND_CUE_SHEET);

    CMD(S_PERSISTENT_RESERVE_IN);

    CMD(S_PERSISTENT_RESERVE_OUT);

    CMD(S_EXTENDED_CDB);

    CMD(S_VARIABLE_LENGTH_CDB);

    CMD(S_XDWRITE_EXTENDED_16);

    CMD(S_READ_REVERSE_16);

    CMD(S_THIRD_PARTY_COPY_OUT_COMMANDS);

    CMD(S_THIRD_PARTY_COPY_IN_COMMANDS);

    CMD(S_ATA_PASS_THROUGH_16);

    CMD(S_ACCESS_CONTROL_IN);

    CMD(S_ACCESS_CONTROL_OUT);

    CMD(S_READ_16);

    CMD(S_COMPARE_AND_WRITE);

    CMD(S_WRITE_16);

    CMD(S_ORWRITE);

    CMD(S_READ_ATTRIBUTE);

    CMD(S_WRITE_ATTRIBUTE);

    CMD(S_WRITE_AND_VERIFY_16);

    CMD(S_VERIFY_16);

    CMD(S_PRE_FETCH_16);

    CMD(S_SYNCHRONIZE_CACHE_16);

    CMD(S_LOCK_UNLOCK_CACHE_16);

    CMD(S_WRITE_SAME_16);

    CMD(S_SERVICE_ACTION_BIDIRECTIONAL);

    CMD(S_SERVICE_ACTION_IN_16);

    CMD(S_SERVICE_ACTION_OUT_16);

    CMD(S_REPORT_LUNS);

    CMD(S_ATA_PASS_THROUGH_12);

    CMD(S_SECURITY_PROTOCOL_IN);

    CMD(S_MAINTENANCE_IN);

    CMD(S_MAINTENANCE_OUT);

    CMD(S_MOVE_MEDIUM);

    CMD(S_EXCHANGE_MEDIUM);

    CMD(S_MOVE_MEDIUM_ATTACHED);

    CMD(S_READ_12);

    CMD(S_SERVICE_ACTION_OUT_12);

    CMD(S_WRITE_12);

    CMD(S_SERVICE_ACTION_IN_12);

    CMD(S_ERASE_12);

    CMD(S_READ_DVD_STRUCTURE);

    CMD(S_WRITE_AND_VERIFY_12);

    CMD(S_VERIFY_12);

    CMD(S_SEARCH_DATA_HIGH_12);

    CMD(S_SEARCH_DATA_EQUAL_12);

    CMD(S_SEARCH_DATA_LOW_12);

    CMD(S_SET_LIMITS_12);

    CMD(S_READ_ELEMENT_STATUS_ATTACHED);

    CMD(S_SECURITY_PROTOCOL_OUT);

    CMD(S_SEND_VOLUME_TAG);

    CMD(S_READ_DEFECT_DATA_12);

    CMD(S_READ_ELEMENT_STATUS);

    CMD(S_READ_CD_MSF);

    CMD(S_REDUNDANCY_GROUP_IN);

    CMD(S_REDUNDANCY_GROUP_OUT);

    CMD(S_SPARE_IN);

    CMD(S_SPARE_OUT);

    CMD(S_VOLUME_SET_IN);

    CMD(S_VOLUME_SET_OUT);


    default: pr_info("Invalid cmd: 0x%2x\n", cmd);return NULL;
  }
}

