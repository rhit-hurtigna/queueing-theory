#ifndef POLICY_H
#define POLICY_H
#include "queue_standard.h"
#include "job.h"
#include <unordered_set>

class Policy {
public:
    virtual std::unordered_set<Job, JobHash> choose(std::unordered_set<Job, JobHash> jobs, unsigned int k) = 0;
};

class IndexPolicy: public Policy {
public:
    std::unordered_set<Job, JobHash> choose(std::unordered_set<Job, JobHash> jobs, unsigned int k);
private:
    virtual real getIndex(Job job) = 0;
};

class FCFSPolicy: public IndexPolicy {
private:
    real getIndex(Job job);
};

bool compareJobs(IndexedJob a, IndexedJob b);

#endif
