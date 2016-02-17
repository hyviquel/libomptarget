#ifndef _INCLUDE_AMAZON_H_
#define _INCLUDE_AMAZON_H_

#include "INIReader.h"
#include "generic.h"
#include "../rtl.h"

struct AmazonInfo {
  std::string Bucket;
  std::string Cluster;
};

GenericProvider *createAmazonProvider(ResourceInfo &resources);

class AmazonProvider : public GenericProvider {
  private:
    AmazonInfo ainfo;
  public:
    AmazonProvider(ResourceInfo resources) : GenericProvider(resources) {}

    int32_t parse_config(INIReader reader);
    int32_t send_file(const char *filename, const char *tgtfilename);
    int32_t data_submit(void *tgt_ptr, void *hst_ptr, int64_t size, int32_t id);
    int32_t data_retrieve(void *hst_ptr, void *tgt_ptr, int64_t size, int32_t id);
    int32_t data_delete(void *tgt_ptr, int32_t id);
    int32_t submit_job();
};

#endif
