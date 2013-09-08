/****************************************************************************
 * (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
 *                                                                           *
 * Confidential computer software. Valid license from HP required for        *
 * possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
 * Commercial Computer Software, Computer Software Documentation, and        *
 * Technical Data for Commercial Items are licensed to the U.S. Government   *
 * under vendor's standard commercial license.                               *
 ****************************************************************************/

#ifndef INCREMENTAL_UPDATE_DEFS_H
#define INCREMENTAL_UPDATE_DEFS_H

#include "serialization/NamedSerialize.h"

namespace omaha {
namespace incremental_update {

struct diff_entry {
BEGIN_NAMED_SERIALIZE_MAP()END_NAMED_SERIALIZE_MAP()
};

struct new_file_entry {
BEGIN_NAMED_SERIALIZE_MAP()END_NAMED_SERIALIZE_MAP()
};

struct package_struct {
  std::list<diff_entry> diffs;
  std::list<new_file_entry> new_files;

BEGIN_NAMED_SERIALIZE_MAP()SERIALIZE_STL_CONTAINER_T(diffs)
  SERIALIZE_STL_CONTAINER_T(new_files)
  END_NAMED_SERIALIZE_MAP()
};

}  // incremental_update
}  // omaha

#endif  // INCREMENTAL_UPDATE_DEFS_H
