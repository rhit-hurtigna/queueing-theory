#ifndef INDEXED_JOB_H
#define INDEXED_JOB_H
#include "queue_standard.h"
#include "policy.h"
#include "job.h"

class IndexedJob : public JobInterface {
public:
    IndexedJob(Policy *p, Job job, real gamma);
    real rank;
    Job job;

    real nextInterrupt() const;
    real getRequired() const;
    void serve(real time);
    void show() const;

    void addToService();
    void removeFromService();

    bool closeTo(const IndexedJob other) const;

    bool operator<(const IndexedJob& other) const;
    struct ReverseComparator {
        bool operator()(const IndexedJob& lhs, const IndexedJob &rhs) const;
    };
    unsigned int getID() const;
private:
    Policy *p;
    bool inService;
    real preemptTime;
    const real gamma;
};

#endif
