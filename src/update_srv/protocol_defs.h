/****************************************************************************
 * (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
 *                                                                           *
 * Confidential computer software. Valid license from HP required for        *
 * possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
 * Commercial Computer Software, Computer Software Documentation, and        *
 * Technical Data for Commercial Items are licensed to the U.S. Government   *
 * under vendor's standard commercial license.                               *
 ****************************************************************************/

#ifndef PROTOCOL_DEFS_H
#define PROTOCOL_DEFS_H

#include "serialization/NamedSerialize.h"

using namespace epee;

namespace omaha 
{
namespace transport 
{
struct action_entity 
{
  std::string arguments;
  std::string event;
  std::string run;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(arguments)
    SERIALIZE_STL_ANSI_STRING(event)
    SERIALIZE_STL_ANSI_STRING(run)
  END_NAMED_SERIALIZE_MAP()
};

struct actions_entity 
{
  std::list<action_entity> action;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_CONTAINER_T(action)
  END_NAMED_SERIALIZE_MAP()
};

struct package_entity 
{
  std::string hash;
  std::string name;
  std::string required;
  std::string size;
  std::string baseversion;
  std::string nextversion;
  std::string updatetype;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(hash)
    SERIALIZE_STL_ANSI_STRING(name)
    SERIALIZE_STL_ANSI_STRING(required)
    SERIALIZE_STL_ANSI_STRING(size)
    SERIALIZE_STL_ANSI_STRING(baseversion)
    SERIALIZE_STL_ANSI_STRING(nextversion)
    SERIALIZE_STL_ANSI_STRING(updatetype)
  END_NAMED_SERIALIZE_MAP()
};

struct packages_entity 
{
  std::list<package_entity> package;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_CONTAINER_T(package)
  END_NAMED_SERIALIZE_MAP()
};

struct diff_entity 
{
  std::string algo;
  std::string base_version;
  std::string file_name;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(algo)
    SERIALIZE_STL_ANSI_STRING(base_version)
    SERIALIZE_STL_ANSI_STRING(file_name)
  END_NAMED_SERIALIZE_MAP()
};

struct diffs_entity 
{
  std::list<diff_entity> diff;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_CONTAINER_T(diff)
  END_NAMED_SERIALIZE_MAP()
};

struct manifest_entity 
{
  std::string version;
  packages_entity packages;
  actions_entity actions;
  diffs_entity diffs;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(version)
    SERIALIZE_T(packages)
    SERIALIZE_T(actions)
    SERIALIZE_T(diffs)
  END_NAMED_SERIALIZE_MAP()
};

struct url_entity 
{
  std::string codebase;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(codebase)
  END_NAMED_SERIALIZE_MAP()
};

struct urls_entity 
{
  std::list<url_entity> url;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_CONTAINER_T(url)
  END_NAMED_SERIALIZE_MAP()
};

namespace update_reqest 
{
/*
request example from https://code.google.com/p/omaha/wiki/ServerProtocol:
<?xml version="1.0" encoding="UTF-8"?>
<request protocol="3.0" version="1.3.23.0" ismachine="0" sessionid="{5FAD27D4-6BFA-4daa-A1B3-5A1F821FEE0F}" userid="{D0BBD725-742D-44ae-8D46-0231E881D58E}" installsource="scheduler" testsource="ossdev" requestid="{C8F6EDF3-B623-4ee6-B2DA-1D08A0B4C665}">
  <os platform="win" version="6.1" sp="" arch="x64"/>
  <app appid="{430FD4D0-B729-4F61-AA34-91526481799D}" version="1.3.23.0" nextversion="" lang="en" brand="GGLS" client="someclientid" installage="39">
    <updatecheck/>
    <ping r="1"/>
  </app>
  <app appid="{D0AB2EBC-931B-4013-9FEB-C9C4C2225C8C}" version="2.2.2.0" nextversion="" lang="en" brand="GGLS" client="" installage="6">
    <updatecheck/>
    <ping r="1"/>
  </app>
</request>
*/

struct ping_entity
{
  std::string r;
  std::string active;
  std::string a;
  
  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(r)
    SERIALIZE_STL_ANSI_STRING(active)
    SERIALIZE_STL_ANSI_STRING(a)
  END_NAMED_SERIALIZE_MAP()
};

struct event_request_entity 
{
  std::string eventtype;
  std::string eventresult;
  std::string errorcode;
  std::string extracode1;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(eventtype)
    SERIALIZE_STL_ANSI_STRING(eventresult)
    SERIALIZE_STL_ANSI_STRING(errorcode)
    SERIALIZE_STL_ANSI_STRING(extracode1)
  END_NAMED_SERIALIZE_MAP()
};

struct updatecheck_entity 
{
  BEGIN_NAMED_SERIALIZE_MAP()
  END_NAMED_SERIALIZE_MAP()
};

struct app_request_entity 
{
  std::string appid;
  std::string version;
  std::string nextversion;
  std::string lang;
  std::string brand;
  std::string client;
  std::string installage;
  enableable<updatecheck_entity> updatecheck;
  enableable<ping_entity> ping;
  std::list<event_request_entity> events;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(appid)
    SERIALIZE_STL_ANSI_STRING(version)
    SERIALIZE_STL_ANSI_STRING(nextversion)
    SERIALIZE_STL_ANSI_STRING(lang)
    SERIALIZE_STL_ANSI_STRING(brand)
    SERIALIZE_STL_ANSI_STRING(client)
    SERIALIZE_STL_ANSI_STRING(installage)
    SERIALIZE_T(updatecheck)
    SERIALIZE_T(ping)
    N_SERIALIZE_STL_CONTAINER_T(events, "event")
  END_NAMED_SERIALIZE_MAP()
};

struct os_entity 
{
  std::string platform;
  std::string version;
  std::string sp;
  std::string arch;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(platform)
    SERIALIZE_STL_ANSI_STRING(version)
    SERIALIZE_STL_ANSI_STRING(sp)
    SERIALIZE_STL_ANSI_STRING(arch)
  END_NAMED_SERIALIZE_MAP()
};

struct request_entity 
{
  std::string protocol;
  std::string version;
  std::string ismachine;
  std::string sessionid;
  std::string userid;
  std::string installsource;
  std::string testsource;
  std::string requestid;
  std::list<app_request_entity> apps;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(protocol)
    SERIALIZE_STL_ANSI_STRING(version)
    SERIALIZE_STL_ANSI_STRING(ismachine)
    SERIALIZE_STL_ANSI_STRING(sessionid)
    SERIALIZE_STL_ANSI_STRING(userid)
    SERIALIZE_STL_ANSI_STRING(installsource)
    SERIALIZE_STL_ANSI_STRING(testsource)
    SERIALIZE_STL_ANSI_STRING(requestid)
    N_SERIALIZE_STL_CONTAINER_T(apps, "app")
  END_NAMED_SERIALIZE_MAP()
};

struct request_wrapper 
{
  request_entity request;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_T(request)
  END_NAMED_SERIALIZE_MAP()
};

//response
/*
<?xml version="1.0" encoding="UTF-8"?>
<response protocol="3.0" server="prod">
  <daystart elapsed_seconds="23583"/>
  <app appid="{D0AB2EBC-931B-4013-9FEB-C9C4C2225C8C}" status="ok">
    <updatecheck status="ok">
      <urls>
        <url codebase="http://cache.pack.google.com/edgedl/googletalk/googletalkplugin/3.9.1.9832/"/>
        <url codebase="http://dl.google.com/googletalk/googletalkplugin/3.9.1.9832/"/>
        <url codebase="https://dl-ssl.google.com/googletalk/googletalkplugin/3.9.1.9832/"/>
      </urls>
      <manifest version="3.9.1.9832">
        <packages>
          <package hash="ooT2Za/cU2tK2udDkD+9TLk7FL0=" name="googletalkpluginaccel.msi" required="true" size="7980032"/>
        </packages>
        <diffs>
          <diff algo="courgette" base_version="1.3.25.64" file_name="OzUpdate_diffs_1.3.25.64.zip" />
          <diff algo="courgette" base_version="1.3.25.63" file_name="OzUpdate_diffs_1.3.25.63.zip" />
          <diff algo="courgette" base_version="1.3.25.62" file_name="OzUpdate_diffs_1.3.25.62.zip" />
          <diff algo="courgette" base_version="1.3.25.61" file_name="OzUpdate_diffs_1.3.25.61.zip" />
          <diff algo="courgette" base_version="1.3.25.60" file_name="OzUpdate_diffs_1.3.25.60.zip" />
        </diffs>
        <actions>
          <action arguments="/qn MANUAL=1" event="install" run="googletalkpluginaccel.msi"/>
          <action event="postinstall"/>
        </actions>
      </manifest>
    </updatecheck>
  </app>
</response>
*/

struct updatecheck_response_entity 
{
  std::string status;
  enableable<urls_entity> urls;
  enableable<manifest_entity> manifest;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(status)
    SERIALIZE_T(urls)
    SERIALIZE_T(manifest)
  END_NAMED_SERIALIZE_MAP()
};

struct daystart_entity 
{
  std::string elapsed_seconds;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(elapsed_seconds)
  END_NAMED_SERIALIZE_MAP()
};

struct ping_response_entity 
{
  std::string status;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(status)
  END_NAMED_SERIALIZE_MAP()
};

struct event_response_entity 
{
  std::string status;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(status)
  END_NAMED_SERIALIZE_MAP()
};

struct app_response_entity 
{
  std::string appid;
  std::string status;
  enableable<updatecheck_response_entity> updatecheck;
  enableable<ping_response_entity> ping;
  std::list<event_response_entity> events;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(appid)
    SERIALIZE_STL_ANSI_STRING(status)
    SERIALIZE_T(updatecheck)
    SERIALIZE_T(ping)
    N_SERIALIZE_STL_CONTAINER_T(events, "event")
  END_NAMED_SERIALIZE_MAP()
};

struct response_entity 
{
  std::string protocol;
  std::string server;
  daystart_entity daystart;
  std::list<app_response_entity> apps;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_STL_ANSI_STRING(protocol)
    SERIALIZE_STL_ANSI_STRING(server)
    SERIALIZE_T(daystart)
    N_SERIALIZE_STL_CONTAINER_T(apps, "app")
  END_NAMED_SERIALIZE_MAP()
};

struct response_wrapper 
{
  response_entity response;

  BEGIN_NAMED_SERIALIZE_MAP()
    SERIALIZE_T(response)
  END_NAMED_SERIALIZE_MAP()
};}  // namespace update_reqest

namespace configure_request
{
  /*
    a.sabelnikov: as request using omaha::server::config::application_entry 
    serialized as json, the same for configure_response - it used to be 
    represented as json as well.
  */

  struct configure_response
  {
    std::string status; //OK or Fail
    std::string server_comment; //in case of error

    BEGIN_NAMED_SERIALIZE_MAP()
      SERIALIZE_STL_ANSI_STRING(status)
      SERIALIZE_STL_ANSI_STRING(server_comment)
    END_NAMED_SERIALIZE_MAP()
  };

} //namespace configure_request
}  // namespace xml
}  // namespace omaha

#endif  // PROTOCOL_DEFS_H
