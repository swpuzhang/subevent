#include <iostream>

#include <subevent/subevent.hpp>

SEV_USING_NS

//---------------------------------------------------------------------------//
// Main
//---------------------------------------------------------------------------//

SEV_IMPL_GLOBAL

int main(int, char**)
{
    NetApplication app;

    IpEndPoint local(9001);

    UdpReceiverPtr receiver = UdpReceiver::newInstance(&app);

    receiver->getSocketOption().setReuseAddress(true);

    // open
    receiver->open(local, [&](const UdpReceiverPtr&) {

        for (;;)
        {
            char message[256];
            IpEndPoint sender;

            // receive
            int32_t res = receiver->receive(message, sizeof(message), sender);
            if (res <= 0)
            {
                break;
            }

            std::cout << message << std::endl;
        }
    });

    // app end timer
    Timer timer;
    timer.start(10 * 1000, false, [&](Timer*) {
        app.stop();
    });

    return app.run();
}
