#ifndef SUBEVENT_COMMON_HPP
#define SUBEVENT_COMMON_HPP

#include <subevent/std.hpp>
#include <subevent/event.hpp>

SEV_NS_BEGIN

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

namespace CommEventId
{
    static const Event::Id Timer = 70001;
    static const Event::Id Stop = 70002;
    static const Event::Id Task = 70003;
    static const Event::Id ChildFinished = 70004;
}

SEV_NS_END

#endif // SUBEVENT_COMMON_HPP