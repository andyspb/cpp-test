/****************************************************************************
 * (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
 *                                                                           *
 * Confidential computer software. Valid license from HP required for        *
 * possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
 * Commercial Computer Software, Computer Software Documentation, and        *
 * Technical Data for Commercial Items are licensed to the U.S. Government   *
 * under vendor's standard commercial license.                               *
 ****************************************************************************/

#ifndef HANDLERS_CONFIG_H
#define HANDLERS_CONFIG_H

#include "serialization/NamedSerialize.h"
#include "protocol_defs.h"

namespace omaha {
namespace server {
namespace config {

/*
 !! Please DO NOT CHANGE formatting for this file! A.Sabelnikov !!
 */

/*
 config entry example:

<application app_name="Oz Update" app_id="{DD7E00B2-6188-43A6-9775-4632AD97FAD1}" needs_admin="true" language="en">
  <os platform="win" arch="x64">
    <app_last_version local_path="D:\Develope\HP\lux\omaha\Debug\www\">
      <urls>
        <url codebase="http://www.ushqhpb0202.palm.com/download/"/>
        <url codebase="http://www.ushqhpb0202.palm.com/download/1/"/>
        <url codebase="http://www.ushqhpb0202.palm.com/download/2/"/>
      </urls>
      <manifest version="1.3.25.0">
        <packages>
          <package hash="" name="OzUpdate.exe" required="true" size=""/>
        </packages>
        <diffs>
          <diff algo="courgette" base_version="1.3.25.64" file_name="OzUpdate_diffs_1.3.25.64.zip" />
          <diff algo="courgette" base_version="1.3.25.63" file_name="OzUpdate_diffs_1.3.25.63.zip" />
          <diff algo="courgette" base_version="1.3.25.62" file_name="OzUpdate_diffs_1.3.25.62.zip" />
          <diff algo="courgette" base_version="1.3.25.61" file_name="OzUpdate_diffs_1.3.25.61.zip" />
          <diff algo="courgette" base_version="1.3.25.60" file_name="OzUpdate_diffs_1.3.25.60.zip" />
        </diffs>
        <actions>
          <action arguments="/c" event="install" run="OzUpdate.exe"/>
        </actions>
      </manifest>
    </app_last_version>
  </os>
</application>

 */

struct application_update_details 
{
  omaha::transport::urls_entity urls;
  omaha::transport::manifest_entity manifest;
  std::string local_path;

  BEGIN_NAMED_SERIALIZE_MAP()SERIALIZE_T(urls)
    SERIALIZE_T(manifest)
    SERIALIZE_STL_ANSI_STRING(local_path)
  END_NAMED_SERIALIZE_MAP()
};

struct application_os 
{
  std::string platform;
  std::string arch;
  application_update_details public_release;
  application_update_details public_beta;
  application_update_details internal_beta;
  //just a stub - for backward capability
  //application_update_details app_last_version;

  BEGIN_NAMED_SERIALIZE_MAP()SERIALIZE_STL_ANSI_STRING(platform)
    SERIALIZE_STL_ANSI_STRING(arch)
    SERIALIZE_T(public_release)
    SERIALIZE_T(public_beta)
    SERIALIZE_T(internal_beta)
  END_NAMED_SERIALIZE_MAP()

  //std::string version;
};

struct application_entry 
{
  std::string app_name;
  std::string app_id;
  std::string needs_admin;
  std::string language;
  std::list<application_os> os;

  BEGIN_NAMED_SERIALIZE_MAP()SERIALIZE_STL_ANSI_STRING(app_name)
    SERIALIZE_STL_ANSI_STRING(app_id)
    SERIALIZE_STL_ANSI_STRING(needs_admin)
    SERIALIZE_STL_ANSI_STRING(language)
    SERIALIZE_STL_CONTAINER_T(os)
  END_NAMED_SERIALIZE_MAP()
};

struct http_settings 
{
  std::string home;

  BEGIN_NAMED_SERIALIZE_MAP()
     SERIALIZE_STL_ANSI_STRING(home)
  END_NAMED_SERIALIZE_MAP()
};

struct connection_settings 
{
  std::string bind_ip;
  std::string listen_port;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(bind_ip)
    SERIALIZE_STL_ANSI_STRING(listen_port)
  END_NAMED_SERIALIZE_MAP()

};

struct generic_settings 
{
  http_settings http;
  connection_settings connection;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_T(http)
    SERIALIZE_T(connection)
  END_NAMED_SERIALIZE_MAP()
};

struct handlers_config 
{
  std::list<application_entry> application;
  generic_settings global_settings;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_CONTAINER_T(application)
    SERIALIZE_T(global_settings)
  END_NAMED_SERIALIZE_MAP()
};

}  // namespace omaha
}  // namespace server
}  // namespace config

#endif  // HANDLERS_CONFIG_H
