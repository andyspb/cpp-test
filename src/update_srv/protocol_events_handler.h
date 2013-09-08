/****************************************************************************
 * (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
 *                                                                           *
 * Confidential computer software. Valid license from HP required for        *
 * possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
 * Commercial Computer Software, Computer Software Documentation, and        *
 * Technical Data for Commercial Items are licensed to the U.S. Government   *
 * under vendor's standard commercial license.                               *
 ****************************************************************************/

#ifndef PROTOCOL_EVENTS_HANDLER_H
#define PROTOCOL_EVENTS_HANDLER_H

namespace omaha {
namespace protocol {
// The extra code represents the file order as defined by the setup.
//static const int kSetupFilesExtraCodeMask = 0x00000100;

// The extra code represents a state of the app state machine.
//static const int kAppStateExtraCodeMask   = 0x10000000;

// When updating this enum, also update the protocol file on the server.
// These values get reported to the server, so do not change existing ones.
//
// Checkpoints:
//  "EVENT_INSTALL_*" events report the progress of initial installs.
//  "EVENT_UPDATE_*" events report the progress of silent updates.
//  These checkpoints represent the "START" or "FINISH" of a phase.
// Actions:
//  "EVENT_*_BEGIN" events report the start of a specific action (i.e. job).
//  "EVENT_*_COMPLETE" events represent the end of such actions and report
// successful completion or the error that occurred during the action.
enum event_types {
  EVENT_UNKNOWN = 0,
  EVENT_INSTALL_DOWNLOAD_FINISH = 1,
  EVENT_INSTALL_COMPLETE = 2,
  EVENT_UPDATE_COMPLETE = 3,
  EVENT_UNINSTALL = 4,
  EVENT_INSTALL_DOWNLOAD_START = 5,
  EVENT_INSTALL_INSTALLER_START = 6,
  // Never used = 7
  // No longer used - EVENT_INSTALLED_GOOPDATE_STARTED = 8,
  EVENT_INSTALL_APPLICATION_BEGIN = 9,

  // Install Setup events.
  // No longer used - EVENT_SETUP_INSTALL_BEGIN = 10,
  // No longer used - EVENT_SETUP_INSTALL_COMPLETE = 11,

  // Update Events.
  // The Update Event = 3 above is used for update completion.
  EVENT_UPDATE_APPLICATION_BEGIN = 12,
  EVENT_UPDATE_DOWNLOAD_START = 13,
  EVENT_UPDATE_DOWNLOAD_FINISH = 14,
  EVENT_UPDATE_INSTALLER_START = 15,

  // Self-update Setup events.
  // No longer used - EVENT_SETUP_UPDATE_BEGIN = 16,
  // No longer used - EVENT_SETUP_UPDATE_COMPLETE = 17,

  // Ping when installed via /registerproduct.
  EVENT_REGISTER_PRODUCT_COMPLETE = 20,

  // Ping when an end user first boots a new system with an OEM-installed app.
  EVENT_INSTALL_OEM_FIRST_CHECK = 30,

  // App Command Events
  EVENT_APP_COMMAND_BEGIN = 40,
  EVENT_APP_COMMAND_COMPLETE = 41,

// Failure report events - not part of the normal flow.
// No longer used - EVENT_SETUP_INSTALL_FAILURE = 100,
// No longer used - EVENT_GOOPDATE_DLL_FAILURE = 101,
// No longer used - EVENT_SETUP_COM_SERVER_FAILURE = 102,
// No longer used - EVENT_SETUP_UPDATE_FAILURE = 103,
};

// When updating this enum, also update the identical one in
// omaha_extensions.proto.
// These values get reported to the server, so do not change existing ones.
enum event_results {
  EVENT_RESULT_ERROR = 0,
  EVENT_RESULT_SUCCESS = 1,
  EVENT_RESULT_SUCCESS_REBOOT = 2,
  //  EVENT_RESULT_SUCCESS_RESTART_BROWSER = 3,
  EVENT_RESULT_CANCELLED = 4,
  EVENT_RESULT_INSTALLER_ERROR_MSI = 5,
  EVENT_RESULT_INSTALLER_ERROR_OTHER = 6,
  //  EVENT_RESULT_NOUPDATE = 7,
  EVENT_RESULT_INSTALLER_ERROR_SYSTEM = 8,
  EVENT_RESULT_UPDATE_DEFERRED = 9,
  EVENT_RESULT_HANDOFF_ERROR = 10,
};

//-----------------------------------------------------------------------------
const char* ping_type_to_string(event_types type) {
  switch (type) {
    case EVENT_UNKNOWN:
      return "EVENT_UNKNOWN";
    case EVENT_INSTALL_DOWNLOAD_FINISH:
      return "EVENT_INSTALL_DOWNLOAD_FINISH";
    case EVENT_INSTALL_COMPLETE:
      return "EVENT_INSTALL_COMPLETE";
    case EVENT_UPDATE_COMPLETE:
      return "EVENT_UPDATE_COMPLETE";
    case EVENT_UNINSTALL:
      return "EVENT_UNINSTALL";
    case EVENT_INSTALL_DOWNLOAD_START:
      return "EVENT_INSTALL_DOWNLOAD_START";
    case EVENT_INSTALL_INSTALLER_START:
      return "EVENT_INSTALL_INSTALLER_START";
    case EVENT_INSTALL_APPLICATION_BEGIN:
      return "EVENT_INSTALL_APPLICATION_BEGIN";

      // Install Setup events.
      //case EVENT_SETUP_INSTALL_BEGIN:
      //  return "EVENT_SETUP_INSTALL_BEGIN";
      //case EVENT_SETUP_INSTALL_COMPLETE:
      //  return "EVENT_SETUP_INSTALL_COMPLETE";

      // Register Product Events.
    case EVENT_REGISTER_PRODUCT_COMPLETE:
      return "EVENT_REGISTER_PRODUCT_COMPLETE";

      // Update Events.
    case EVENT_UPDATE_APPLICATION_BEGIN:
      return "EVENT_UPDATE_APPLICATION_BEGIN";
    case EVENT_UPDATE_DOWNLOAD_START:
      return "EVENT_UPDATE_DOWNLOAD_START";
    case EVENT_UPDATE_DOWNLOAD_FINISH:
      return "EVENT_UPDATE_DOWNLOAD_FINISH";
    case EVENT_UPDATE_INSTALLER_START:
      return "EVENT_UPDATE_INSTALLER_START";

      // Self-update Setup events.
      //case EVENT_SETUP_UPDATE_BEGIN:
      //  return "EVENT_SETUP_UPDATE_BEGIN";
      //case EVENT_SETUP_UPDATE_COMPLETE:
      //  return "EVENT_SETUP_UPDATE_COMPLETE";

      // Other events.
    case EVENT_INSTALL_OEM_FIRST_CHECK:
      return "EVENT_INSTALL_OEM_FIRST_CHECK";
    case EVENT_APP_COMMAND_BEGIN:
      return "EVENT_APP_COMMAND_BEGIN";
    case EVENT_APP_COMMAND_COMPLETE:
      return "EVENT_APP_COMMAND_COMPLETE";

      // Failure report events - not part of the normal flow.
      //case EVENT_SETUP_INSTALL_FAILURE:
      //  return "EVENT_SETUP_INSTALL_FAILURE";
      //case EVENT_SETUP_COM_SERVER_FAILURE:
      //  return "EVENT_SETUP_COM_SERVER_FAILURE";
      //case EVENT_SETUP_UPDATE_FAILURE:
      //  return "EVENT_SETUP_UPDATE_FAILURE";
    default:
      return "Unknown";
  }
}

std::string ping_result_to_string(event_results result) {
  switch (result) {
    case EVENT_RESULT_ERROR:
      return "EVENT_RESULT_ERROR";
    case EVENT_RESULT_SUCCESS:
      return "EVENT_RESULT_SUCCESS";
    case EVENT_RESULT_SUCCESS_REBOOT:
      return "EVENT_RESULT_SUCCESS_REBOOT";
    case EVENT_RESULT_CANCELLED:
      return "EVENT_RESULT_CANCELLED";
    case EVENT_RESULT_INSTALLER_ERROR_MSI:
      return "EVENT_RESULT_INSTALLER_ERROR_MSI";
    case EVENT_RESULT_INSTALLER_ERROR_OTHER:
      return "EVENT_RESULT_INSTALLER_ERROR_OTHER";
      //case EVENT_RESULT_NOUPDATE:
      //  return "EVENT_RESULT_NOUPDATE";
    case EVENT_RESULT_INSTALLER_ERROR_SYSTEM:
      return "EVENT_RESULT_INSTALLER_ERROR_SYSTEM";
    case EVENT_RESULT_UPDATE_DEFERRED:
      return "EVENT_RESULT_UPDATE_DEFERRED";
    case EVENT_RESULT_HANDOFF_ERROR:
      return "EVENT_RESULT_HANDOFF_ERROR";
    default:
      return "unknown result";
  }
}

bool handle_omaha_protocol_events(
    const omaha::transport::update_reqest::app_request_entity& data) {
  for (std::list<omaha::transport::update_reqest::event_request_entity>::const_iterator it =
      data.events.begin(); it != data.events.end(); it++) {
    boost::uint32_t ev_type = 0;
    boost::uint32_t ev_result = 0;
    if (!string_tools::get_xtype_from_string(ev_type, it->eventtype)
        || !string_tools::get_xtype_from_string(ev_result, it->eventresult)) {
      LOG_ERROR("Failed to convert event code");
      return false;
    }

    LOG_PRINT_L0(
        "[GLOBAL_OBSERVER] Ping App = " << data.appid << ", Type = "
            << ping_type_to_string(static_cast<event_types>(ev_type))
            << ", Result = "
            << ping_result_to_string(static_cast<event_results>(ev_result))
            << ", Error = " << it->errorcode);
  }
  return true;
}

}  // namespace protocol
}  // namespace omaha

#endif  // PROTOCOL_EVENTS_HANDLER_H
