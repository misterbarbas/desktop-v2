#include "pingtime.h"
#include <QObject>

const int typeIdPingTime = qRegisterMetaType<locationsmodel::PingTime>("locationsmodel::PingTime");

namespace locationsmodel {


PingTime::PingTime()
{
    timeMs_ = NO_PING_INFO;
}

PingTime::PingTime(int timeMs) : timeMs_(timeMs)
{

}

int PingTime::toConnectionSpeed() const
{
    if (timeMs_ == NO_PING_INFO)
    {
        return 3;
    }
    else if (timeMs_ == PING_FAILED)
    {
        return 0;
    }
    else if (timeMs_ < LATENCY_STEP1)
    {
        return 3;
    }
    else if (timeMs_ < LATENCY_STEP2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

} //namespace locationsmodel
