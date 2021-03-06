/**
 * This file is part of the CernVM File System.
 */

#ifndef CVMFS_SWISSKNIFE_LEASE_CURL_H_
#define CVMFS_SWISSKNIFE_LEASE_CURL_H_

#include <string>

#include "curl/curl.h"

#define REPO_SERVICES_API_ROOT "/api/v1"

struct CurlBuffer {
  std::string data;
};

size_t RecvCB(void* buffer, size_t size, size_t nmemb, void* userp);

CURL* PrepareCurl(const char* method);

bool MakeAcquireRequest(const std::string& user_name,
                        const std::string& lease_fqdn,
                        const std::string& repo_service_url,
                        CurlBuffer* buffer);

bool MakeDeleteRequest(const std::string& session_token,
                       const std::string& repo_service_url, CurlBuffer* buffer);

#endif  // CVMFS_SWISSKNIFE_LEASE_CURL_H_
